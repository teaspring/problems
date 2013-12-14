/*
 * from leetcode
 * given a node from a cyclic linked list which has been sorted. write a function to insert a value into the list which remains
 * as cyclic sorted list. the given node can be any single node in the list
 *
 * >>it needs careful process of edge cases where value to insert
 * test case: ascending list and decending list, and position to insert can be normal within the list or between tail and head.
 * */
#include "stdio.h"
#include <iostream>
#include <string>

using namespace std;

struct node{
    int val;
    node* pnext;
};

void insertnode(node* prev, node* next, int v){
    node* curr = new node;
    curr->val = v;
    prev->pnext = curr;
    curr->pnext = next;
    return;
}

void insertcyclicsortedSLL(node* pnode, int v){
    node *tail=pnode, *head=pnode->pnext;
    node *next = head->pnext;
    node *nnext = next->pnext;
    node *realtail=0, *realhead=0;
    bool asc=true;
    if(head->val > next->val){        //confirm cycle is ascending or descending
        if(tail->val > head->val || next->val > nnext->val){
            asc = false;
        }else{
            realtail = head;
            realhead = next;
        }
    }else{
        if(tail->val > head->val && next->val > nnext->val){
            asc = false;
            realtail = head;
            realhead = next;
        }
    }
    if(realhead != 0){
        head = realhead;
        tail = realtail;
    }

    next=0, nnext=0;
    tail->pnext=0;        //cut the cycle after tail
    node *prev = tail, *curr = head;
    while(curr != 0){
        if(!asc){        //decending cyclic, realhead should be maximum while realtail should be minimum 
            if(prev != realtail && prev->val > v && v > curr->val){
                insertnode(prev, curr, v);
                break;
            }else if(prev < curr){    //v should be between realtail and realhead
                realtail = prev;
                realhead = curr;
                if(v > realhead->val || v < realtail->val){
                    insertnode(realtail, realhead, v);
                    break;
                }
            }
        }else{        //ascending cyclic, realhead should be minimum while realtail should be maximum
            if(prev != realtail && prev->val < v && v < curr->val){
                insertnode(prev, curr, v);
                break;
            }else if(prev > curr){    //v should be between realtail and realhead
                realtail = prev;
                realhead = curr;
                if(v > realtail->val || v < realhead->val){
                    insertnode(realtail, realhead, v);
                    break;
                }
            }
        }
        prev = curr;
        curr = curr->pnext;
    }
    tail->pnext = head;
    prev=0, head=0, tail=0, realhead=0, realtail=0;
    return;
}

void showcycleSLL(node* pnode){
    node* curr = pnode;
    printf("cyclic sorted list is: ");
    do{
        printf("%d ", curr->val);
        curr = curr->pnext;
    }while(curr != pnode);
    printf("\n");
    return;
}

int main(int, char**){
    return 0;
}

