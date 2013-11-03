import os, sys

if len(sys.argv) > 1:
    folder=sys.argv[1]
else:
    folder='./'
files=os.listdir(folder)
for f in files:
	root,ext = os.path.splitext(f)
	if ext=='.c' or ext=='.cpp' or ext=='.h':
		longname = os.path.join(folder, f)
        os.system('sed -i ' + longname + ' -e \'s/\t/    /g\'')

