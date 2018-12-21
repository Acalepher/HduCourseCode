import argparse, socket, time

PATH_TAIL  = b'!@#TAIL'     #加入!@# $%^ &*(这些字符以便于将标志和正常文件内容进行区分

FILE_BEGIN = b'$%^BEGIN'
FILE_TAIL  = b'$%^TAIL'

REPLY_BEGIN = b'&*(BEGIN'
REPLY_TAIL  = b'&*(TAIL'


def parse_command_line(description):    #命令语法相关信息的设定
    parser = argparse.ArgumentParser(description=description)
    parser.add_argument('host', help='IP or hostname')
    parser.add_argument('-p', metavar='port', type=int, default=1060,
                        help='TCP port (default 1060)')
    args = parser.parse_args()
    address = (args.host, args.p)   #从命令中获取地址
    return address

def create_srv_socket(address): #创建服务端监听套接字
    listener = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    listener.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    listener.bind(address)
    listener.listen(64)
    print('Listening at {}'.format(address))
    return listener


def accept_connections_forever(listener):   #循环接收连接
    while True:
        sock, address = listener.accept()
        print('Accepted connection from {}'.format(address))
        handle_conversation(sock, address)


def handle_conversation(sock, address): #处理会话
    try:
        while True:
            path = recv_until(sock, PATH_TAIL)
            handle_request(sock, path)
    except EOFError:
        print('Client socket to {} has closed'.format(address))
    except Exception as e:
        print('Client {} error: {}'.format(address, e))
    finally:
        sock.close()


def handle_request(sock, path): #向套接字发送路径所描述的文件
    try:
        file = open(path, 'rb') #二进制读，便于直接发送
        sock.sendall(FILE_BEGIN)   #发送文件开始标志
        while 1:
            line = file.readline()
            if not line:
                break
            sock.sendall(line)
        sock.sendall(FILE_TAIL)    #发送文件结束标志
        file.close()
    except IOError:
        reply = REPLY_BEGIN + b'File doesn\'t exist.\n'+REPLY_TAIL #reply：提示开始标志+提示文本+提示结束标志
        sock.sendall(reply)

def recv_until(sock, suffix):   #获取路径，直到路径结束标志出现
    message = sock.recv(4096)
    if not message:
        raise EOFError('socket closed')
    while suffix not in message:
        data = sock.recv(4096)
        if not data:
            raise IOError('received {!r} then socket closed'.format(message))
        message += data
    message = message.split(suffix)[0]
    return message.decode('gbk')


