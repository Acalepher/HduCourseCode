import socket,threading

MAX_BYTES = 65535
port = 2342


#接受输入模块
def readKeyboard(port):
	while True:
		text = input()
		data = text.encode('utf-8')
		sock.sendto(data, ('127.0.0.1', port))

#等待服务器信息模块
def readServer(MAX_BYTES):
	while True:
		data, address = sock.recvfrom(MAX_BYTES) 
		text = data.decode('utf-8')
		print(text)


sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

print("---------------Guide-----------------\nAvailable command:\nregister YOUR_USERNAME YOUR_PASSWORD\nlogin YOUR_USERNAME YOUR_PASSWORD\njoinchat YOUR_USERNAME\ntell USERNAME :YOUR_WORDS\nexit\n-------------------------------------\n")

th1 = threading.Thread(target=readKeyboard, args=(port,))		#创建两个线程，分别制定线程的函数
th2 = threading.Thread(target=readServer, args=(MAX_BYTES,))

th1.start() # 线程启动
th2.start() 

th1.join()  #等待结束
