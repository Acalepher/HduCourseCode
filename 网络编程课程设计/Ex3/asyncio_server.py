import asyncio
import ft

class FtServer(asyncio.Protocol):

    def connection_made(self, transport):   #建立连接
        self.transport = transport
        self.address = transport.get_extra_info('peername')
        self.data = b''
        print('Accepted connection from {}'.format(self.address))

    def data_received(self, data):  #接收数据
        self.data += data
        if ft.PATH_TAIL in data:    #若数据中包含路径结尾标志
            path_en = data.split(ft.PATH_TAIL)[0]
            path = path_en.decode('gbk')
            try:
                file = open(path, 'rb') #读文件
                self.transport.write(ft.FILE_BEGIN)   #发送文件开始标志
                while 1:
                    line = file.readline()
                    if not line:    #发送文件直到文件结尾
                        break
                    self.transport.write(line)
                self.transport.write(ft.FILE_TAIL)    #发送文件结束标志
                file.close()
            except IOError:
                reply = ft.REPLY_BEGIN + b'File doesn\'t exist.\n' + ft.REPLY_TAIL #reply：提示开始标志+提示文本+提示结束标志
                self.transport.write(reply) #发送路径错误提示
            self.data = b''

    def connection_lost(self, exc):
        if exc:
            print('Client {} error: {}'.format(self.address, exc))
        elif self.data:
            print('Client {} sent {} but then closed'
                  .format(self.address, self.data))
        else:
            print('Client {} closed socket'.format(self.address))

if __name__ == '__main__':
    address = ft.parse_command_line('asyncio server using callbacks')
    loop = asyncio.get_event_loop()
    coro = loop.create_server(FtServer, *address)
    server = loop.run_until_complete(coro)
    print('Listening at {}'.format(address))
    try:
        loop.run_forever()
    finally:
        server.close()
        loop.close()
