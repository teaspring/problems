/*
 * add two numbers, each is presented in SLL in reverse order. e.g. (2->4->3) + (5->6->4) = 7->0->8
 * test case:
 * 8->9    + 2->3->4->5
 * 1->9->9 + 2->4->3
 *
 * @extend: what about negative value of node? the requisite is define a format to display negative value in list node
 * */
import java.util.*;
import java.io.*;

public class addTwoNumbers{
    public class ListNode{
        int val;
        ListNode next;
        ListNode(int x){
            val = x;
            next = null;
        }
    }
    private ListNode copyList(ListNode head){
        if(head == null)    return null;
        ListNode h = new ListNode(head.val);
        head = head.next;
        for(ListNode curr = h; head != null; head=head.next){
            curr.next = new ListNode(head.val);
            curr = curr.next;
        }
        return h;
    }

    public ListNode addTwo(ListNode l1, ListNode l2){
        if(l1 == null)    return copyList(l2); //return a copy instead of argument directly!
        if(l2 == null)    return copyList(l1);
        int bene = 0;
        ListNode head = null, curr = null;
        while(l1 != null || l2 != null){  //note: while following SLL remains, it cannot break as it needs to create new node
            int x = bene;
            x += (l1 == null) ? 0 : l1.val;
            x += (l2 == null) ? 0 : l2.val;
            if(x > 9){
                bene = 1;
                x = x - 10;
            }else{
                bene = 0;
            }
            if(curr == null){
                head = new ListNode(x);
                curr = head;
            }else{
                curr.next = new ListNode(x);
                curr = curr.next;
            }
            if(l1 != null)    l1 = l1.next;
            if(l2 != null)    l2 = l2.next;
        }
        if(bene != 0)    //remember if finally there is bene exist
            curr.next = new ListNode(bene);
        return head;
    }

    private void display(ListNode head){
        if(head == null){
            System.out.println();
            return;
        }
        System.out.print(head.val);
        head = head.next;
        while(head != null){
            System.out.print(" -> " + head.val);
            head = head.next;
        }
        System.out.println();
    }

    /* unit test will be executed in ../java_unittest/addTwoNumbers_unittest/ */
}
