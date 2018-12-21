#encoding: utf-8
'''
    udp.py UDP服务器
    udp_user.py UDP客户端
    用法：
    接收服务器数据：s.recv(1024)
    向服务器发数据：  s.sendto(content, addr)
'''
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)        # 创建一个基于UDP的socket对象
s.sendto('hello!'.encode(), ('127.0.0.1',9999))             # 向指定服务器与端口号发送内容
print(s.recv(1024))                                         # 接收服务器返回的内容
s.close()