/********************genSLL.h************************/
#include "stdio.h"

struct SLLNode{
    SLLNode(int v):val(v), next(0){
    }
    int val;
    SLLNode* next;
};

class genSLL{
public:
    genSLL(): head(0), tail(0){}
    ~genSLL();
    bool isEmpty(){
        return head == 0;
    }
    void insertAtTail(int);
    void output();   
    SLLNode* head;
    SLLNode* tail;
};

class linkedListExer{
public:
    linkedListExer(){}
    ~linkedListExer(){}

    SLLNode* findLoopBeginning(SLLNode*);
    void testFindLoopBeginning(SLLNode* head, SLLNode* tail, SLLNode* loopBegin );

    void sllPlus(SLLNode*, SLLNode*, genSLL*);
    void rmNode(SLLNode*);
    int findN2Last(SLLNode*, int);
    void rmDuplicateVal(SLLNode*);
};

