/*
 * given a binary tree, flatten it to a linked list in-place.
 * e.g 
 *        1           1
 *      /   \          \
 *     2     5     =>   2
 *    / \     \          \
 *   3   4     6          3
 *                         \
 *                          4
 *                           \
 *                            5
 *                             \
 *                              6
 * */

import java.io.*;
import java.util.*;

public class flattenBT2LL{
    public class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }
    
    public void flatten(TreeNode root){
        if(root == null)    return;
        TreeNode curr = null, last = null;
        Stack<TreeNode> stk = new Stack<TreeNode>();
        stk.push(root);
        while(!stk.isEmpty()){
            curr = stk.pop();
            if(curr.right != null)       stk.push(curr.right);
            if(curr.left  != null)       stk.push(curr.left);
            if(last != null){
                last.right = curr;
                last.left = null;
            }
            last = curr;
        }
        return;
    }

    public static void Main(String[] args){
        return;
    }
}
