/*
 * given a binary tree, check whether it is a mirror of itself(symmetric around its center)
 * e.g
 *        1
 *      /   \
 *     2     2
 *    / \   / \
 *    3 4   4 3    is true
 *
 * test case:
 * 1
 * 1 # 2
 * */
 
import java.io.*;
import java.util.*;

public class symmetricTree{
    public class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x){ val = x; }
    }

    /*
     * solution 2, compare a ArrayList by inorder traverse with null saved in place
     * */
    public boolean isSymmetric_02(TreeNode root){
        if(root == null)    return true;
        ArrayList<String> arr = new ArrayList<String>();
        inorderTraversal(root, arr);

        int i=0, j=arr.size()-1;
        while(i < j){
            if(!arr.get(i).equals(arr.get(j)))        return false;
            ++i;
            --j;
        }
        return true;
    }

    private void inorderTraversal(TreeNode root, List<String> lst){
        if(root == null){
            lst.add("#");
            return;
        }
        if(root.left == null && root.right == null){
            lst.add("" + root.val);    // trick to create a string of int
        }else{
            inorderTraversal(root.left, lst);
            lst.add("" + root.val);
            inorderTraversal(root.right, lst);
        }
        return;
    }

    /*
     * solution 3, elegant recurse!!!
     * */
    public boolean isSymmetric_03(TreeNode root){
        if(root == null)    return true;
        return symmetricChildren(root.left, root.right);
    }

    private boolean symmetricChildren(TreeNode l, TreeNode r){
        if(l==null && r==null)        return true;
        if(l==null || r==null)        return false;
        if(l.val != r.val)            return false;
        return symmetricChildren(l.left, r.right) && symmetricChildren(l.right, r.left);
    }


    public void test_01(){
        TreeNode node1 = new TreeNode(1);
        System.out.println(isSymmetric_02(node1));
        System.out.println(isSymmetric_03(node1));
    }

    public void test_02(){
        TreeNode node1 = new TreeNode(1);
        node1.left = new TreeNode(2);
        System.out.println(isSymmetric_02(node1));
        System.out.println(isSymmetric_03(node1));
    }

    public static void main(String[] args){
        symmetricTree st = new symmetricTree();
        st.test_02(); 
        return;
    }
}
