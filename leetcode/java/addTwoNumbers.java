/*
 * add two numbers, each is presented in SLL in reverse order. e.g. (2->4->3) + (5->6->4) = 7->0->8
 * test case:
 * 8->9    + 2->3->4->5
 * 1->9->9 + 2->4->3
 *
 * @extend: what about negative value of node?
 * firstly, we can define a format: -15 is presented via list node as (-5) -> (1)
 * we have 2 kinds of cases:
 * 1.both SLL are negative
 * 2.only one if them is negative,
 * */
import java.util.*;
import java.io.*;
import java.lang.Math;

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
        boolean bothNega = false;
        if(l1.val < 0 && l2.val < 0){
            bothNega = true;
            l1.val = -l1.val;
            l2.val = -l2.val;
        }else if(l1.val < 0 || l2.val < 0){
            return addTwo_nega(l1, l2);
        }

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

        if(bothNega){
            head.val = -head.val;
        }
        return head;
    }

    /*
     * one of lists (l1, l2) is negative
     * */
    public ListNode addTwo_nega(ListNode l1, ListNode l2){
        /// compare abs value of list1(l1) and list2(l2)
        /// two kinds of result: one has more decimals than the other, or one has greater value on highest digit
        boolean l1Negative = l1.val < 0;
        if(l1Negative){
            l1.val = -l1.val;
        }else{
            l2.val = -l2.val;
        }

        ListNode h1 = l1, h2 = l2;
        /// use Stack to store digits
        Stack<Integer> stk1 = new Stack<Integer>();
        Stack<Integer> stk2 = new Stack<Integer>();

        /// decide abs(l2) - abs(l1) or opposite
        while(h1 != null || h2 != null){
            if(h1 != null){
                stk1.push(h1.val);
                h1 = h1.next;
            }
            if(h2 != null){
                stk2.push(h2.val);
                h2 = h2.next;
            }
        }

        boolean l2GreaterAbs = false;
        if(stk1.size() < stk2.size()){
            l2GreaterAbs = true;
        }else if(stk1.size() == stk2.size()){
            while(!stk1.isEmpty() && stk1.peek() == stk2.peek()){
                stk1.pop();
                stk2.pop();
            }
            if(stk1.isEmpty())    return new ListNode(0);
            l2GreaterAbs = stk1.peek() < stk2.peek();
        }

        /// calculate the minus arith operation
        ListNode head = null, curr = null;
        h1 = l1;
        h2 = l2;
        int borrow = 0;
        while(l1 != null || l2 != null){
            int x = -borrow;
            if(l2GreaterAbs){
                x += l2.val;
                x -= (l1 == null) ? 0 : l1.val;
            }else{
                x += l1.val;
                x -= (l2 == null) ? 0 : l2.val;
            }

            if(x < 0){
                borrow = 1;
                x += 10;
            }else{
                borrow = 0;
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
        /// finally, borrow should not > 0

        if((l1Negative && !l2GreaterAbs)
        || (!l1Negative && l2GreaterAbs)){
            head.val = -head.val;
        }
        return head;
    }
    /*
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
    */

    /* unit test will be executed in ../java_unittest/addTwoNumbers_unittest/ */
}
