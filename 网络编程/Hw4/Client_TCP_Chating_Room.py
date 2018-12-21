import socket, threading, argparse, time

MAX_BYTES = 1024
BEGIN_SUF = b"!@#BEGIN"     #开头和结尾标志
END_SUF = b"!@#END"

flag = 1    #客户端输入"/exit"后，flag置0，便于读服务器的线程得知可以退出while循环

#接受输入模块
def readKeyboard(sock):
    global flag
    while True:
        text = input()
        data = text.encode('utf-8')
        sock.sendall(BEGIN_SUF + data + END_SUF)
        if text == "/exit":
            break
    flag = 0

#等待服务器信息模块
def readServer(MAX_BYTES, sock):
	data = b""
	while flag:
		data += sock.recv(MAX_BYTES) 
		if END_SUF in data:
			t_data = data.split(END_SUF)
			for i in range(len(t_data)-1):
				text = t_data[i].split(BEGIN_SUF)[1].decode('utf-8')
				print(text)
			data = t_data[len(t_data)-1]

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='File transfer client')
    parser.add_argument('host', help='IP or hostname')
    parser.add_argument('-p', metavar='port', type=int, default=1060,
                        help='TCP port (default 1060)')
    args = parser.parse_args()
    address = (args.host, args.p)
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect(address)
    print("---------------Guide-----------------\nAvailable command:\n/register YOUR_USERNAME YOUR_PASSWORD\n/login YOUR_USERNAME YOUR_PASSWORD\n/tell USERNAME :YOUR_WORDS\n/exit\n-------------------------------------\n")

    th1 = threading.Thread(target=readKeyboard, args=(sock,))		#创建两个线程，分别制定线程的函数
    th2 = threading.Thread(target=readServer, args=(MAX_BYTES,sock,))

    th1.start() # 线程启动
    th2.start() 

    th1.join()  #等待结束
    th2.join()

    sock.close()
