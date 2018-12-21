import ft

if __name__ == '__main__':
    address = ft.parse_command_line('a single-threaded file transfer server')
    listener = ft.create_srv_socket(address)    #创建监听套接字
    ft.accept_connections_forever(listener) #开始连接	