# final py file to combine all classes to generate
from colordescriptor import ColorDescriptor
from searcher import Searcher
import argparse
import cv2

# parse argument via argument parser
ap = argparse.ArgumentParser()
ap.add_argument("-d", "--index", required = True,
    help = "Path to where the computed index will be stored")
ap.add_argument("-q", "--query", required = True,
    help = "Path to the query image")
ap.add_argument("-r", "--result-path", required = True,
    help = "Path to the indexed source images")
args = vars(ap.parse_args())
# HSV: 8 bins for hue, 12 bins for saturation, 3 bins for values(brightness)
cd = ColorDescriptor((8, 12, 3))

# load the query image and describe it
query = cv2.imread(args["query"])
features = cd.describe(query)

# perform the search
searcher = Searcher(args["index"])
results = searcher.search(features)

# display the query
cv2.imshow("Query", query)

# loop over the results
for (score, resultID) in results:
    # load the result image and display it
    result = cv2.imread(args["result_path"] + "/" + resultID)
    cv2.imshow("Result", result)
    cv2.waitKey(0)
