/*
 * from oj.leetcode. 
 * Preorder traverse of binary tree without recurse
 * Postorder
 * Inorder (Morris algorithm)
 * */

import java.io.*;
import java.util.*;

public class traverse{
    public class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x){
            val = x;
        }
    }
    public ArrayList<Integer> preorderTraversal(TreeNode root){
        ArrayList<Integer> res = new ArrayList<Integer>();
        if(root == null)    return res;
        Stack<TreeNode> stk = new Stack<TreeNode>();
        stk.push(root);        //every node will be pushed to stack only once
        while(!stk.isEmpty()){
            TreeNode t = stk.pop();
            res.add(t.val);
            if(t.right != null)     stk.push(t.right);
            if(t.left != null)      stk.push(t.left);
        }
        return res;
    }
    
    /*
     * it is worth to think about postorder iterative traversal carefully
     * */
    public ArrayList<Integer> postorderTraversal(TreeNode root){
        ArrayList<Integer>    res = new ArrayList<Integer>();
        if(root == null)    return res;
        Stack<TreeNode> stk = new Stack<TreeNode>();
        TreeNode p=null, q=root;
        while(q != null){    //when loop starts, root is not pushed to stack initially
            while(q.left != null){
                stk.push(q);                
                q = q.left;
            }
            while(q.right == p || q.right==null){
                res.add(q.val);
                p=q;
                if(stk.isEmpty())    return res;
                q=stk.pop();
            }
            stk.push(q);    //node with left and right child will be pushed to stack twice
            q=q.right;
        }
        return res;
    }

    public void test(){
        TreeNode p0 = new TreeNode(0);
        TreeNode p1 = new TreeNode(3);
        p0.left = p1;
        TreeNode p2 = new TreeNode(-1);
        p0.right = p2;
        TreeNode p3 = new TreeNode(2);
        p1.left = p3;
        TreeNode p4 = new TreeNode(-2);
        p2.right = p4;

        TreeNode p10 = new TreeNode(5);
        TreeNode p11 = new TreeNode(6);
        p10.right = p11;
        ArrayList<Integer> arr = postorderTraversal(p10);
        System.out.println(arr.toString());
    }
    public static void main(String[] args){
        traverse tr = new traverse();
        tr.test();
    }
}


