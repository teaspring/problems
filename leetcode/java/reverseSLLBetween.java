/*
 * reverse a SLL from position m to n. Do it in-place and in one-pass.
 * given m,n : 1 <= m <= n <= length of SLL 
 *
 * test data:  0->1->2->3,
 * m=1, n=3
 * m=1, n=4
 * m=3, n=4
 * m=2, n=4
 * m=2, n=3
 * */

import java.io.*;
import java.util.*;

public class reverseSLLBetween{
    private class ListNode{
        int val;
        ListNode next;
        ListNode(int x){
            val = x;
            next = null;
        }
    }
    public ListNode reverseBetween(ListNode head, int m, int n){
        if(m==n)    return head;
        ListNode mPrev=null, mHead=null, cPrev=null, curr=head;
        for(int i=1;curr != null; i++){
            ListNode cNext = curr.next;    //take care of the position/order of these statements
            if(i<=m){
                if(i==m){
                    mPrev = cPrev;
                    mHead = curr;
                }
            }else if(i<=n){
                curr.next = cPrev;  //store curr.next and reverse it  
                if(i==n){
                    if(mPrev != null){
                        mPrev.next = curr;
                    }
                    mHead.next = cNext;
                    break;
                }
            }
            cPrev = curr;    //move forward cPrev and curr in one step
            curr = cNext;
        }
        return m==1 ? curr : head;
    }
    
    private void display(ListNode head){
        System.out.print(head.val);
        head = head.next;
        while(head != null){
            System.out.print("->" + head.val);
            head = head.next;
        }
        System.out.println();
    }
    public void test_01(){
        ListNode p1 = new ListNode(0);
        ListNode p2 = new ListNode(1);
        ListNode p3 = new ListNode(2);
        p1.next = p2;
        p2.next = p3;
        display(p1);
        ListNode nhead = reverseBetween(p1, 1, 2);
        display(nhead);
    }
    public void test_02(){
        ListNode p1 = new ListNode(0);
        ListNode p2 = new ListNode(1);
        ListNode p3 = new ListNode(2);
        p1.next = p2;
        p2.next = p3;
        ListNode nhead = reverseBetween(p1, 1, 3);
        display(nhead);
    }
    public void test_03(){
        ListNode p1 = new ListNode(0);
        ListNode p2 = new ListNode(1);
        ListNode p3 = new ListNode(2);
        p1.next = p2;
        p2.next = p3;
        ListNode nhead = reverseBetween(p1, 2, 3);
        display(nhead);
    }
    public void test_04(){
        ListNode p1 = new ListNode(0);
        ListNode p2 = new ListNode(1);
        ListNode p3 = new ListNode(2);
        ListNode p4 = new ListNode(3);
        p1.next = p2;
        p2.next = p3;
        p3.next = p4;
        ListNode nhead = reverseBetween(p1, 1, 2);
        display(nhead);
    }
    public void test_05(){
        ListNode p1 = new ListNode(0);
        ListNode p2 = new ListNode(1);
        ListNode p3 = new ListNode(2);
        ListNode p4 = new ListNode(3);
        p1.next = p2;
        p2.next = p3;
        p3.next = p4;
        ListNode nhead = reverseBetween(p1, 2, 3);
        display(nhead);
    }

    public static void main(String[] args){
        reverseSLLBetween rb = new reverseSLLBetween();
        rb.test_01();
        rb.test_02();
        rb.test_03();
        rb.test_04();
        rb.test_05();
    }
}
