/*
 * 9.3, search in a sorted array is rotated somewhere. assume increasing order
 */
#include "stdio.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stack>

using namespace std;

int searchExt(int *a, int l, int u, int x){
    while(l <= u){                     //area will be shorten by 1 each round(best practice for binary search)
        int m = (l+u)/2;
        if(x == a[m]){
            return m;
        }else if(a[l] <= a[m]){            //[l, m] is linearly increasing.note when compare the boudary, it is <= or >=
            if(x > a[m]){
                l = m+1;
            }else if(x >= a[l]){
                u = m-1;
            }else{ 
                l = m+1;                //not inside [l, m], must be in the other half
            }
        }else{                            //rotate break point is inside [l, m]
            if(x < a[m] || x > a[l]){    
                u = m-1;
            }else if(x <= a[u]){
                l = m+1;
            }else{                        //[l,m] is not linear, possible to have x
                u = m-1;
            }
        }
    }
    return -1;
}

void test_01(){
    return;
}

int main(int, char**){
    //ofstream ofs("./result.txt", ios::app);    //create file if not exist
    return 0;
}

