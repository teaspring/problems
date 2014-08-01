/*
 * remove duplicates in a SLL
 *
 * 1->1->2->2->2->3     1->2->3
 * */

#include "../header/preliminary.h"

/*
 * for duplicate nodes, remove them other than one
 * input:  1->1->2
 * output: 1->2
 * */
ListNode* remove(ListNode *head){
    if(!head)    return NULL;
    ListNode *pre = NULL, *curr = head, *post = curr->next;
    while(curr && post){
        if(curr->val == post->val){
            if(!pre){
                head = post;
            }else{
                pre->next = post;
            }
            curr->next = NULL;
            delete curr;
        }else{
            pre = curr;
        }
        curr = post;
        post = curr->next;
    }
    return head;
}

/*
 * given a sorted SLL, remove all the nodes with duplicates
 * input:  1->1->2
 * output: 2
 * */
ListNode* delPart(ListNode *pre, ListNode *start, ListNode *end){
    if(pre)    pre->next = end->next;
    for(ListNode *h = start; h != end;){
        ListNode *after = h->next;
        delete h;
        h = after;
    }
    delete end;
    return pre;
}

ListNode* removeII(ListNode *head){
    if(!head || !(head->next))    return head;
    ListNode *pre = NULL, *curr = head, *post = head->next;
    ListNode *start = NULL, *end = NULL;
    while(curr){
        post = curr->next;
        end  = curr;
        if(!post || curr->val != post->val){
            if(start){
                if(head == start)    head = post;
                pre = delPart(pre, start, end);
                start = NULL;
            }else{
                pre = curr;
            }
        }else{
            if(!start)    start = curr;
        }
        curr = post;
    }
    if(pre)    pre->next = NULL;
    return head;
}

void test_01(){
    int arr[6] = {1,1,1,2,3,3};
    ListNode *head = createSLL(arr, sizeof(arr)/sizeof(int));
    displaySLL(head);
    head = removeII(head);
    displaySLL(head);

    delSLL(head);
    return;
}

int main(){
    return 0;
}
