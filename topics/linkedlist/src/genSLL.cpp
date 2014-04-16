/*********************genSLL.cpp*************************/
#include "../genSLL.h"

void genSLL::insertAtTail(int v){
    if(isEmpty()){
        head = new SLLNode(v);
        tail = head;
    }
    else{
        tail->next = new SLLNode(v);
        tail = tail->next;
    }       
}

genSLL::~genSLL(){
    SLLNode* tmp = 0;
    while(tmp != tail){
        head = head->next;
        delete tmp;
        tmp = head;
    }
    delete tmp;
    tmp = tail = head = 0;
}

void genSLL::output(){
    SLLNode* curr = head;
    while(curr->next != 0){
        printf("%d -> ", curr->val);
        curr = curr->next;
    }
    printf("%d\n", curr->val);
}

void linkedListExer::testFindLoopBeginning(SLLNode* head, SLLNode* tail, SLLNode* lBegin ){   
    tail->next = lBegin;
    SLLNode* res0 = findLoopBeginning(head);
    printf("case: find loop beginning: %d\n", res0->val);
}

/*exer 2.4
 * you have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1's digit is at the head of list. write a function to adds the two numders and returns the sum as a linked list
 * exam:
 * input: 3->1->5 + 5->9->2->3
 * output: 8->0->8->3
 * */
void linkedListExer::sllPlus(SLLNode* lhl, SLLNode* rhl, genSLL* pSLL){      //note: here the out para must be a SingleLinkedList object instead of a SLLNode*
    if(lhl == 0 || rhl ==0 || pSLL == 0) return;
    SLLNode* iter1 = lhl;
    SLLNode* iter2 = rhl;
    int unitSum = 0;
   
    while(iter1 != 0 || iter2 != 0){
        if(iter1 != 0)    unitSum += iter1->val;
        if(iter2 != 0)    unitSum += iter2->val;   
        pSLL->insertAtTail(unitSum % 10);
        unitSum = unitSum / 10;       
        iter1 = iter1 != 0 ? iter1->next : 0;
        iter2 = iter2 != 0 ? iter2->next : 0;
    }
}

/*exer 2.3
 * to delete a node in middle of a SLL, given only access to that node
 * input: the node 'c' from the linked list a->b->c->d->e; result: nothing is returned,and the new list becomes a->b->d->e
 * remove by copy
 * note: within this method, the parameter should not be the tail
 * */
void linkedListExer::rmNode(SLLNode* nd){
    if(nd == 0) return;
    SLLNode* toRm = nd->next;
    nd->val = toRm->val;
    nd->next = toRm->next;   
    delete toRm;
    toRm = 0;
}

/* exer2.2
 * to find the nth to last element of a single linked list
 * input: a->b->c->d->e, 2th to last, output: c
 * */
int linkedListExer::findN2Last(SLLNode* head, int n){
    if(head == 0 || n<0) return -1;
    SLLNode* iter = head;
    int steps = 0;
    while(iter->next != 0){
        iter=iter->next;
        steps++;
    }
    if(steps < n)    return -1;

    steps -= n;
    iter = head;
    while(steps-- != 0){
        iter = iter->next;
    }
    return iter->val;
}

/* exer2.1
 * write code to remove duplicates(value) from an unsorted single linked list, without a temporary buffer
 *input: 0->1->2->3->2->4; result: 0->1->2->3->4
 if with buffer, a hashmap can be used to save the iterated values
 without buffer, we have to use another cursor to iterate from head to curr
 * */
void linkedListExer::rmDuplicateVal(SLLNode* head){
    if (head == 0) return;
    SLLNode* iter = head;
    SLLNode* prev= 0;
    while(iter != 0){
        SLLNode* curr = head;
        prev = iter;
        iter = iter->next;
        while(curr != iter){                       
            if(iter->val == curr->val){
                prev->next = iter->next;
                delete iter;
                iter = prev->next;           
                break;
            }
            curr = curr->next;           
        }
    }
}

