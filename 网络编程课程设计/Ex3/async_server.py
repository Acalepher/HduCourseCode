import select
import ft

def serve(listener):
    socket_list = [listener]
    bytes_received = {} #name:客户套接字 key:其接收到的数据

    while True:
        readable, writable, exceptional = select.select(socket_list, [], socket_list)

        for sock in readable:   #当有套接字需要处理
            if (sock == listener):  #若有新的连接
                client_socket, client_addr = listener.accept()
                print("client accept", client_addr)
                socket_list.append(client_socket)
            else:
                client_socket = sock    #当有数据可接收
                more_data = client_socket.recv(1024)
                if len(more_data)>0:
                    data = bytes_received.pop(client_socket, b'') + more_data
                    if ft.PATH_TAIL in data:
                        path = data.split(ft.PATH_TAIL)[0].decode('gbk')    #获取文件路径
                        ft.handle_request(sock, path)   #读文件并发送
                    else:
                        bytes_received[client_socket] = data
                else:
                    print("client close", client_socket.getpeername())  #getpeername返回所连接的远程socket的地址和端口
                    socket_list.remove(client_socket)
                    client_socket.close()

        for sock in exceptional:
            print("client exception:", sock.getpeername())
            socket_list.remove(sock)
            sock.close()

if __name__ == '__main__':
    address = ft.parse_command_line('low-level async server')
    listener = ft.create_srv_socket(address)
    serve(listener)
