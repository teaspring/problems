from asyncore import dispatcher
from asynchat import async_chat
import socket, asyncore

PORT = 5005
NAME = 'TestChat'

class ChatSession(async_chat):
    """
    connect session of one user for server
    """
    def __init__(self, sock, svr):
        async_chat.__init__(self, sock)
        self.server = svr
        self.set_terminator("\r\n")    # terminator of conn stream process 
        self.data = []
        # welcome
        self.push('Welcome to %s\r\n' % self.server.name)

    def collect_incoming_data(self, data):
        self.data.append(data)

    def found_terminator(self):
        """
        terminator char means one complete line which can be broadcast to other guests from svr
        """
        line = ''.join(self.data)
        self.data = []
        self.server.broadcast(line, self)

    def handle_close(self):
        async_chat.handle_close(self)
        self.server.disconnect(self)

class ChatServer(dispatcher):
    def __init__(self, port, name):
        # standard setup
        dispatcher.__init__(self)
        self.create_socket(socket.AF_INET, socket.SOCK_STREAM)
        self.set_reuse_addr()
        self.bind(('', port))
        self.listen(5)
        self.name = name
        self.sessions = []

    def disconnect(self, session):
        self.sessions.remove(session)

    # broadcast line to all clients except proposer
    def broadcast(self, line, proposer):
        for s in self.sessions:
            if s != proposer:
                s.push(line + '\r\n')

    def handle_accept(self):
        conn, addr = self.accept()
        self.sessions.append(ChatSession(conn, self))

if __name__ == '__main__':
    s = ChatServer(PORT, NAME)
    try: asyncore.loop()
    except KeyboardInterrupt: print
