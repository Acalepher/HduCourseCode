#encoding: utf-8
'''
    tcp.py 为服务器端
    tcp_user.py 为客户端
    用法：
    接收服务器数据：s.recv( 1024 )
    向服务器发数据：s.send( content )
'''
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)       # 创建一个基于TCP连接的Socket对象
s.connect(('127.0.0.1',9999))               # 连接到指定地址和端口，参数是tuple类型

print(s.recv(1024))
for data in ['li','bo','ca']:
    s.send(data.encode())           # 向服务器发送数据
    print(s.recv(1024))             # 每次最多接收1024b(1kb)
s.send('exit'.encode())
s.close()                           # 关闭连接