/*
 * from oj.leetcode. given a SLL: L0->L1->L2->l3...->Ln-1->Ln, reorder it to: L0->Ln->L1->Ln-1->L2...
 * do it in-place without altering nodes' values
 * */

#include "../header/preliminary.h"

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

void showSLL(ListNode *head){
    if(head==NULL)        return;
    printf("%d", head->val);
    ListNode *curr = head->next;
    for(;curr != NULL; curr = curr->next){
        printf(" -> %d", curr->val);
    }
    cout<<endl;
}

ListNode* reverseSLL(ListNode *head){
    if(!head)    return NULL;
    ListNode *curr = head, *cprev = NULL, *cnext = curr->next;
    while(cnext){
        curr->next = cprev;
        cprev = curr;
        curr = cnext;
        cnext = cnext->next;
    }
    curr->next = cprev;
    return curr;
}

void reorderSLL(ListNode *head){
    if(head == NULL)    return;
    ListNode *l1 = head, *l2=head;
    while(l2 && l2->next){ //use slow & quick walker to find the middle node
        l1 = l1->next;
        l2 = l2->next;
        if(l2->next)    l2 = l2->next;
    }
    if(l1==l2)    return;    //length is 1 or 2
    l2 = l1->next;
    l1->next = NULL;
    l2 = reverseSLL(l2);

    ListNode *curr = head;
    l1 = curr->next;
    while(l2 && curr){    //curr is result of last l1
        curr->next = l2;
        curr = l2;
        if(l2)    l2 = l2->next;    //take care of the node move in order
        curr->next = l1;    //l1 is possible to be NULL
        curr = l1;
        if(l1)    l1 = l1->next;
    }
    return;
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
        reorderSLL(head);
        showSLL(head);
    }
    return 0;
}
