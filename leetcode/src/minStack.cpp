/*
 * design a stack that supports push, pop, and retrieving the minimum element in time O(1)
 * void push(x)
 * void pop()
 * int top()
 * int getMin()
 * */
#include "../include/preliminary.h"

/*
 * solution 1: vector<> is used, but Memory Limit Error:(
 * */
struct element{
    int val;
    int minBelow;
    element(int v, int b): val(v), minBelow(b){}
};

class MinStackI{
public:
    void push(int x){
        int n = mVec.size();
        if(mVec.empty()){
            mVec.push_back(element(x, x));
        }else{
            mVec.push_back(element(x, min(x, mVec[n-1].minBelow)));
        }
        return;
    }

    void pop(){
        if(!mVec.empty())        mVec.pop_back();
        return;
    }

    int top(){
        return mVec.empty() ? 0 : mVec[mVec.size()-1].val;
    }

    int getMin(){
        return mVec.empty() ? 0 : mVec[mVec.size()-1].minBelow;
    }
private:
    vector<element> mVec;
};

/*
 * solution 2: use double linked list(DLL), but memory limit error as well :(
 * */
struct node{
    int val;
    int minFront;
    node* pre;
    node* next;
    node(int v, int f, node* p): val(v), minFront(f), pre(p), next(NULL){}
};

class MinStackII{
public:
    void push(int x){
        if(!mTail){
            mHead = new node(x, x, NULL);
            mTail = mHead;
        }else{
            mTail->next = new node(x, min(x, mTail->minFront), mTail);
            mTail = mTail->next;
        }
    }

    void pop(){
        if(!mTail)    return;
        node* tmp = mTail;
        mTail = mTail->pre;
        if(mTail)    mTail->next = NULL;
        tmp->pre = NULL;
        delete tmp;
        if(!mTail)    mHead = NULL; // cannot be forgotten !
        return;
    }

    int top(){
        if(!mTail)    return 0;
        return mTail->val;
    }

    int getMin(){
        if(!mTail)    return 0;
        return mTail->minFront;
    }

public:
    MinStackII(): mHead(NULL), mTail(NULL){}
    virtual ~MinStackII(){
        while(mHead){
            node* tmp = mHead;
            mHead = mHead->next;
            tmp->next = NULL;
            if(mHead)    mHead->pre = NULL;
            delete tmp;
        }
        mTail = NULL;
    }

private:
    node* mHead;
    node* mTail;
};

/*
 * this solution causes memory limit error ?!!
 * */
class MinStackIII{
public:
    void push(int x){
        if(stk.empty()){
            stk.push(new element(x, x));
        }else{
            int preMin = stk.top()->minBelow;
            stk.push(new element(x, min(preMin, x)));
        }
        return;
    }

    void pop(){
        if(!stk.empty()){
            element* tmp = stk.top();
            stk.pop();
            delete tmp;
        }
    }

    int top(){
        return stk.empty() ? 0 : stk.top()->val;
    }

    int getMin(){
        return stk.empty() ? 0 : stk.top()->minBelow;
    }

    virtual ~MinStackIII(){
        while(!stk.empty()){
            pop();
        }
    }

private:
    stack<element*> stk;
};

/*
 * the oj judge accepts this kind of structure without explicit stack<>
 * each node takes extra pointers of minimum next
 * */
struct ItsNode{
    int val;
    ItsNode* next;
    ItsNode* minNext;
    ItsNode(int x):val(x), next(NULL), minNext(NULL){}
};

class MinStackIV{
public:
    void push(int x){
        ItsNode* curr = new ItsNode(x);
        if(empty()){
            minHead = curr;
        }else{
            curr->next = head;
            curr->minNext = minHead;
            if(x < minHead->val)    minHead = curr;
        }
        head = curr;
        return;
    }

    void pop(){
        if(empty())    return;

        ItsNode* tmp = head;
        head = tmp->next;
        tmp->next = NULL;

        minHead = tmp->minNext; // need to compare head->minNext and tmp->minNext!
        tmp->minNext = NULL;
        delete tmp;
        return;
    }

    int top(){
        return empty() ? 0 : head->val;
    }

    int getMin(){
        return empty() ? 0 : minHead->val;
    }

    bool empty(){
        return head == NULL;
    }

    MinStackIV():head(NULL), minHead(NULL){}

    virtual ~MinStackIV(){
        while(!empty()){
            pop();
        }
    }

private:
    ItsNode* head;     // as top of the stack
    ItsNode* minHead;  // as min node of the stack
};
