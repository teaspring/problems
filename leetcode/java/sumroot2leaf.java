/*
 * given a binary tree containing 0-9 only, each root-to-leaf path could present a number,e.g. 1->2->3 which represents the number 123
 * find the total sum of all root-to-leaf numbers
 * */
import java.util.*;
import java.io.*;

public class sumroot2leaf{
    public class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x){val=x;}
    }
    
    public int sumNumbers(TreeNode root){
        if(root == null)    return 0;
        Stack<TreeNode> stk = new Stack<TreeNode>();
        stk.push(root);
        Stack<TreeNode> snums = new Stack<TreeNode>();
        int res=0;
        while(!stk.isEmpty()){
            TreeNode p = stk.pop();
            while(!snums.isEmpty() && snums.peek().left != p && snums.peek().right != p){
                snums.pop();
            }
            snums.push(p);
            if(p.left == null && p.right == null){
                res += sumStackNumber(snums);
                snums.pop();
                continue;
            }
            if(p.right != null)     stk.push(p.right);
            if(p.left != null)      stk.push(p.left);
        }
        return res;
    }

    private int sumStackNumber(Stack<TreeNode> snums){
        int sum=0;
        for(TreeNode t : snums){
            sum *= 10;
            sum += t.val;
        }
        return sum;
    }

    public void test_01(){
        TreeNode p0 = new TreeNode(1);
        TreeNode p1 = new TreeNode(2);
        TreeNode p2 = new TreeNode(3);
        p0.left = p1;
        p0.right = p2;
        System.out.println(sumNumbers(p0));
    }

    public static void main(String[] args){
        sumroot2leaf sr = new sumroot2leaf();
        sr.test_01();
    }
}
