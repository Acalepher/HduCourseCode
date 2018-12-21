#encoding: utf-8
'''
    udp.py UDP服务器
    udp_user.py UDP客户端
    用法：
    接收客户端数据：s.recvfrom(1024)
    向客户端发数据：  s.sendto(content, addr)
'''
import socket
import threading

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)        # 创建一个基于UDP的socket对象
s.bind(('127.0.0.1',9999))      # 绑定地址与端口

def fun(data, addr):
    print('from {},content is {}'.format(addr, data))
    s.sendto('Hi!{}'.format(data).encode(), addr)   # 向客户端返回内容
while True:
    data, addr = s.recvfrom(1024)       #接受客户端发送的内容，创建新线程处理
    t = threading.Thread(target=fun, args=(data,addr))
    t.start()   # 启动线程
