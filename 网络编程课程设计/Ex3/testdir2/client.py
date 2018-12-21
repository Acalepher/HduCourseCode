import argparse, random, socket
import ft

def writefile(sock, message, local_filename):
    try:
        f = open(local_filename,'wb')   #二进制写方式打开文件，若文件不存在则新建，若文件存在则清空
        message = message.split(ft.FILE_BEGIN)[1] #获取第一段数据中文件开始标志之后的数据
        while ft.FILE_TAIL not in message:
            f.write(message)    #写入
            message = sock.recv(1024)
        message = message.split(ft.FILE_TAIL)[0]  ##获取最后一段数据中文件结束标志之前的数据
        f.write(message)    #写入
        f.close()
    except Exception as e:
        print('Client {} error: {}'.format(address, e))
    else:
        return 1

def client(address, remote_filepath, local_filename):
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect(address)
    text = remote_filepath.encode('gbk') + ft.PATH_TAIL #内容为文件路径+路径结尾标志
    sock.sendall(text)

    message = sock.recv(1024)
    while 1:    #接收数据直到出现开始标志
        if ft.FILE_BEGIN in message:    #出现文件开始标志
            if writefile(sock, message, local_filename) == 1:   #若写文件成功
                print("File reception succeeded!\n")
            else:
                print("File reception failed!\n")
            break
        if ft.REPLY_BEGIN in message:   #出现提示开始标志
            reply_encode = message.split(ft.REPLY_BEGIN)[1] #提取编码后的提示数据
            while ft.REPLY_TAIL not in reply_encode:
                message = sock.recv(1024)
                reply_encode += message
            reply_encode =  reply_encode.split(ft.REPLY_TAIL)[0]    #提取提示结束标志之前的数据
            print(reply_encode.decode('gbk'))   #输出解码后的提示
            break
    sock.close()

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='File transfer client')
    parser.add_argument('host', help='IP or hostname')
    parser.add_argument('remotefilepath', help='name of the remote file path you want to download')
    parser.add_argument('localfilename', help='name of the local file you want to save as')
    parser.add_argument('-p', metavar='port', type=int, default=1060,
                        help='TCP port (default 1060)')
    args = parser.parse_args()
    address = (args.host, args.p)
    client(address, args.remotefilepath, args.localfilename)
