# simple_markup.py
# $ python simple_markup.py < [in txt] > [out html]
# requirements:
# 1. handle different kinds of block: heading, title, paragraph, table, emphasized and hyperlink
# 2. firstly out HTML, support other mark language(super class)

import sys, re
from util import *   # util is our local module

print '<html><head><title>...</title><body>'

title = True
for block in util.blocks(sys.stdin):   # stdin
    block = re.sub(r'\*(.+?)\*', r'<em>\1</em>', block)  # emphasize words between *,*
    if title:
        print '<h1>'
        print block
        print '</h1>'
        title = False
    else:
        print '<p>'
        print block
        print '</p>'
print '</body></html>'
