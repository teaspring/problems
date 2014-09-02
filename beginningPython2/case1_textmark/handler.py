#handler.py

from rules import *

class Handler(Rule):    # sub class of Rule, Rule.condition() and action()
    """
    handle obj from Parser.
    1. each block needs its own head-end wrap of html mark,  define start() and end()
    2. suitable name can be parameter. sub() works in re.sub()
    """
    def callback(self, prefix, name, *args):   # variable arguments
        method = getattr(self, prefix+name, None)  # getattr(x, y)  -> x.y if it exist
        if callable(method): return method(*args)

    def start(self, name):
        self.callback('start_', name)

    def end(self, name):
        self.callback('end_', name)

    def sub(self, name):
        def substitution(match):
            result = self.callback('sub_', name, match)  # name is external variable, closure ?!
            if result is None: match.group(0)
            return result
        return substitution

class HTMLRenderer(Handler):
    """
    render HTML. all of its methods can be accessed by super
    start(), end() and sub(), rendering basic marks of HTML
    """
    def start_document(self):
        print '<html><head><title>...</title></head><body>'   # <title> is for tab in browser

    def end_document(self):
        print '</body></html>'

    def start_paragrapgh(self):
        print '<p>'

    def end_paragrapgh(self):
        print '</p>'

    def start_heading(self):
        print '<h2>'

    def end_heading(self):
        print '</h2>'

    def start_list(self):
        print '<ul>'

    def end_list(self):
        print '</ul>'

    def start_listitem(self):
        print '<li>'

    def end_listitem(self):
        print '</li>'

    def start_title(self):
        print '<h1>'

    def end_title(self):
        print '</h1>'

    def sub_emphasis(self, match):
        return '<em>%s</em>' % match.group(1)

    def sub_url(self, match):
        return '<a href="%s">%s</a>' % (match.group(1), match.group(1))

    def sub_mail(self, match):
        return '<a href="mailto:%s">%s</a>' % (match.group(1), match.group(1))

    def feed(self, data):
        print data
