# markup.py
# current version: mark up for html

import sys, re
from handler import *
from util import *
from rules import *

class Parser:    # base class
    """
    read txt via handler, apply rules, and control
    """
    def __init__(self, handler):
        self.handler = handler
        self.rules, self.filters = [], []

    def addRule(self, rule):
        self.rules.append(rule)

    def addFilter(self, pattern, name):
        def filter(block, handler):    # filter is func to execute the substitute
            return re.sub(pattern, handler.sub(name), block)
        self.filters.append(filter)

    def parse(self, file):
        self.handler.start('document')
        for block in blocks(file):   # read file via util.blocks()
            for filter in self.filters:  # why to run all filters without care of result?
                block = filter(block, self.handler)
            for rule in self.rules:
                if rule.condition(block):
                    last = rule.action(block, self.handler)  # return bool to control break
                    if last: break    # break process of current block 
        self.handler.end('document')

# the solution is not perfect in decompose: HTMLRenderer.start_xxx()/sub_xxx() are dependent
# on list/item/utl/email etc. but not added dynamically in main py
class BasicTextParser(Parser):
    """
    inside constructor, add rule and filter
    """
    def __init__(self, handler):  # put specified rule/filter in sub class, good scalability
        Parser.__init__(self, handler)
        self.addRule(ListRule())
        self.addRule(ListItemRule())
        self.addRule(TitleRule())
        self.addRule(HeadingRule())
        self.addRule(ParagraphRule())

        self.addFilter(r'\*(.+?)\*', 'emphasis')
        self.addFilter(r'(http://[\.a-zA-Z0-9/]+)', 'url')
        self.addFilter(r'([\.a-zA-Z0-9]+@[\.a-zA-Z0-9]+)', 'mail')

handler = HTMLRenderer()
parser = BasicTextParser(handler)
parser.parse(sys.stdin)
