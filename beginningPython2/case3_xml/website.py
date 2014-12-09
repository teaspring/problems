from xml.sax.handler import ContentHandler
from xml.sax import parse
import os

# xml.sax.handler.ContentHandler is main callback interface of SAX

class Dispatcher:  # mix-in class, inherited by WebsiteConstructor with ContentHandler
    
    def dispatch(self, prefix, name, attrs=None):
        mname = prefix + name.capitalize()       # prefix is start/end, name is Head/Page...
        dname = 'default' + prefix.capitalize()  # like defaultStart, defaultEnd
        method = getattr(self, mname, None)      # self.<mname>
        if callable(method): args = ()     # tuple
        else:
            method = getattr(self, dname, None)
            args = name,    # ',' makes it tuple
        if prefix == 'start': args += attrs,
        if callable(method) : method(*args)

    def startElement(self, name, attrs):  # override ContentHandler.startElement
        self.dispatch('start', name, attrs)

    def endElement(self, name):
        self.dispatch('end', name)

class WebsiteConstructor(Dispatcher, ContentHandler):

    passthrough = False

    def __init__(self, directory):  # root dir of all created files and dir
        self.directory = [directory]
        self.ensureDirectory()

    def ensureDirectory(self):
        path = os.path.join(*self.directory)
        if not os.path.isdir(path): os.makedirs(path)

    def characters(self, chars):
        if self.passthrough: self.out.write(chars)

    def defaultStart(self, name, attrs):
        if self.passthrough:
            self.out.write('<' + name)
            for key, val in attrs.items():
                self.out.write(' %s="%s"' % (key, val))
            self.out.write('>')

    def defaultEnd(self, name):
        if self.passthrough:
            self.out.write('</%s>' % name)

    def startDirectory(self, attrs):
        self.directory.append(attrs['name'])
        self.ensureDirectory()

    def endDirectory(self):
        self.directory.pop()

    def startPage(self, attrs):
        filename = os.path.join(*self.directory + [attrs['name'] + '.html'])
        self.out = open(filename, 'w')
        self.writeHeader(attrs['title'])
        self.passthrough = True

    def endPage(self):
        self.passthrough = False
        self.writeFooter()
        self.out.close()

    def writeHeader(self, title):
        self.out.write('<html>\n <head>\n  <title>')
        self.out.write('title')
        self.out.write('</title>\n </head>\n  <body>\n')

    def writeFooter(self):
        self.out.write('\n </body>\n</html>\n')

parse('website.xml', WebsiteConstructor('public_html'))
