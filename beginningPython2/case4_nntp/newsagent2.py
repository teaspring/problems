from nntplib import NNTP
from time import strftime, time, localtime
from email import message_from_string
from urllib import urlopen
import textwrap
import re

day = 24 * 60 * 60  # second of one day

def wrap(string, max=70):
    """
    maximize the char width
    """
    return '\n'.join(textwrap(string)) + '\n'

class NewsAgent:
    """
    it can get news from nntp svr and publish to target
    """
    def __init__(self):
        self.sources = []
        self.destinations = []

    def addSource(self, source):
        self.sources.append(source)

    def addDestination(self, dest):
        self.destinations.append(dest)

    def distribute(self):
        """
        get news from all src and publish to all dest
        """
        items = []   # list of list
        for src in self.sources:
            items.extend(src.getItems())
        for dest in self.destinations:
            dest.receiveItems(items)

class NewsItem:
    """
    simple news item including title and body
    """
    def __init__(self, title, body):
        self.title = title
        self.body = body

class NNTPSource:
    """
    get news item from NNTP svr group
    """
    def __init__(self, servername, group, window):
        self.servername = servername
        self.group = group
        self.window = window

    def getItems(self):
        start = localtime(time() - self.window * day)
        date = strftime('%y%m%d', start)
        hour = strftime('%H%M%S', start)

        server = NNTP(self.servername)
        ids = server.newnews(self.group, date, hour)[1]

        for id in ids:
            lines = server.article(id)[3]
            message = message_from_string('\n'.join(lines))
            title = message['subject']
            body = message.get_payload()
            if message.is_multipart():
                body = body[0]
            yield NewsItem(title, body)
        
        server.quit()

class SimpleWebSource:
    """
    news src which get news item from web page with regular expre
    """
    def __init__(self, url, titlePattern, bodyPattern):
        self.url = url
        self.titlePattern = re.compile(titlePattern)
        self.bodyPattern = re.compile(bodyPattern)

    def getItems(self):
        text = urlopen(self.url).read()
        titles = self.titlePattern.findall(text)
        bodies = self.bodyPattern.findall(text)
        for title, body in zip(titles, bodies):
            yield NewsItem(title, wrap(body))

class PlainDestination:
    """
    format all news items to target of plain text
    """
    def receiveItems(self, items):
        for item in items:
            print item.title
            print '-'*len(item.title)
            print item.body

class HTMLDestination:
    """
    format all news items to target of HTML
    """
    def __init__(self, filename):
        self.filename = filename

    def receiveItems(self, items):
        out = open(self.filename, 'w')
        print >> out, """
        <html>
          <head>
            <title>Today's News</title>
          </head>
          <body>
          <h1>Today's News</h1>
        """

        print >> out, '<ul>'
        id = 0
        for item in items:
            id += 1
            print >> out, ' <li><a href="#%i">%s</a></li>' % (id, item.title)
        print >> out, '</ul>'

        id = 0
        for item in items:
            id += 1
            print >> out, '<h2><a name="%i">%s</a></h2>' % (id, item.title)
            print >> out, '<pre>%s</pre>' % item.body

        print >> out, """
          </body>
        </html>
        """

def runDefaultSetup():
    """
    default setup of src and tgt, can be modified manually
    """
    agent = NewsAgent()

    # SimpleWebSource which get news from BBS news website
    bbc_url = 'http://news.bbc.co.uk/text_only.stm'
    bbc_title = r'(?s)a href="[^"]*">\s*<b>\s*(.*?)\s*</b>'
    bbc_body = r'(?s)</a>\s*<br />\s*(.*?)\s*<'
    bbc = SimpleWebSource(bbc_url, bbc_title, bbc_body)

    agent.addSource(bbc)
        
    # NNTPSource from comp.lang.python.announce
    clpa_server = 'mcadams.posc.mu.edu'  # Insert your real server name
    clpa_group = 'alt.assassination.jfk'
    clpa_window = 1
    clpa = NNTPSource(clpa_server, clpa_group, clpa_window)

    agent.addSource(clpa)

    # add plain text tgt and HTML tgt
    agent.addDestination(PlainDestination())
    agent.addDestination(HTMLDestination('news.html'))

    # publish
    agent.distribute()

if __name__ == '__main__': runDefaultSetup()

