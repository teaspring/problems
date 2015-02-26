import numpy as np
import csv

class Searcher:
    def __init__(self, indexPath):
        # store our index path
        self.indexPath = indexPath

    def search(self, queryFeatures, limit=10):
        # result as dictionary which key is file ID
        results = {}
        # open the index file for reading
        with open(self.indexPath) as f:
            reader = csv.reader(f)

            # loop over the rows in the index
            for row in reader:
                # parse out the image ID and features, then compute the
                # chi-squared distance between the features in our index and the query feature
                features = [float(x) for x in row[1:]]
                d = self.chi2_distance(features, queryFeatures)
                # dict: key of image ID and value of distance
                results[row[0]] = d
            f.close()
        # sort results in ascending order of distance
        # note the results become key of distance and value of image ID
        results = sorted([(v, k) for (k, v) in results.items()])
        return results[:limit]

    def chi2_distance(self, histA, histB, eps = 1e-10):
        # *** Pearson Chi-Square distance ***
        d = 0.5 * np.sum([((a - b) ** 2) / (a + b + eps)
                for (a,b) in zip(histA, histB)])
        return d
