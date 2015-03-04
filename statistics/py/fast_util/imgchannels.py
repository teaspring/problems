import argparse, glob
import cv2

## this script checks basic property of images, e.g. rows,cols, channels

# parse argument
ap = argparse.ArgumentParser()
ap.add_argument("-d", "--directory", required=True,
    help = "path to the image file directory")

args = vars(ap.parse_args())

# use glob to grab the image files in pattern
for lname in glob.glob(args["directory"] + "/*.jpg"):
    sname = lname[lname.rfind('/') + 1 :]
    img = cv2.imread(lname)
    prop = img.shape
    if len(prop) < 3:
        print 'image %s has not 3 chanels %s' % (sname, prop)
