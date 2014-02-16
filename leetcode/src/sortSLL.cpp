/*
 * sort a single linked list. among all the sort algorithms, merge and insertion are two options. this file is for merge sort
 * */
#include "../header/preliminary.h"  //class ListNode is defined in preliminary.h

using namespace std;

ListNode* merge(ListNode *l1, ListNode *l2, ListNode* &tail){//sort in ascending order; both valid head and tail have to return after sort
    ListNode *h=0, *head=0;
    if(!l1)    return l2;    //immediately return without traverse, tail remains 0
    if(!l2)    return l1;
    if(l1->val < l2->val){
        h = head = l1;
        l1 = l1->next;
    }else{
        h = head = l2;
        l2 = l2->next;
    }
    while(l1 || l2){
        if(!l2 || (l1 && l1->val < l2->val)){
            h->next = l1;
            l1 = l1->next;
        }else{
            h->next = l2;
            l2 = l2->next;
        }
        h = h->next;
    }
    tail = h;
    return head;
}

ListNode* ruler(ListNode *head, int len){
    if(!head)    return NULL;
    --len;        //if we want to return head->next, len should be reduced separately
    while(head->next != NULL && len>0){
        head = head->next;
        --len;
    }
    ListNode *res = head->next;
    head->next = NULL;        //cut the SLL in ruler of length len
    return res;
}

ListNode* mergesort(ListNode *head){
    int n=0;
    ListNode *h = head;
    while(h){
        h = h->next;
        ++n;
    }
    ListNode *h1=0, *h2=0, *tail=0;
    for(int len=1;len<n;len *= 2){
        ListNode *prev=NULL;
        h=head;
        while(h != NULL){
            h1 = h;
            h2 = ruler(h1, len);
            h = ruler(h2, len);
            h1 = merge(h1, h2, tail);
            if(prev != NULL){
                prev->next = h1;
            }else{
                head = h1;
            }
            if(tail != NULL)    tail->next = h;
            prev = tail;
            tail=0;
        }
    }
    return head;
}

void show_SLL(ListNode *head){
    if(!head){
        printf("NULL\n");
        return;
    }
    printf("%d", head->val);
    head = head->next;
    while(head){
        printf(" -> %d", head->val);
        head = head->next;
    }
    printf("\n");
}

ListNode* createSLL(int* arr, int n){
    ListNode *head=0, *h=0;
    for(int i=0;i<n;++i){
        ListNode *curr = new ListNode(arr[i]);
        if(!h){
            head = h = curr;
        }else{
            h->next = curr;
            h = h->next;
        }
    }
    return head;
}

int main(int, char**){
    string str;
    while(1){
        if(getline(cin, str)==0 || str.empty())    break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        ListNode* head = createSLL(arr, n);
        ListNode* h = mergesort(head);
        show_SLL(h);
    }
    return 0;
}

