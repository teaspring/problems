# util.py
# import sys, fileinput

def lines(file):
    for line in list(file):
        yield line
    yield '\n'

# generate block seperated by empty line
def blocks(file):
    block = []
    for line in lines(file):
        if line.strip():
            block.append(line)
            if line.strip()[0] == '-':
                yield ''.join(block).strip()
                block=[]
        elif block:
            yield ''.join(block).strip()
            block=[]

# if __name__ == '__main__':
#    for blk in blocks(fileinput.input()):
#        print blk

