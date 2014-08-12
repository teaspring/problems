# sort a SLL in time O(nlgn) using space O(1)

import sys, unittest

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def sortList(self, head):
        prev = ListNode(0)
        prev.next = head
        curr = prev.next
        n = 0
        while curr is not None:
            curr = curr.next
            n = n+1
        h1, h2, len = None, None, 1
        while len < n:
            curr, h = prev, None
            while curr.next is not None:
                h1 = curr.next
                h2, t1 = self.ruler(h1, len)    # h1 and t1 are head and tail of this part, h2 is head of following part
                h,  t2 = self.ruler(h2, len)    # h2 and t2 are head and tail of this part, h is head of following part
                h1 = self.merge(h1, t1, h2, t2, curr)   # h1 is tail of this part
                h1.next = h
                curr = h1
            len = len*2
        curr = prev.next
        prev.next = None
        return curr

    def merge(self, l1, t1, l2, t2, prehead):
        if l1 is None:
            prehead.next = l2
            return t2
        if l2 is None:
            prehead.next = l1
            return t1
        if l1.val < l2.val:
            prehead.next = l1
            l1 = l1.next
        else:
            prehead.next = l2
            l2 = l2.next
        h = prehead.next
        while l1 is not None or l2 is not None:
            if l2 is None: 
                h.next = l1
                l1 = l1.next
            elif l1 is not None and l1.val < l2.val:
                h.next = l1
                l1 = l1.next
            else:
                h.next = l2
                l2 = l2.next
            h = h.next
        return h

    def ruler(self, head, len):
        if head is None:
            return None, None
        for i in range(len-1):    # NOTE: length for iteration should be (n-1) now
            if head.next is None:
                break
            head = head.next
        res = head.next
        head.next = None
        return res, head    # head of next part, and tail of this part

def displaySLL(head):
    if head is None:
        return
    else:
        print head.val,
    while head.next is not None:
        head = head.next
        print ' -> %d' % head.val,
    print ''

# Not in need now: from sortList import Solution

def test_out():
    h = ListNode(11)
    t, arr = h, range(11)
    for i in arr:
        t.next = ListNode(arr[-1 - i])
        t = t.next
    s = Solution()
    displaySLL(h)
    t = s.sortList(h)
    displaySLL(t)

class TestSortList(unittest.TestCase):
    def test_sortSLL(self):
        n = 11
        h = ListNode(n)
        t, arr = h, range(n)
        for i in arr:
            t.next = ListNode(arr[-1 - i])
            t = t.next
        s = Solution()
        t = s.sortList(h)

        for i in range(n):
            if t is None or t.next is None:
                break
            self.assertTrue(t.val < t.next.val)
            t = t.next

if __name__ == '__main__':
    # test_out()
    unittest_main()
