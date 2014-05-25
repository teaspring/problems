/*
 * givena two binary trees, write a function to check it they are equal or not. The concept "equal" means they are structually
 * identical and the nodes have the same value.
 * */

import java.io.*;
import java.util.*;

public class sameTree{
    public class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x){ val=x; }
    }
    
    public boolean isSameTree(TreeNode p, TreeNode q){
        if(p==null && q==null)        return true;
        if(p==null || q==null)        return false;
        if(p.val != q.val)            return false;
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }

    public void test_01(){
        TreeNode node1 = new TreeNode(1);
        node1.right = new TreeNode(2);

        TreeNode node2 = new TreeNode(1);
        node2.right = new TreeNode(2);
        System.out.println(isSameTree(node1, node2));
        return;
    }

    public static void main(String[] args){
        sameTree st = new sameTree();
        st.test_01();
        return;
    }
}

