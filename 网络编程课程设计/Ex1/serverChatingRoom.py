import socket
MAX_BYTES = 65535
port = 2342

def deal_request(req, address):					#处理请求的函数，根据text的第一个单词来区分命令种类，判断、执行后为reply赋相应值
	v=req.strip().split(' ')
	global reply
	if v[0] == "register" and len(v) == 3:
		if register(v[1],v[2],address)==0:
			reply = "Registration succeeded!\n"
		else:
			reply = "Username existed!\n"
	elif v[0] == "login" and len(v) == 3:
		result = login(v[1],v[2])
		if result == 0:
			reply = "Login completed!\n"
		elif result == 1:
			reply = "Wrong password!\n"
		elif result == 2:
			reply = "Please resgister first!\n"
	elif v[0] == "joinchat" and len(v) == 2:
		if joinchat( v[1], address) == 0 :
			reply = "join succeeded!\n"
		else:
			reply = "Please login first!\n"
	else:
		reply = "Request Error!\n"
	return reply
		
def register(username, password, address):		#注册函数，用户名存在返回1，否则在注册字典中添加用户名：密码键值对
	if username in reg_dic:
		return 1
	else:
		reg_dic[username] = password
		return 0

def login(username, password):					#登陆函数，成功，密码错误，未注册分别返回0，1，2
	if username in reg_dic:
		if reg_dic[username]==password:
			login_user.append(username)
			return 0
		else:
			return 1
	else:
		return 2

def joinchat(username, address):				#开始聊天函数，将用户的地址和用户名加入一个字典，未登录返回1
	if username in login_user:
		addr_name[address] = username
		return 0
	else:
		return 1

def send_reply(reply,address):					#发送应答
	data = reply.encode('utf-8')
	sock.sendto(data, address)

def deliver_chating(username, words):			#分发群聊消息
	for addr in addr_name:
		text = "\033[34m[Public]@"+username+" : \033[0m"+words
		data = text.encode('utf-8')
		sock.sendto(data, addr)

def deliver_priv_msg(username, words, address):	#分发私聊消息
	text = "\033[33m[Private]@"+username+" : \033[0m"+words			#用不同颜色来显示消息属性（公私&发送者）和消息文本来自朱昱凯同学的推销，感觉非常高级，遂学习采用
	data = text.encode('utf-8')
	sock.sendto(data, address)

def getaddrbyname(name):						#通过地址查找用户名
	for addr in addr_name:
		if addr_name[addr] == name:
			return addr
	return 0

if __name__ == "__main__":						#主体内容
	reg_dic={}			#注册信息字典
	login_user=[]		#已登陆用户的列表
	addr_name={}		#包含正在聊天中的用户地址和用户名

	sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
	sock.bind(('127.0.0.1', port))

	while True:									#循环进行
	    data, address = sock.recvfrom(MAX_BYTES)
	    text = data.decode('utf-8')
	    t = text.strip().split(' ')
	    w = text.strip().split(':')
	    if address in addr_name:				#正在聊天的情况
	    	name = addr_name[address]
	    	if text == "exit":						#退出聊天
	    		del addr_name[address]
	    	elif t[0] == "/tell":					#发起私聊请求，用／tell作为私聊请求的敏感词，而不是tell，可以防止将用户的聊天信息误认为私聊请求，因为／tell在一般聊天中出现几率极低，该思路来自于朱昱凯
	    		ad = getaddrbyname(t[1])
	    		if ad == 0:
	    			send_reply("That user is offline",address)
	    		else:
	    			deliver_priv_msg(name, w[1], ad)
	    	else:									#一般的聊天信息
	    		deliver_chating(name, text)
	    		
	    else:									#没有在聊天（也就是发送命令）的情况
	    	reply = ""
	    	send_reply(deal_request(text, address), address)
