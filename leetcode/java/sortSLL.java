/*
 * sort Single Linked List in time O(nlgn) and space O(1)
 * option 1. merge sort;
 * option 2. insertion sort
 * */
import java.io.*;
import java.util.*;

public class sortSLL{
    public class ListNode{
        int val;
        ListNode next;
        ListNode(int x){
            val = x;
            next = null;
        }
    }

    /*
     * merge sort 
     * */
    public ListNode mergesort(ListNode head){
        int n = 0;
        ListNode prev = new ListNode(0);    //the one to link real head
        prev.next = head;
        ListNode curr = prev.next;
        while(curr != null){
            curr = curr.next;
            ++n;
        }
        ListNode h1=null, h2=null;
        for(int len=1;len<n;len *= 2){
            ListNode h = null;
            curr = prev;
            while(curr.next != null){
                h1 = curr.next;
                h2 = ruler(h1, len);
                h = ruler(h2, len);
                h1 = merge(h1, h2, curr);    //h1 is set to tail of merged h1 + h2
                h1.next = h;
                curr = h1;
            }    
        }
        curr = prev.next;
        prev.next = null;    //cut the link
        return curr;
    }

    private ListNode findtail(ListNode head){
        if(head == null)    return null;
        ListNode h = head;
        while(h.next != null){
            h = h.next;
        }
        return h;
    }

    //append real head to prehead, return real tail
    private ListNode merge(ListNode l1, ListNode l2, ListNode prehead){ //in ascending order
        /// as l1 is cut ahead of l2, l1 never be null
        if(l2 == null){
            prehead.next = l1;
            return findtail(l1);
        }

        if(l1.val < l2.val){
            prehead.next = l1;
            l1 = l1.next;
        }else{
            prehead.next = l2;
            l2 = l2.next;
        }
        ListNode h = prehead.next;
        while(l1 != null || l2 != null){
            if(l2 == null || (l1!=null && l1.val < l2.val)){
                h.next = l1;
                l1 = l1.next;
            }else{
                h.next = l2;
                l2 = l2.next;
            }
            h = h.next;
        }
        return h;
    }

    private ListNode ruler(ListNode head, int len){
        if(head == null)    return null;
        --len;
        while(head.next != null && len>0){
            head = head.next;
            --len;
        }
        ListNode res = head.next;
        head.next = null;
        return res;
    }

    /*
     * insertion sort
     * */
    public ListNode insertionsort(ListNode head){
        if(head==null)    return null;
        ListNode curr = head.next, start = head, cprev = head;
        while(curr != null){
            ListNode t=start, tprev = null;
            while(t != curr && t.val <= curr.val){
                tprev=t;
                t=t.next;
            }
            if(t == curr){
                cprev = curr;
                curr = curr.next;
                continue;
            }
            cprev.next = curr.next;  //insert curr between tprev and t
            if(tprev == null){
                curr.next = t;       //insert curr as new head
                start = curr;
            }else{
                tprev.next = curr;
                curr.next = t;
            }
            curr = cprev.next;
        }
        return start;
    }
    /* unit test case is in ../java_unittest/sortSLL_junit */
}
