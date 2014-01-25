/*
 * given a SLL, remove the Nth node from the end
 *
 * test data:
 * 1->2->3, 2
 * 1->2, 1
 * 1->2, 2
 * 2, 1
 * */
import java.io.*;
import java.util.*;

public class removeNthFromEnd{
    public class ListNode{
        int val;
        ListNode next;
        ListNode(int x){
            val = x;
            next = null;
        }
    }
    public ListNode removeNth2End(ListNode head, int n){
        if(head==null)    return null;
        if(n==1){
            ListNode prev = null, l=head;
            while(l.next != null){
                prev = l;
                l = l.next;
            }
            if(prev != null)    prev.next = null;
            return prev==null ? null : head;
        }
        
        ListNode p1 = head;
        for(int i=1;i<n && p1 != null; i++){
            p1 = p1.next;
        }
        if(p1==null)    return null;
        ListNode p2 = head, cprev = null;
        while(p1.next != null){
            cprev = p2;
            p2 = p2.next;
            p1 = p1.next;
        }
        ListNode h = head;
        if(cprev != null)    cprev.next = p2.next;
        else                 h = p2.next;
        p2.next = null;
        return h;
    }

    public static void main(String[] args){
        
    }
}
