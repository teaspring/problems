/*
 * personal implementation of BFS
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

void PushPoint(Point* pp, queue<Point*>& q){
    q.push(pp);
    cout << pp->value << ' ';
}

void BFS01(Point* begin){
    queue<Point*> _q;

    _q.push(begin);
    cout << begin->value << ' ';
    while(!_q.empty()){
        Point *parent = _q.front();
        if(parent->Left != 0){
            PushPoint(parent->Left, _q);
            //_q.push(parent->Left);
            //cout << parent->Left->value << ' ';
        }
        
        if(parent->Mid != 0){
            PushPoint(parent->Mid, _q);
            //_q.push(parent->Mid);
            //cout << parent->Mid->value << ' ';
        }
        
        if(parent->Right != 0){
            PushPoint(parent->Right, _q);
            //_q.push(parent->Right);
            //cout << parent->Right->value << ' ';
        }

        _q.front()->Cov = Covered;
        _q.pop();
    }
    cout << endl;
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

    BFS01(pp);
    return;
}

int main(){
    test_01();
    return 0;
}

