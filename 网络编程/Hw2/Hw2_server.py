import socket

MAX_BYTES = 65535
port = 9999

fr=open('dict.txt','r')
dic={}
for line in fr:
	v=line.strip().split('   ')
	dic[v[0]]=v[1]
fr.close()	#从当前目录下读取dict文件，并将每一行由“   ”分隔开的两项作为键值对插入到dic字典中，关闭文件

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)	#创建udp套接字
sock.bind(('127.0.0.1', port))	#连接端口
while True:	#循环接收
    data, address = sock.recvfrom(MAX_BYTES)	#接收数据
    text = data.decode('utf8')	#数据解码
    if text in dic:	#判定该单词是否在字典中，若能查询到返回词义，若不能返回“查询不到”
    	text = '{} : {}'.format(text,dic[text])
    else:
    	text="{} : 查询不到".format(text)
    data = text.encode('utf8')	#对查询结果编码
    sock.sendto(data, address)	#发送
