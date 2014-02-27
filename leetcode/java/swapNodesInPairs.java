/*
 * given a SLL, swap every two adjacent nodes and return its head
 * e.g. 1->2->3->4->5 => 2->1->4->3->5
 *
 * test cases:
 * 1
 * 1->2
 * 1->2->3
 * */
import java.io.*;
import java.util.*;

class ListNode{
    int val;
    ListNode next;
    ListNode(int x){
        val = x;
        next = null;
    }
}

public class swapNodesInPairs{
    public ListNode swapPairs(ListNode head){
        if(head==null || head.next == null)        return head;
        ListNode pre = null, l1 = head, l2 = head.next,
                 post = l2.next, h=l2;
        while(true){
            if(pre != null)        pre.next = l2;    //swap
            l2.next = l1;
            l1.next = post;

            pre = l1;        //move forward
            l1 = post;
            if(l1 == null)    break;
            l2 = l1.next;
            if(l2 == null)    break;
            post = l2.next;
        }
        return h;
    }

    public static void main(String[] args){
        return;
    }
}

