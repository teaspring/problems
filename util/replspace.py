import os, sys

def replfile(f):
    root,ext = os.path.splitext(f)
    if ext=='.c' or ext=='.cpp' or ext=='.h' or ext=='.py':
        # longname = os.path.join(folder, f)
        os.system('sed -i ' + f + ' -e \'s/\t/    /g\'')


def scandir(folder):
    files=os.listdir(folder)
    for f in files:
        lname = os.path.join(folder, f)
        if os.path.isdir(lname):
            scandir(lname)
        else:
            replfile(lname)

# main function
if len(sys.argv) > 1:
    folder=sys.argv[1]
else:
    folder='./'
scandir(folder)
