#encoding: utf-8
'''
    tcp.py 为服务器端
    tcp_user.py 为客户端
    用法：
    接收客户端数据：sock.recv( 1024 )
    向客户端发数据：sock.send( content )
'''
import socket
import threading

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)       # 创建一个基于TCP(SOCK_STREAM)连接的socket对象，指定使用AF_INET协议（IPv4,AF_INET6为AF_INET6）
s.bind(('127.0.0.1', 9999))         # 绑定地址和端口
s.listen(5)                        # 开始监听端口，参数是挂起连接队列的最大长度。

def fun(sock, addr):
    print('Accept new connection from {}'.format(addr))
    sock.send('Hello!'.encode())
    while True:
        data = sock.recv(1024)
        if data == 'exit' or not data:
            break
        sock.send('hello,{}'.format(data).encode())
    sock.close()
    print('Connection closed {}'.format(addr))

# 服务器程序通过一个永久循环来接受来自客户端的连接，accept()会等待并返回一个客户端的连接。
print('Waiting for connection...')
while True:
    sock, addr = s.accept()     # 一个socket对象 和 请求连接的客户端地址
    t = threading.Thread( target=fun, args=(sock,addr) )    # 创建新线程（或进程）来处理TCP连接，否则，单线程在处理连接的过程中，无法接受其他客户端的连接。
    t.start() # 启动线程
