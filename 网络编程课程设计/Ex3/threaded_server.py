from threading import Thread
import ft

def start_threads(listener, workers=4):	#四个线程接收连接
    t = (listener,)
    for i in range(workers):
        Thread(target=ft.accept_connections_forever, args=t).start()

if __name__ == '__main__':
    address = ft.parse_command_line('a multi-threaded file transfer server')
    listener = ft.create_srv_socket(address)
    start_threads(listener)
