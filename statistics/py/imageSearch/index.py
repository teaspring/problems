from colordescriptor import ColorDescriptor
import argparse
import glob
import cv2

# construct an argument parser
ap = argparse.ArgumentParser()
ap.add_argument("-d", "--dataset", required=True,
    help = "Path to the directory that contains the images to be indexed")
ap.add_argument("-i", "--index", required=True,
    help = "Path of file where the computed index will be stored")
# vars() return a dict, it can be retrieved as args[dataset]/args[index]
args = vars(ap.parse_args())

# in HSV, 8 bins for hue, 12 bins for saturation, 3 for values(brightness)
cd = ColorDescriptor((8, 12, 3))

# open output index file for writing
output = open(args["index"], "w")

# use glob to grab the image files in path and iterate them
for imagePath in glob.glob(args["dataset"] + "/*.jpg"):
    # extract the image ID(i.e. the unique filename)
    imageID = imagePath[imagePath.rfind('/') + 1 :]
    image = cv2.imread(imagePath)

    features = cd.describe(image)

    # write the features to file
    features = [str(f) for f in features]
    output.write("%s,%s\n" % (imageID, ",".join(features)))

output.close()
