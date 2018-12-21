import select, socket, argparse

MAX_BYTES = 1024
BEGIN_SUF = b"!@#BEGIN"
END_SUF = b"!@#END"

reg_dic={}          #注册信息字典 Uname:password
sock_name={}        #包含登陆的用户套接字和用户名

def deal_request(req, sock):                 #处理请求的函数，根据text的第一个单词来区分命令种类，判断、执行后为reply赋相应值
    v=req.strip().split(' ')
    if v[0] == "/register" and len(v) == 3:
        if register(v[1],v[2])==0:
            reply = "Registration succeeded!\n"
        else:
            reply = "Username existed!\n"
    elif v[0] == "/login" and len(v) == 3:
        result = login(v[1],v[2], sock)
        if result == 0:
            reply = "Login completed!\n"
        elif result == 1:
            reply = "Wrong password!\n"
        elif result == 2:
            reply = "Please resgister first!\n"
    else:
        reply = "Request Error!\n"
    return reply
        
def register(username, password):      #注册函数，用户名存在返回1，否则在注册字典中添加用户名：密码键值对
    global reg_dic
    if username in reg_dic:
        return 1
    else:
        reg_dic[username] = password
        return 0

def login(username, password, sock):                  #登陆函数，成功，密码错误，未注册分别返回0，1，2
    global sock_name
    if username in reg_dic:
        if reg_dic[username]==password:
            sock_name[sock] = username
            return 0
        else:
            return 1
    else:
        return 2

def deliver_priv_msg(username, words, sock):    #分发私聊消息
    text = "\033[33m[Private]@"+username+" : \033[0m"+words         #用不同颜色来显示消息属性（公私&发送者）和消息文本来自朱昱凯同学的推销，感觉非常高级，遂学习采用
    data = text_to_data(text)
    sock.sendall(data)

def deliver_chating(username, words, sock):           #分发群聊消息
    for sock in sock_name:
        text = "\033[34m[Public]@"+username+" : \033[0m"+words
        data = text_to_data(text)
        sock.sendall(data)

def send_reply(reply,sock):                  #发送应答
    data = text_to_data(reply)
    sock.sendall(data)

def getsockbyname(name):                        #通过名字查找用户套接字
    for sock in sock_name:
        if sock_name[sock] == name:
            return sock
    return 0

def text_to_data(text):
    data = BEGIN_SUF + text.encode('utf-8') + END_SUF
    return data

def serve(listener):
    socket_list = [listener,]
    bytes_received = {}     #sock - b'received data'

    while True:
        readable, writable, exceptional = select.select(socket_list, [], socket_list)

        for sock in readable:
            if (sock == listener):  #监听套接字可读时接收新连接
                client_socket, client_addr = listener.accept()
                print("client accept", client_addr)
                socket_list.append(client_socket)
            else:
                client_socket = sock
                more_data = client_socket.recv(1024)
                if len(more_data)>0:
                    data = bytes_received.pop(client_socket, b'') + more_data
                    if END_SUF in data:     #处理完整数据
                        l_data = data.split(END_SUF)
                        for i in range(len(l_data)-1):  #处理每一条以end_suf结尾的数据
                            text = l_data[i].split(BEGIN_SUF)[1].decode('utf-8')    #解码
                            if text == "/exit":     #处理退出请求
                                send_reply("Disconnected.",client_socket)
                                print("{} disconnected.".format(client_socket.getpeername()))
                                socket_list.remove(client_socket)
                                if client_socket in sock_name:
                                    del sock_name[client_socket]
                                if client_socket in bytes_received:
                                    del bytes_received[client_socket]
                                client_socket.close()
                                break
                            if client_socket in sock_name:                #正在聊天的情况
                                name = sock_name[client_socket]
                                t = text.strip().split(' ')
                                w = text.strip().split(':')
                                if t[0] == "/tell":                   #发起私聊请求，用／tell作为私聊请求的敏感词，而不是tell，可以防止将用户的聊天信息误认为私聊请求，因为／tell在一般聊天中出现几率极低，该思路来自于朱昱凯
                                    sk = getsockbyname(t[1])    #获取私聊发送对象的socket
                                    if sk == 0:
                                        send_reply("That user is offline",client_socket)
                                    else:
                                        deliver_priv_msg(name, w[1], sk)
                                else:                                   #一般的聊天信息
                                    deliver_chating(name, text, client_socket)
                            else:
                                reply = deal_request(text, client_socket)
                                send_reply(reply,client_socket)
                        bytes_received[client_socket] = l_data[len(l_data)-1]
                    else:
                        bytes_received[client_socket] = data
                else:
                    print("client close", client_socket.getpeername())
                    socket_list.remove(client_socket)
                    del sock_name[client_socket]
                    client_socket.close()

        for sock in exceptional:    #处理异常套接字
            print("client exception:", sock.getpeername())
            socket_list.remove(sock)
            if sock in sock_name:
                del sock_name[client_socket]
            sock.close()

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Chating room server')
    parser.add_argument('host', help='IP or hostname')
    parser.add_argument('-p', metavar='port', type=int, default=1060,
                        help='TCP port (default 1060)')
    args = parser.parse_args()
    address = (args.host, args.p)
    listener = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    listener.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    listener.bind(address)
    listener.listen(64)
    print("Listening at {}".format(address))
    serve(listener)
