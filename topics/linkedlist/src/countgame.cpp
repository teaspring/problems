/*
 * from CSDN student programming challenge competition in Jan 2014, but should be a famous little game
 * given n integers [1,n] to be a circular count in ascending. given int x and int y. start counting at 1 in clockwise, the xth integer is
 * removed. start counting at x-1 in counterclockwise, the yth integer will be removed. continue the game play till there is only one
 * integer in rest. 
 * 
 * perfect structure for this problem is DLL definitely:
 * 1. it needs to remove integer at random position from the structure, so is linked list
 * 2. it will traverse forward and backward repeatedly, so are double pointers(prev and next) in need
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include "stdlib.h"

using namespace std;

struct node{    //node of DLL
    node(int v, node* pp, node* pn):val(v), prev(pp), next(pn){}
    ~node(){
        prev = 0;
        next = 0;
    }
    int getVal(){
        return val;
    }
private:    
    int val;
public:
    node* prev;
    node* next;
};

struct cirDLL{    //circular DLL
    node* head;
    cirDLL():head(0){}
    ~cirDLL();
    void insertAtTail(node*);
    void remove(node*);
};

void cirDLL::insertAtTail(node* pnode){
    if(head==0){
        head = pnode;
        head->prev = head;
        head->next = head;
    }else{
        node* tail = head->prev;
        tail->next = pnode;
        head->prev = pnode;
        pnode->prev = tail;
        pnode->next = head;
        tail=0;
    }
    return;
}

void cirDLL::remove(node* pnode){
    if(pnode->next==pnode || pnode->prev == pnode){
        head = 0;
    }else{
        if(head == pnode)
          head = head->next;
        pnode->next->prev = pnode->prev;
        pnode->prev->next = pnode->next;
    }
    delete pnode;
    return;
}

cirDLL::~cirDLL(){
    node* curr = head;
    while(curr != 0 && curr->prev != curr && curr->next != curr){
        node* pnext = curr->next;
        curr->prev->next = pnext;
        pnext->prev = curr->prev;
        delete curr;
        curr = pnext;
    }
    if(curr != 0)
      delete curr;
    head=0;
}

int countgame(int n, int x, int y){
    if(n<1 || x<1 || y<1)
      return -1;
    cirDLL* pDLL = new cirDLL();
    for(int i=1;i<=n;++i){
        pDLL->insertAtTail(new node(i,0,0));
    }
    bool bclock = true;
    node* curr = pDLL->head;
    while(curr->next != curr && curr->prev != curr){
        if(bclock){
            for(int i=0;i<x-1;++i){    //clockwise is to traverse in next pointer
                curr = curr->next;
            }
            node* tmp = curr->prev;
            pDLL->remove(curr);
            curr = tmp;
        }else{
            for(int i=0;i<y-1;++i){ //counterclockwise is to traverse in prev pointer
                curr = curr->prev;
            }
            node* tmp = curr->next;
            pDLL->remove(curr);
            curr = tmp;
        }
        bclock = !bclock;
    }
    int res = curr->getVal();
    delete pDLL;
    return res;
}

int main(int, char**){
    string str;
    while(1){
        cout<<"input n:"<<endl;
        if(getline(cin, str)==0 || str.empty())
          break;
        int n = atoi(str.c_str());

        cout<<"input x:"<<endl;
        if(getline(cin, str)==0 || str.empty())
          break;
        int x = atoi(str.c_str());
        
        cout<<"input y:"<<endl;
        if(getline(cin, str)==0 || str.empty())
          break;
        int y = atoi(str.c_str());
        
        printf("finally, the rest integer is %d\n", countgame(n, x, y));
    }
    return 0;
}


