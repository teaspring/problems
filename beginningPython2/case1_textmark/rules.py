# ruler.py

class Rule:    # base of Handler()
    """
    super class of all rules
    """
    # although all sub class has condition(), they have different logic,
    # so not defined(interface or virtual class) in base class
    def action(self, block, handler):  # all sub class have identical logic, no override mostly
        handler.start(self.type)       # self.type is defined in each sub class
        handler.feed(block)
        handler.end(self.type)
        return True    # used in parse()

class HeadingRule(Rule):
    """
    heading: all in one line, 70 char in maximum, not end with ';'
    """
    type = 'heading'
    def condition(self, block):
        return not '\n' in block and len(block) <= 70 and not block[-1] == ';'

class TitleRule(HeadingRule):
    """
    title: first block of document, and it should be Heading already
    """
    type = 'title'
    first = True
    def condition(self, block):
        if not self.first: return False
        self.first = False
        return HeadingRule.condition(self, block)

class ListItemRule(Rule):
    """
    list item: block begins with '-'. within HTML, the '-' is removed
    """
    type = 'listitem'
    def condition(self, block):
        return block[0] == '-'

    def action(self, block, handler):  # specified action() to wrap with <li></li>, and remove '-' at [0]
        handler.start(self.type)
        handler.feed(block[1:].strip())
        handler.end(self.type)
        return True

class ListRule(ListItemRule):
    """
    list: from one block not list item to last list item.
    """
    type = 'list'
    inside = False

    def condition(self, block):
        return True

    def action(self, block, handler):   # specified action() to wrap with <ul> </ul>
        if not self.inside and ListItemRule.condition(self, block):
            handler.start(self.type)
            self.inside = True
        elif self.inside and not ListItemRule.condition(self, block):
            handler.end(self.type)
            self.inside = False
        return False

class ParagraphRule(Rule):
    """
    paragraph: by default
    """
    type = 'paragraph'
    def condition(self, block):
        return True

