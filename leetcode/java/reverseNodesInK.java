/*
 * given a SLL, reverse every k nodes at a time and return is modified head
 * if rest nodes less than k, remain them
 * e.g, 1->2->3->4->5
 * k=2, 2->1->4->3->5
 * k=3, 3->2->1->4->5
 * {1}, k=2, => {1}
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

public class reverseNodesInK{
    private void reverse(ListNode pre, ListNode h, ListNode e, ListNode post){
        if(h==null)        return;
        ListNode l1=h, l2=h.next, after = l2.next;
        while(l2 != post){  //l1->l2->after => l1<-l2  after
            l2.next = l1;
            if(after == null)    break;
            l1 = l2;
            l2 = after;
            after = l2.next;
        }
        if(pre != null)    pre.next = e;
        h.next = post;
        return;
    }

    public ListNode reverseKGroups(ListNode head, int k){
        if(head==null || k<2)    return head;
        ListNode pre = null, h=head, post = null;
        head = null;
        while(h != null){
            ListNode e = h;
            int i=0;
            for(i=1;i<k && e.next != null;++i){
                e = e.next;
            }
            if(i<k)        break;
            post = e.next;
            reverse(pre, h, e, post);
            if(head==null)    head = e;

            pre = h;    //move forward. after reverse, h becomes prev of post
            h=post;
        }
        if(head == null)    return h;
        return head;
    }

    public static void main(String[] args){
        return;
    }
}
