/*
 * ********************<DataStructureInC++> chapter3 LinkedList********************
 * Singly linked list(SLL), with head and tail.
 *
 * Normalized methods as below: 
 * void isEmpty()
 * void addToHead(int)
 * void addToTail(int)
 * int deleteHead()
 * int deleteTail()
 * int deleteNode(int)
 * bool isInList(int)
 *
*/
#include "stdio.h"
#include <iostream>
#include <cstring>

using namespace std;

struct SLNode{
    SLNode(const char* name, int val, SLNode* next=0):
        Value(val),
        Next(next){
            size_t n = strlen(name);
            Name = new char[n+1];
            memset(Name, 0, sizeof(char)*(n+1));
            strcpy(Name, name);
            Name[n] = '\0';
        }
    ~SLNode(){
        delete Name;
        Name = 0;
        Next = 0;
    }
    char* Name;
    int Value;
    SLNode* Next;                        // frontward pointer
};

/*
 * Singly Linked List, with head and tail 
 * */
class SLList{
public:
    SLList():head(0),
        tail(0){    
    };
    ~SLList();
    bool isEmpty(){
        return head==0;
    }
    void addToHead(const char*, int);
    void addToTail(const char*, int);
    int* deleteFromHead();            //return value of deleted node
    int* deleteFromTail();
    void deleteNode(const char*, int);
    bool isInList(const char*, int);

private:
    SLNode* head;
    SLNode* tail;
};

SLList::~SLList(){
    SLNode* tmp = head;
    while(!isEmpty()){
        head = tmp->Next;
        delete tmp;
        tmp = head;
    }
    tmp = 0;
    head = 0;
    tail = 0;
}

void SLList::addToHead(const char* name, int el){    //for SLL, operation around head and tail always have great difference. because
    head = new SLNode(name, el, head);                //only one frontward pointer exists
    if(tail == 0)
        tail = head;
    return;
}

void SLList::addToTail(const char* name, int el){
    SLNode* tmp = new SLNode(name, el, 0);
    if(isEmpty()){
        head = tail = tmp;
    }else{
        tail->Next = tmp;
        tail = tmp;
    }
    tmp = 0;
    return;
}

int* SLList::deleteFromHead(){
    if(isEmpty())
        return 0;
    int* el = new int(head->Value);
    SLNode* tmp = head;    
    if(head == tail){    
        head = 0;
        tail = 0;
    }else{        
        head = head->Next;
    }
    delete tmp;
    tmp=0;
    return el;
}

int* SLList::deleteFromTail(){
    if(isEmpty())
      return 0;
    int* el = new int(tail->Value);
    if(head == tail){
        delete head;
        head = tail = 0;
    }else{
        SLNode* tmp = head;
        for(;tmp->Next != tail;tmp = tmp->Next);            //has to iterate to tail from head, drawback of SLL
        delete tail;
        tail = tmp;
        tail->Next = 0;
        tmp=0;
    }
    return el;
}


void SLList::deleteNode(const char* name, int el){
    if(head != 0){
        SLNode* pre = 0;
        SLNode* curr = head;
        for(;curr != 0 && !(strcmp(curr->Name,name)==0 && curr->Value == el);pre = curr, curr = curr->Next);
        if(curr != 0){
            if(pre !=  0){                    //operation without head or tail involved
                pre->Next = curr->Next;
            }
            if(curr == head)                //head involved, it must be set to next
                head = head->Next;
            if(curr == tail)                //tail is involved, it must bt set to pre
                tail = pre;
            delete curr;
            curr=0;
            pre=0;
        }
    }
    return;
}

bool SLList::isInList(const char* name, int el){
    SLNode* tmp = head;
    for(;tmp != 0 && !(strcmp(tmp->Name,name)==0 && tmp->Value == el);tmp = tmp->Next);
    return tmp != 0;
}

int main(int argc, char* argv[]){
    SLList* pSLList = new SLList();
    pSLList->addToHead("tom", 1);
    pSLList->addToTail("jerry", 2);
    pSLList->addToTail("thomas", 3);
    int* pa = pSLList->deleteFromHead();
    printf("the deleted head value should be tom's,  %d\n", *pa);
    pa = pSLList->deleteFromTail();
    printf("the deleted tail value should be thomas',  %d\n", *pa);
    pSLList->deleteNode("jerry", 2);
    if(pSLList->isEmpty()){
        printf("yes, it is empty now\n");
    }
    delete pSLList;
    pSLList=0;
    return 0;
}
