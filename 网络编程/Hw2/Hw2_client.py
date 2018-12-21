import socket
MAX_BYTES = 65535
port = 9999
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)	#创建客户端socket
text = input()	#接收需要查询的单词
data = text.encode('utf8')	#由于ascii报错，改成了utf8编码
sock.sendto(data, ('127.0.0.1', port))	#向指定端口发送单词查询
data, address = sock.recvfrom(MAX_BYTES)	#接收查询结果的编码
text = data.decode('utf8')	#解码查询结果
print(text)	#当当当 输出查询结果