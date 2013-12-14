/*
 * implemente double linked list with only one pointer in node. 
 * solution: the internal pointer makes use XOR of pointers(int) of previous Node and next Node. with cast between void* and int 
 *
 * Mar 2013
 */

#include "stdio.h"
#include <iostream>
#include <cstring>
#include <string>
using  namespace std;

struct SideNode{
public:
    SideNode(const char* name, int val):Value(val), ownKey(0){
        size_t n = strlen(name);
        Name = new char[n+1];
        memset(Name, 0, sizeof(char)*(n+1));
        strcpy(Name, name);
        Name[n] = '\0';
    }
    char* Name;
    int Value;
    int ownKey;                // void* ^ void*
};

class SideLink{
public:
    SideLink():
        head(0), tail(0){};
    ~SideLink();
    SideNode* Next(SideNode* curr, SideNode* pre);
    
    void insertTail(const char*, int);
    void deleteNode(int);
    int* getVal(const char*);
    void displayLink();                //just for test, unnecessary
private:
    SideNode* head;
    SideNode* tail;
};

SideLink::~SideLink(){
    if(this->head == 0)
      return;
    SideNode* curr = this->head;
    SideNode* next = Next(curr, 0);
    while(next != 0){
        SideNode* nextPost = Next(next, curr);
        delete curr;
        curr = next;
        next = nextPost;
    }
    delete curr;
    curr=0;
    this->head = 0;
    this->tail = 0;
}

inline SideNode* SideLink::Next(SideNode* curr, SideNode* pre){
    return (SideNode*)(curr->ownKey ^ (int)pre);                // b=a^c, b^c = a, b^a = c
}

void SideLink::insertTail(const char* name, int val){
    SideNode* nNode = new SideNode(name, val);
    if(this->head == 0){
        this->head = nNode;
        this->head->ownKey = 0;                //0^0
        this->tail = this->head;
        return;
    }else{                    //current this->tail->ownKey is preNode->onwKey xor 0
        this->tail->ownKey = (this->tail->ownKey ^ (int)nNode);            //now the tail->ownKey is pre^0
        nNode->ownKey = (int)this->tail;            // actually it is tail ^ 0
        this->tail = nNode;
    }
    nNode=0;
    return;
}

void SideLink::deleteNode(int val){
    if(this->head == 0)
      return;
    SideNode* pre = 0;
    SideNode* curr = this->head;
    SideNode* next = Next(curr, 0);
    if(curr->Value == val){
        next->ownKey ^= (int)curr;    //a^c^a
        this->head = next;                
        delete curr;
        curr=0;
        return;
    }

    while(next != 0){
        SideNode* nextPost = Next(next, curr);    //because 2nd next remains in curr and next->ownKey 
        if(curr->Value == val){                //similar to operation of single linked list, when delete node, the prev and next should be got
            int tmp = pre->ownKey;            //more complicated, the node following next must be got to set to next    
            tmp ^= (int)curr;               //a^b^b = a
            tmp ^= (int)next;
            pre->ownKey = tmp;

            tmp = next->ownKey;
            tmp ^= (int)curr;
            tmp ^= (int)pre;
            next->ownKey = tmp;
            tmp=0;
            delete curr;
            curr=0;
            return;
        }else{
            pre = curr;
            curr = next;
            next = nextPost;
        }
    }
    if(curr->Value == val){                 // tail
        this->tail = pre;
        delete curr;
        curr=0;
    }
    return;
}

int* SideLink::getVal(const char* name){
    if(this->head == 0)
        return 0;
    SideNode* curr = this->head;
    SideNode* next = Next(curr, 0);
    while(next != 0){        
        if(strcmp(curr->Name,name)==0){
            break;
        }else{
            SideNode* nextPost = Next(next, curr);
            curr = next;
            next = nextPost;
        }
    }
    
    int* el = new int(0);
    if(strcmp(curr->Name,name)==0){
        *el = curr->Value;
        curr=0;
        next=0;
        return el;
    }else{
        curr=0;
        next=0;
        return 0;
    }
}

void SideLink::displayLink(){
    if(this->head == 0){
        cout<<"SideLink is NULL"<<endl;
        return;
    }
    SideNode* curr = this->head;
    SideNode* next = Next(curr, 0);
    while(next != 0){
        cout<<"SideNode-- Name:"<<curr->Name<< ", Value: "<<curr->Value<<endl; 
        SideNode* nextPost = Next(next, curr);
        curr = next;
        next = nextPost;
    }
    cout<<"SideNode-- Name:"<<curr->Name<< ", Value: "<<curr->Value<<endl;
    return;
}

int main(int argc, char* argv[]){
    SideLink* pSLink = new SideLink();
    pSLink->insertTail("tom", 1);
    pSLink->insertTail("jerry", 2);
    pSLink->insertTail("thomas", 3);
    pSLink->displayLink();
    
    pSLink->deleteNode(1);
    pSLink->displayLink();
    
    delete pSLink;
    pSLink = 0;
    return 0;
}
