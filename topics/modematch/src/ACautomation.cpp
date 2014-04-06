/*
 * Aho-Corasick(AC) aotomation, for multi-modes macth 
 * typical situation is: given n words and an artical of m char, find how many words appear in it. a little similar to KMP algorithm
 * 
 * trie tree structure, fail pointer
 *
 * test data:
 * say, she, shr, he, her; 
 *
 * */

#include "stdio.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int kind=26;
struct node{
    node *fail;
    node *next[kind];
    int count;
    node();
    virtual ~node();
}*q[100];            //queue for constructing fail pointer via BFS
int head=0, tail=0;        // head and tail of queue

node::node(){
    fail = NULL;
    count = 0;
    memset(next, 0, sizeof(node*)*kind);
}
node::~node(){
    fail = NULL;
    count = 0;
    for(int i=0;i<kind;++i){
        if(next[i] != NULL){
            delete next[i];
            next[i] = NULL;
        }
    }    
}

void insert(const string& word, node* root){                //construct trie tree with input word
    node *p = root;
    int index=0;
    for(size_t i=0;i<word.size();i++){
        index = word[i] - 'a';
        if(p->next[index] == NULL){
            p->next[index] = new node();
        }
        p = p->next[index];
    }
    p->count++;            //it means one word ends
}

void build(node* root){
    root->fail = NULL;
    q[head++] = root;            //queue push
    while(head != tail){
        node* temp = q[tail];    //queue pop
        q[tail++] = 0;
        node* p = NULL;
        for(int i=0;i<26;i++){    //build fail pointer of each child node via temp's fail
            if(temp->next[i] != NULL){
                if(temp==root){
                    temp->next[i]->fail = root;
                }else{
                    p = temp->fail;
                    while(p != NULL){
                        if(p->next[i] != NULL){
                            temp->next[i]->fail = p->next[i];
                            break;
                        }
                        p=p->fail;
                    }
                    if(p==NULL)
                      temp->next[i]->fail = root;
                }
                q[head++] = temp->next[i];    //push child to queue
            }
        }
    }
}

int query(const string& str, node *root){
    int cnt=0, index=0;
    node *p = root;
    for(size_t i=0;i<str.size();i++){
        index = str[i] - 'a';
        while(p != NULL && p->next[index]==NULL){
            p = p->fail;            //iterate upwords
        }
        if(p == NULL){
            p = root;
        }else{
            p = p->next[index];
        }
        node* temp = p;
        while(temp != root && temp->count != -1){
            cnt += temp->count;            // 0 or 1
            if(temp->count == 1){
                temp->count = -1;            //mark this word has been searched already
            }
            temp = temp->fail;
        }
    }
    return cnt;
}

int main(int argc, char* argv[]){
    return 0;
}
