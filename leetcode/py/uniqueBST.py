# given n, generate all structually unique BST's that store values 1...n
# E.g, n=3, your program should return all 5 unique BST
#

import copy

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def build(self, nodes):
        n = len(nodes)
        if n == 0:
            yield None
        for i in range(n):
            root = nodes[i]
            for left in self.build(nodes[:i]):
                for right in self.build(nodes[i+1:]):
                    root.left, root.right = left, right
                    yield root
    
    # @return a list of tree nodes
    def generateTrees(self, n):
        nodes = map(TreeNode, range(1, n+1))
        return map(copy.deepcopy, self.build(nodes))
