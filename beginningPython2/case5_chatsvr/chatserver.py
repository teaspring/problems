from asyncore import dispatcher
from asynchat import async_chat
import socket, asyncore, cmd

PORT = 5005
NAME = 'TestChat'

class EndSession(Exception): pass

class CommonHandler:
    # a simple cmd process program similar to cmd.Cmd
    
    def unknown(self, session, cmd):
        session.push('Unknown command: %s\r\n' % cmd)
    
    def handle(self, session, line):
        if not line.strip(): return
        # split cmd string, mostly 2 parts(1+1) in result 
        parts = line.split(' ', 1)  
        cmd = parts[0]
        try: line = parts[1].strip()
        except IndexError: line = ''
        # find the process method
        meth = getattr(self, 'do_'+cmd, None)
        try:
            meth(session, line)
        except TypeError:
            self.unknown(session, line)

class Room(CommandHandler):
    # general svr with 1+ session(client)
    def __init__(self, svr):
        self.server = svr
        self.sessions = []

    def add(self, session):
        self.sessions.append(session)

    def remove(self, session):
        self.sessions.remove(session)

    def broadcast(self, line):
        for s in self.sessions:
            s.push(line)

    def do_logout(self, session, line):
        raise EndSession

class LoginRoom(Room):
    # room for latest connected user
    
    def add(self, session):
        Room.add(session)
        self.broadcast('Welcome to %s\r\n' % self.server.name)
    
    def unknown(self, session):
        session.push('Please log in\nUse "login <nick>"\r\n')

    def do_login(self, session, line):
        name = line.strip()
        if not name:
            session.push('Please enter a name\r\n')
        # ensure this name not login already
        elif name in self.server.users:
            session.push('This name "%s" is taken already.\r\n' % name)
            session.push('Please try another name again.\r\n')
        else:
            session.name = name
            session.enter(self.server.main_room)

class ChatRoom(Room):
    # room for multiple users inter-chat
    
    def add(self, session):
        # tell everybody someone comes in
        self.broadcast(session.name + ' has entered the room.\r\n')
        self.server.users[session.name] = session
        Room.add(self, session)

    def remove(self, session):
        Room.remove(self, session)
        # tell everybody someone leaves
        self.broadcast(session.name + ' has left the room.\r\n')

    def do_say(self, session, line):
        self.broadcast(session.name + ': ' + line + '\r\n')

    def do_look(self, session, line):
        # look at who are in this room right now
        session.push('The following are in this room:\r\n')
        for other in self.sessions:
            session.push(other.name + '\r\n')

    def do_who(self, session, line):
        session.push('the following are logged in:\r\n')
        for name in self.server.users:
            session.push(name + '\r\n')

class LogoutRoom(Room):
    def add(self, session):
        try: del self.server.users[session.name]
        except KeyError: pass

class ChatSession(async_chat):
    def __init__(self, server, sock):
        async_chat.__init__(self, sock)
        self.server = server
        self.set_terminator("\r\n")
        self.data = []
        self.name = None
        self.enter(LoginRoom(server))

    def enter(self, room):
        # remove self from current room, and enter next room
        try: cur = self.room
        except AttributeError: pass
        else: cur.remove(self)
        self.room = room
        room.add(self)

    def collect_incoming_data(self, data):
        self.data.append(data)

    def found_terminator(self):
        line = ''.join(self.data)
        self.data = []
        try: self.room.handle(self, line)
        except EndSession:
            self.handle_close()

    def handle_close(self):
        async_chat.handle_close(self)
        self.enter(LogoutRoom(self.server))

class ChatServer(dispatcher):
    # chat server with 1 room
    def __init__(self, port, name):
        dispatcher.__init__(self)
        self.create_socket(socket.AF_INET, SOCK_STREAM)
        self.set_reuse_addr()
        self.bind(('', port))
        self.listen(5)
        self.name = name
        self.users = {}
        self.main_room = ChatRoom(self)

    def handle_accept(self):
        connm, addr = self.accept()
        ChatSession(self, conn)

if __name__ == '__main__':
    s = ChatServer(PORT, NAME)
    try: asyncore.loop()
    except KeyboardInterrupt: print

