# !/usr/bin/env/ python

# given a binary tree, return the zigzag level order traversal of its nodes' values
# ie, from left to righ, then right to left for the next level and alternate between

import sys, unittest

class TreeNode:
    def __init__(self, x, left=None, right=None):
        self.val = x
        self.left = left
        self.right = right

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

    # convert sorted array to binary tree with 'yield'
    def tree(self, A):
        n = len(A)
        if n == 0:
            return None
        i = n/2
        return TreeNode(A[i], self.tree(A[:i]), self.tree(A[i+1:]))

    # convert sorted array to binary tree, C++/Java style
    # @param A, a list of int value
    # @param end, exclusive index
    def tree_02(self, A, start, end):
        if start >= end:
            return None
        mid = start + (end-start)/2
        curr = TreeNode(A[mid])
        curr.left  = self.tree_02(A, start, mid)
        curr.right = self.tree_02(A, mid+1, end)
        return curr

    # for preorder traverse of binary tree
    def preorder_gen(self, root):
        if root:
            yield root.val
            for x in self.preorder_gen(root.left):
                yield x
            for x in self.preorder_gen(root.right):
                yield x

    # with yield, recurse
    def inorder_gen(self, root):
        if root:
            for x in self.inorder_gen(root.left):
                yield x
            yield root.val
            for x in self.inorder_gen(root.right):
                yield x

    # with yield, recurse
    def inorder_iter(self, node):
        stack = []
        while node:
            while node.left:
                stack.append(node)
                node = node.left
            yield node.val
            while not node.right and len(stack) > 0:
                node = stack.pop()
                # try:
                #    node = stack.pop()
                # except IndexError:
                #    return
                yield node.val
            if not node.right and len(stack) == 0:
                return
            node = node.right

    def postorder(self, root):
        if root is None:
            return
        self.postorder(root.left)
        self.postorder(root.right)
        print root.val,

def test_init():
    A = range(16)
    b = TreeTraverse()
    root = b.tree(A)
    for i in b.preorder_gen(root):
        print i,
    print
    for i in b.inorder_gen(root):
        print i,
    print
    for i in b.inorder_iter(root):
        print i,
    print
    b.postorder(root)
    print

def test_zigzag():
    A = range(15)
    b = TreeTraverse()
    root = b.tree(A, 0, len(A))
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
    test_init()
    # unittest.main()
