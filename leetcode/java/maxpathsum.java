/*
 * given a binary tree, find the maximum path sum. the path can start and end at any node in the tree
 * 
 * */
import java.io.*;
import java.util.*;

class TreeNode{
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){val=x;}
}

public class maxpathsum{
    private int ret=0;
    private int max(int a, int b){
        return a>b ? a : b;
    }
    private int DFS(TreeNode root){
        if(root==null)        return 0;
        int maxl = DFS(root.left);
        int maxr = DFS(root.right);
        ret = max(ret, root.val + max(0, maxl) + max(0, maxr));
        return max(0, root.val + max(0, max(maxl, maxr)));
    }
    public int maxSum(TreeNode root){
        ret = root.val;
        DFS(root);
        return ret;
    }
    public void test_01(){
        
    }
    public static void main(String[] args){
        maxpathsum mps = new maxpathsum();
        mps.test_01();
    }
}
