/*
 * from oj.leetcode
 * problem 1: given a SLL, determine if it has a cycle in it wihtout using extra space.
 * note: "without extra space" means constant space, O(1) 
 *
 * problem2: given a SLL, return the start node of cycle if it has cycle
 * test data:
 * {}, {1}, {1,2}
 * */
import java.io.*;
import java.util.*;


public class cycleSLL{
    public class ListNode{
        int val;
        ListNode next;
        ListNode(int x){
            val=x;
            next=null;
        }
    }
    public boolean hasCycle(ListNode head){
        if(head==null)    return false;
        ListNode n1=head, n2=head;
        while(n1 != null && n1.next != null){
            n1=n1.next.next;
            n2=n2.next;
            if(n1==n2)    return true;
        }
        return false;
    }

    public ListNode findCycleStart(ListNode head){
        if(head==null)    return null;
        ListNode n1=head, n2=head;
        while(n1 != null && n1.next != null){
            n1 = n1.next.next;
            n2 = n2.next;
            if(n1==n2)    break;
        }
        if(n1==null || n1.next==null)    return null;
        n1 = head;
        while(n1 != n2){
            n1 = n1.next;
            n2 = n2.next;
        }
        return n1;
    }

    public static void main(String[] args){
        cycleSLL sll = new cycleSLL();
    }
    
}
