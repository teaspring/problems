/*
 * merge k sorted linked lists and return it as one sorted list. Analyze its complexity.
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

public class mergeKSortedList{
    private void merge(ListNode l1, ListNode l2, ListNode prehead){
        if(l1 == null){
            prehead.next = l2;
            return;
        }
        if(l2 == null){
            prehead.next = l1;
            return;
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
            if(l2 == null || (l1 != null && l1.val < l2.val)){
                h.next = l1;
                l1 = l1.next;
            }else{
                h.next = l2;
                l2 = l2.next;
            }
            h = h.next;
        }
        return;
    }

    public ListNode mergeKLists(ArrayList<ListNode> lists){
        int n = lists.size();
        int i=0;
        for(;i<n && lists.get(i) == null;i++);
        if(i==n)    return null;
        ListNode pre = new ListNode(0);
        ListNode l1 = lists.get(i++);
        for(;i<n;++i){
            ListNode l2 = lists.get(i);
            merge(l1, l2, pre);
            l1 = pre.next;
        }
        pre.next=null;
        return l1;
    }

    public void showSLL(ListNode head){
        if(head == null)    return;
        ListNode h = head;
        System.out.print(h.val);
        h = h.next;
        while(h != null){
            System.out.print(" " + h.val);
            h = h.next;
        }
        System.out.println();
        return;
    }

    public void test_01(){
        ListNode l1 = new ListNode(1);
        l1.next = new ListNode(2);
        l1.next.next = new ListNode(2);
        
        ListNode l2 = new ListNode(1);
        l2.next = new ListNode(1);
        l2.next.next = new ListNode(2);
        ArrayList<ListNode> lists = new ArrayList<ListNode>();
        lists.add(l1);
        lists.add(l2);;
        ListNode head = mergeKLists(lists);
        showSLL(head);
    }

    public static void main(String[] args){
        mergeKSortedList ms = new mergeKSortedList();
        ms.test_01();
    }
}
