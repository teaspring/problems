/*
 * from oj.leetcode. given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along
 * the path equals the given sum
 * */

import java.io.*;
import java.util.*;

public class pathsum{
    public class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x){
            val=x;
        }
    }

    public boolean hasPathSum(TreeNode root, int sum){
        if(root==null)    return false;
        sum -= root.val;
        if(root.left != null){
            if(hasPathSum(root.left, sum))    return true;
        }
        if(root.right != null){
            if(hasPathSum(root.right, sum))    return true;
        }
        
        if(root.left==null && root.right==null && sum==0){
            return true;
        }
        return false;
    }
    
    public ArrayList<ArrayList<Integer>> pathsum(TreeNode root, int sum){
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        if(root == null)    return res;
        Stack<Integer>    stk = new Stack<Integer>();
        branchSum(res, stk, sum, root);
        return res;
    }
    
    private void branchSum(ArrayList<ArrayList<Integer>> res, Stack<Integer> stk, int sum, TreeNode par){
        if(par==null)    return;
        stk.push(par.val);
        sum -= par.val;
        if(par.left != null){
            branchSum(res, stk, sum, par.left);
        }
        if(par.right != null){
            branchSum(res, stk, sum, par.right);
        }
        if(par.left == null && par.right == null && sum==0){
            res.add(new ArrayList<Integer>(stk));    //as Stack implements interface Collection<>
        }
        stk.pop();
        return;
    }

    public void test(){
        TreeNode p0 = new TreeNode(1);
        TreeNode p1 = new TreeNode(2);
        p0.left = p1;
        TreeNode p2 = new TreeNode(3);
        p0.right = p2;
        TreeNode p3 = new TreeNode(4);
        p1.left = p3;
        TreeNode p4 = new TreeNode(5);
        p1.right = p4;
        TreeNode p5 = new TreeNode(-1);
        p2.left = p5;
        TreeNode p6 = new TreeNode(3);
        p2.right = p6;
        TreeNode p7 = new TreeNode(-1);
        p4.right = p7;
        int sum = 7;
        
        ArrayList<ArrayList<Integer>>    res = pathsum(p0, sum);
        for(ArrayList<Integer> arr : res){
            System.out.println(arr.toString());
        }
    }

    public static void main(String[] args){
        pathsum ps = new pathsum();
        ps.test();
    }
}

