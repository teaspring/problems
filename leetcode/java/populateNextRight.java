/*
 * assume each binary tree node has one another pointer to next right node. write a function to connect this pointer of each node in a binary tree.
 *
 * e.g. 
 *    1                 1 -> null
 *   / \              /   \
 *  2   3   ==>      2 ->  3 -> null
 * / \ / \          / \   / \
 *4  5 6  7        4 ->5->6->7 -> null
 * 
 *
 * solution: BFS, traverse every horizontal level once, using two queue to save traversed node. this solution has no dependence on the binary tree shape, either perfect BST or not does not matter.
 * */

import java.io.*;
import java.util.*;
import java.util.LinkedList;
import java.util.Queue;

public class populateNextRight{
    public class TreeLinkNode{
        int val;
        TreeLinkNode left, right, next;
        TreeLinkNode(int x){ val=x; }
    }

    private void pushChildren(TreeLinkNode root, Queue<TreeLinkNode> q){
        if(root == null)    return;
        if(root.left != null){
            q.offer(root.left);
        }
        if(root.right != null){
            q.offer(root.right);
        }
        return;
    }

    public void connect(TreeLinkNode root){
        if(root == null)    return;
        List<Queue<TreeLinkNode>> qArr = new ArrayList<Queue<TreeLinkNode>>();
        for(int i=0; i<2; ++i){
            qArr.add(new LinkedList<TreeLinkNode>());
        }
        int idx = 0;
        qArr.get(idx).offer(root);
        while(!qArr.get(idx).isEmpty()){
            for(TreeLinkNode curr = null, last = null; !qArr.get(idx).isEmpty(); last = curr){
                curr = qArr.get(idx).poll();    // get and remove
                pushChildren(curr, qArr.get(1-idx));
                if(last != null)    last.next = curr;
            }
            idx = 1 - idx;
        }
        return;
    }

    public static void Main(String[] args){
        return;
    }
}

