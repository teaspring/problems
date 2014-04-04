/*
 * rotate list to right by k places, where k >= 0
 *
 * test case:
 * 1->2->3->4->5
 * k = 2,  return  4->5->1->2->3
 * k = 11, return  5->1->2->3->4              
 * */
import java.io.*;
import java.util.*;

public class rotateList{
    class ListNode{
        int val;
        ListNode next;
        ListNode(int x){
            val = x;
            next = null;
        }
    }

    public ListNode rotateRight(ListNode head, int k){
        if(head == null || k==0)    return head;
        ListNode curr = head;
        int n = 1;
        while(curr.next != null){   // 1st traverse to get length of SLL
            curr = curr.next;
            ++n;
        }
        curr.next = head;        // enable loop
        int l = n - (k % n);    // in case k > n

        while(l>0){             // 2nd traverse
            curr = curr.next;
            --l;
        }
        ListNode h = curr.next;
        curr.next = null;
        return h;
    }

    public static void main(String[] args){
        return;
    }
}
