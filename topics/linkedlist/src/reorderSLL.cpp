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
    int listlen = 0;
    ListNode *curr = head;
    while(curr){
        ++listlen;
        curr=curr->next;
    }
    if(listlen==1)    return;
    curr=head;
    for(int halflen=(listlen-1)/2;halflen>0;--halflen){
        curr = curr->next;
    }
    ListNode *l2 = curr->next;
    curr->next = NULL;        //cut in half
    l2 = reverseSLL(l2);
    curr = head;
    ListNode *l1 = curr->next;
    while(l2 && curr){    //merge l1 and l2 one by one, head is from l1
        curr->next = l2;
        curr = curr->next;
        if(l2)
          l2 = l2->next;
        curr->next = l1;    //l1 is possible to be NULL
        curr = curr->next;
        if(l1)
          l1 = l1->next;
    }
    return;
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
        reorderSLL(head);
        showSLL(head);
    }
    return 0;
}
