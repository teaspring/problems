/*
 * personal implemenation of DFS
 * Note: the data structure can be tree or array. But as linked list does not support random access, array is easier.
 * date: Feb03, 2013
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

enum CoveredEnum {
    NoProbed = 0,
    Probed,
    Covered
};

struct Point{
    Point(int val): 
        value(val), Left(0), Mid(0), Right(0), Cov(NoProbed){}
    int value;
    Point *Left;
    Point *Mid;
    Point *Right;
    CoveredEnum Cov;
};

Point* FindNextChild(Point* pParent){
    if(pParent->Cov == Covered)        return 0;
    if(pParent->Left != 0 && pParent->Left->Cov == NoProbed){
        return pParent->Left;
    }else if(pParent->Mid != 0 && pParent->Mid->Cov == NoProbed){
        return pParent->Mid;
    }else if(pParent->Right != 0 && pParent->Right->Cov == NoProbed){
        return pParent->Right;
    }
    return NULL;
}

void DFS02(Point* begin){
    stack<Point*> _stack;
    Point* parent = begin;

    _stack.push(parent);
    cout << parent->value << ' ';
    while(!_stack.empty()){
        Point* child = FindNextChild(parent);
        if(child != 0){
            _stack.push(child);
            cout << child->value << ' ';
            child->Cov = Probed;
            parent = child;
        }else{
            _stack.top()->Cov = Covered;
            _stack.pop();
            if(!_stack.empty()){
                parent = _stack.top();
            }
        }
    }
    cout << endl;
    return;
}

void test_01(){
    Point* pp = new Point(1);
    pp->Left  = new Point(2);
    pp->Mid   = new Point(3);
    pp->Right = new Point(4);

    pp->Left->Left   = new Point(5);
    pp->Left->Right  = new Point(6);
    pp->Mid->Left    = new Point(7);
    pp->Mid->Right   = new Point(8);
    pp->Right->Left  = new Point(9);
    pp->Right->Mid   = new Point(10);
    pp->Right->Right = new Point(11);

    pp->Left->Left->Left    = new Point(12);
    pp->Left->Left->Right   = new Point(13);
    pp->Left->Right->Left   = new Point(14);
    pp->Mid->Left->Left     = new Point(15);
    pp->Mid->Left->Right    = new Point(16);
    pp->Mid->Right->Left    = new Point(17);
    pp->Mid->Right->Right   = new Point(18);
    pp->Right->Left->Left   = new Point(19);
    pp->Right->Left->Right  = new Point(20);
    pp->Right->Mid->Left    = new Point(21);
    pp->Right->Mid->Right   = new Point(22);
    pp->Right->Right->Left  = new Point(23);
    pp->Right->Right->Right = new Point(24);

    DFS02(pp);
    return;
}

int main(){
    test_01();
    return 0;
}
