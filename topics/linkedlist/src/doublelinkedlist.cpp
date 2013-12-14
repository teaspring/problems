/*
 * ******************* <DataStructureInC++> chapter3 LinkedList
 * doubly linked list(DLL), with head and tail node. Normalized methods:
 *
 * void isEmpty()
 * void addToHead(int)
 * void addToTail(int)
 * int deleteHead()
 * int deleteTail()
 * int deleteNode(int)
 * bool isInList(int)
 * ...
 * */
#include "stdio.h"
#include <iostream>
#include <cstring>

using namespace std;

struct DLNode{
public:
    DLNode(const char* name, int val):
        Value(val),
        Next(0),
        Previous(0){
            size_t n = strlen(name);
            Name = new char[n+1];
            memset(Name, 0, sizeof(char)*(n+1));
            strcpy(Name, name);
            Name[n] = '\0';
        }
    ~DLNode(){
        delete Name;
        Next=0;
        Previous=0;
    }
    char* Name;
    int   Value;
    DLNode* Next;
    DLNode* Previous;
};

class DLList{
public:
    DLList():
        head(0), tail(0){};
    ~DLList();
    bool insertTail(DLNode*);
    
    bool insertTail(const char*, int);
    void deleteNode(const char*);
    int getval(const char*);

private:
    DLNode* head;
    DLNode* tail;
};

DLList::~DLList(){        
    if(this->head == 0){
        return;
    }
    while(this->head->Next){                //delete from head to tail via moving header to next
        this->head->Next->Previous = 0;
        DLNode* temp = this->head;
        this->head = this->head->Next;
        delete temp;
        temp=0;
    }
    delete this->head;
    this->head = 0;
    this->tail = 0;
}

bool DLList::insertTail(DLNode* node){                //besides, insert head is feasible as well  
    if(node == 0){
        return false;
    }
    if(this->head == 0){
        node->Previous = node->Next = 0;
        this->head = this->tail = node;
    }else{
        node->Previous = this->tail;                //set two pointers for interact
        node->Next = 0;
        this->tail->Next = node;
        this->tail = node;
    }
    return true;
}

bool DLList::insertTail(const char* name, int val){
    return insertTail(new DLNode(name, val));
}
void DLList::deleteNode(const char* name){
    DLNode* curr = this->head;
    while(curr != this->tail){                            //iterate except tail
        if(strcmp(curr->Name, name) == 0){                //curr is the one to delete
            curr->Next->Previous = curr->Previous;
            if(curr->Previous == 0){                    //curr is head
                this->head = curr->Next;
            }else{                                        // set next of previous node
                curr->Previous->Next = curr->Next;
            }
            delete curr;
            curr = 0;
        }else{
            curr = curr->Next;
        }
    }

    if(strcmp(curr->Name, name)==0){                    //tail
        curr->Previous->Next = 0;
        this->tail = curr->Previous;
        delete curr;
        curr=0;
    }
    return;
}

int DLList::getval(const char* name){
    DLNode* curr = this->head;
    while(curr != 0){
        if(strcmp(curr->Name, name)==0){
            return curr->Value;
        }else{
            curr = curr->Next;
        }
    }
    curr = 0;
    return 0;                //not found
}

int main(int argc, char* argv[]){
    DLList* pDLList = new DLList();
    pDLList->insertTail("tom", 1);
    pDLList->insertTail("jerry", 2);
    pDLList->insertTail("thomas", 34);
    printf("tom is %d years\n", pDLList->getval("tom"));
    printf("thomas is %d years\n", pDLList->getval("thomas"));
    
    delete pDLList;
    pDLList= 0;
    return 0;
}
