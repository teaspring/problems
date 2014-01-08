/*
 * from oj.leetcode. given a SLL, sort it in time O(n*lgn) with constant space structure
 *
 * generally I think about two options: quick sort and merge sort for this problem:
 * 1.quick sort is dependent on swap(), this function will turns too complicated in SLL
 * 2.merge sort is great for linked list, no additional space like for array
 * 
 * test cases:
 * 1,2,3
 * 3,2,1
 * 3,2,4
 * 3,4,2
 * 4,2,3
 * 3,1,4,2
 * */

#include "../header/preliminary.h"

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int v): val(v), next(NULL){}
};

/*
 * solution 1: quick sort
 * because this swap of SLL node includes two nodes and their prev pointers, the edge case of paprev==pb must be considered
 * */
void swap(ListNode *pa, ListNode *paprev, ListNode *pb, ListNode *pbprev){    //assume pa is on right side of pb
    if(pa == pb || pa ==NULL || pb==NULL)    return;
    if(pb == paprev){
        pb->next = pa->next;
        pa->next = pb;
        if(pbprev != NULL){
          pbprev->next = pa;
        }
    }else{
        ListNode *tmp = pa->next;
        pa->next = pb->next;
        pb->next = tmp;
        if(paprev != NULL){
            paprev->next = pb;
        }
        if(pbprev != NULL){
            pbprev->next = pa;
        }
    }
    return;
}

ListNode* quicksort_SLL(ListNode *hprev, ListNode *head, ListNode *end){    //sort in decending recursively
    if(head==NULL)    return NULL;
    if(head==end || head->next == end){        //only one node or no node at all, similar to n<2(n==0 || n==1)
        return hprev == NULL ? head : NULL;        //head is real head of entire SLL when hprev is NULL
    }
    ListNode *p=head, *pprev=hprev, *q=head->next, *qprev=head;        //head is sentinel in this body
    while(q != end){
        if(q->val > head->val){    //q is on right side of p
            pprev = p;
            p = p->next;
            if(q != p){
                swap(q, qprev, p, pprev);
                if(qprev == p){
                    p = pprev->next;
                    q = p->next;
                    qprev = p;
                }else{
                    p = pprev->next;
                    q = qprev->next;    //the two statements must follow swap() strictly
                }
            }
        }
        qprev = q;        //be careful about the node pointer swap
        q = q->next;
    }

    if(p != head){    //p==head means nodes post head are less than head, no need to sort further
        swap(p, pprev, head, hprev);    //p is on right side of head
        if(pprev == head){
            head = hprev==NULL? p : hprev->next;
            p = head->next;
            pprev = head;
        }else{
            head = hprev==NULL ? p : hprev->next;
            p = pprev->next;
        }
        quicksort_SLL(p, p->next, end);    //right half is all nodes greater than head
        return quicksort_SLL(hprev, head, p);    //left half is all nodes less than head
    }else{
        quicksort_SLL(p, p->next, end);
        return hprev==NULL ? head : NULL;
    }
}

ListNode* reverseSLL(ListNode *head){    //reverse SLL and return reversed head
    ListNode *curr = head, *pprev = NULL, *pnext = head->next;
    while(pnext != NULL){
        curr->next = pprev;
        pprev = curr;
        curr = pnext;
        pnext = curr->next;
    }
    curr->next = pprev;
    return curr;
}

ListNode* sortSLL(ListNode *head){
    if(head==NULL)        return NULL;
    head = quicksort_SLL(NULL, head, NULL);
    return reverseSLL(head);
}

/*
 * solution 2: merge sort, due to the character of linked list, this is good for this problem
 * */
ListNode* merge(ListNode *l1, ListNode *l2, ListNode *h){
    ListNode *l = h;
    while(l1 || l2){
        if(!l1){
            l->next = l2;
            l2 = l2->next;    
        }else if(!l2){
            l->next = l1;
            l1 = l1->next;                
        }else if(l1->val < l2->val){
            l->next = l1;
            l1 = l1->next;
        }else{
            l->next = l2;
            l2 = l2->next;
        }
        l = l->next;
    }
    return l;
}

ListNode *merge_02(ListNode *l1, ListNode *l2, ListNode *h){
    ListNode *l = h;
    while(l1 || l2){
        if(!l1 || (l2 && l1->val > l2->val)){
            l->next = l2;
            l2=l2->next;
        }else{
            l->next = l1;
            l1=l1->next;
        }
        l=l->next;
    }
    return l;
}

ListNode *split(ListNode *h, int len){    //cut a segment of SLL of size len from the SLL starting at h 
    for(int i=1;i<len && h!= NULL;i++){
        h = h->next;
    }
    if(!h)        return NULL;
    ListNode *t = h->next;
    h->next = NULL;        //cut the segment at t from the original linked list
    return t;
}

ListNode* sortList(ListNode *head){
    ListNode n(0);
    n.next = head;
    int listlen = 0;
    while(head){
        listlen++;
        head = head->next;
    }
    for(int len=1;len<listlen;len *= 2){
        ListNode *t = n.next, *l1, *l2;
        ListNode *h = &n;
        while(t != NULL){
            l1 = t;
            l2 = split(l1, len);
            t = split(l2, len);
            ListNode *tail = merge_02(l1, l2, h);
            tail->next = t;
            h = tail;
        } 
    }
    return n.next;
}

void showSLL(ListNode *head){
    if(head==NULL)        return;
    printf("%d", head->val);
    ListNode *curr = head->next;
    for(;curr != NULL; curr = curr->next){
        printf(" -> %d", curr->val);
    }
    cout<<endl;
}

int main(int, char**){
    string str;
    while(1){
        cout<<"please input random integers of SLL:"<<endl;
        if(getline(cin, str)==0 || str.empty())
          break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        ListNode *head = NULL, *curr=NULL;
        for(int i=0;i<n;++i){
            ListNode *tmp = new ListNode(arr[i]);
            if(head == NULL){
              head = tmp;
              curr = tmp;
              continue;
            }
            curr->next = tmp;
            curr = tmp;
        }
        showSLL(head);
        ListNode *res = sortList(head);
        showSLL(res);

        delete[] arr;
        arr=0;
    }
    return 0;
}
