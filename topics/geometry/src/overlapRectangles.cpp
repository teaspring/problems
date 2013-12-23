/*
 * problem from leetcode
 * given two axis-aligned rectangles A and B, write a function to determine if the two overlap
 * ^y
 * |
 * |
 * |_________>x
 * 
 * solution1: think straightly, overlap: every corner of either rectangle appears in the other rectangle, total 8 corners, this is not all;
 *            another case is rectangles overlap in "body" without any corner, two many conditions....
 * solution2: think the opposite. not overlap: one rectangle appers above/below, right/left of the other. reverse the result
 * */
#include "../header/preliminary.h"

struct node{
    int x;
    int y;
    node(int a, int b): x(a), y(b){
    }
    virtual ~node(){}
};

bool isinrectangle(int x, int y, node *pLU, node *pRL){        //LU: LeftUpper, RL: RightLower
    return (x > pLU->x) && (x < pRL->x) && (y > pRL->y) && (y < pLU->y); 
}

/*
 * these conditions are not all...
 * */
bool overlapRectangles01(node *p1, node *p2, node *p3, node *p4){
    if(isinrectangle(p1->x, p1->y, p3, p4))        return true;
    if(isinrectangle(p1->x, p2->y, p3, p4))        return true;
    if(isinrectangle(p2->x, p2->y, p3, p4))        return true;
    if(isinrectangle(p2->x, p1->y, p3, p4))        return true;
    if(isinrectangle(p3->x, p3->y, p1, p2))        return true;
    if(isinrectangle(p3->x, p4->y, p1, p2))        return true;
    if(isinrectangle(p4->x, p4->y, p1, p2))        return true;
    if(isinrectangle(p4->x, p3->y, p1, p2))        return true;
    return false;
}

bool overlapRectangles02(node *p1, node *p2, node *p3, node *p4){
    return !(p1->y < p4->y          //B above A
            ||p2->x < p3->x         //B on right of A
            ||p2->y > p3->y         //B below A
            ||p1->x > p4->x);       //B on left of A
}

int main(int,char**){
    string str;
    while(1){
        cout<<"input rectangle A: upper-left x, upper-left y, lower-right x, lower-right y"<<endl;
        if(getline(cin, str)==0 || str.empty())
          break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        if(n<4)    continue;
        node *p1 = new node(arr[0], arr[1]);
        node *p2 = new node(arr[2], arr[3]);

        delete[] arr;
        cout<<"input rectangle B: upper-left x, upper-left y, lower-right x, lower-right y"<<endl;
        if(getline(cin, str)==0 || str.empty())
          break;
        arr = new int[str.size()]();
        n = splitStr2IntArray(str, arr);
        if(n<4)    continue;
        node *p3 = new node(arr[0], arr[1]);
        node *p4 = new node(arr[2], arr[3]);

        cout<<"solution1: ";
        if(overlapRectangles01(p1, p2, p3, p4)){
            cout<<"Yes, overlap";
        }else{
            cout<<"No overlap";
        }
        cout<<endl;

        cout<<"solution2: ";
        if(overlapRectangles02(p1, p2, p3, p4)){
            cout<<"Yes, overlap";
        }else{
            cout<<"No overlap";
        }

        cout<<endl;
        delete[] arr;
        arr=0;
        delete p1;
        delete p2;
        delete p3;
        delete p4;
    }
    return 0;
}
