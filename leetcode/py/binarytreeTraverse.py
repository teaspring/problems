# !/usr/bin/env/ python

# given a binary tree, return the zigzag level order traversal of its nodes' values
# ie, from left to righ, then right to left for the next level and alternate between

import sys, unittest

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class TreeTraverse:
    # traverse binary tree in zigzag level order
    # --->
    # <---
    # --->
    # <---
    def zigzagLevelOrder(self, root):
        res = []
        if root is None:
            return res
        stks = [[], []]
        isl2r, i = True, 0;
        stks[i].append(root);
        while(len(stks[i]) != 0):
            level = []
            while(len(stks[i]) != 0):
                rt = stks[i].pop()    # [-1]
                if isl2r is True:
                    if rt.left is not None:
                        stks[1-i].append(rt.left)
                    if rt.right is not None:
                        stks[1-i].append(rt.right)
                else:
                    if rt.right is not None:
                        stks[1-i].append(rt.right)
                    if rt.left is not None:
                        stks[1-i].append(rt.left)
                level.append(rt.val)
            if len(level) != 0:
                res.append(level)
            isl2r, i = not isl2r, 1-i
        return res

    # traverse binary tree in primary level order
    # --->
    # --->
    # --->
    def levelOrder(self, root):
        res = []
        if root is None:
            return res
        twists, i = [[], []], 0
        twists[i].append(root)
        while len(twists[i]) != 0:
            level = []
            for node in twists[i]:
                if node.left is not None:
                    twists[1-i].append(node.left)
                if node.right is not None:
                    twists[1-i].append(node.right)
                level.append(node.val)
            res.append(level)
            while len(twists[i]) > 0:
                twists[i].pop()
            i = 1-i
        return res

    # convert sorted array(list in Python) to binary tree
    # @param A, a list of int value
    # @param end, exclusive index
    def initTree(self, A, start, end):
        if start >= end:
            return None
        mid = start + (end - start)/2
        curr = TreeNode(A[mid])
        curr.left  = self.initTree(A, start, mid)
        curr.right = self.initTree(A, mid+1, end)
        return curr

    # for preorder traverse of binary tree
    def preorder(self, root):
        if root is None:
            return
        print root.val,
        self.preorder(root.left)
        self.preorder(root.right)

    def inorder(self, root):
        if root is None:
            return
        self.inorder(root.left)
        print root.val,
        self.inorder(root.right)
    
    def postorder(self, root):
        if root is None:
            return
        self.postorder(root.left)
        self.postorder(root.right)
        print root.val,

def test_init():
    A = range(16)
    b = TreeNode()
    root = b.initTree(A, 0, len(A))
    b.preorder(root)
    print
    b.inorder(root)
    print
    b.postorder(root)
    print

def test_zigzag():
    A = range(15)
    b = TreeTraverse()
    root = b.initTree(A, 0, len(A))
    matrix = b.zigzagLevelOrder(root)
    for level in matrix:
        print level
    matrix = b.levelOrder(root)
    for level in matrix:
        print level


class TestZigzagLevel(unittest.TestCase):
    def test_01(self):
        s = TreeNode()
        

if __name__ == '__main__':
    test_zigzag()
    # unittest.main()
