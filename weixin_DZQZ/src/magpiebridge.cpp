/*
 * question on Aug15
 * construct a magpie bridge, each cell of which is an integer pair (x,y), y>x 
 * requirement: if (x1, y1), (x2,y2) can construct, x2 > y1  
 * 1.sort the pairs in 2nd value ascending; 
 * 2.find the longest ascending sequence
 * 
 * test data:
 * (1,2), ()
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include "stdlib.h"
using namespace std;

template<typename T>
void myswap(T* pa, T* pb){
    T tmp = *pb;
    *pb = *pa;
    *pa = tmp;
    tmp = 0;
}

void quickSortXY(int* px, int* py, int N){    //quick sort the px and py based on py ascending
    if(N<2)    return;                         
    int *p = py-1, *q = py;
    int *s = py + N-1;  
    while(q<s){
        if(*q < *s){
            ++p;
            myswap(px+(p-py), px+(q-py));
            myswap(p, q);
        }
        ++q;
    }
    ++p;
    myswap<int>(px+(p-py), px+(s-py));
    myswap<int>(p, s);
    quickSortXY(px, py, p-py);
    quickSortXY(px+(p-py+1), p+1, s-p);
}

/*
* longest ascending sequence
* input: py[] is ascending
* O(nlgn) + O(n) = O(nlgn)
*/
int LAS(int* px, int* py, int n){
    quickSortXY(px, py, n);
    for(int i=0;i<n;++i){                //output the sorted
        printf("[%d, %d], ", px[i], py[i]);
    }
    printf("\n");

    int s1 = px[n-1], s2=0xffff;          //two optional start
    int l = 1;                              //O(n) iterate the array
    for(int i=n-2; i>=0; --i){
        if(py[i] < s1){
            s2 = s1;
            s1 = px[i];
            ++l;
        }else if(py[i] < s2){
            if(px[i] > s1)    s1=px[i];    //l remains, use greater x as entry
        }
    }
    return l;
}

int parse1stInt(const string& str, string::size_type& pos){
    while(pos < str.size() && !isdigit(str[pos]))
        ++pos;
    string::size_type s = pos;
    while(pos<str.size() && isdigit(str[pos]))
        ++pos;
    char* cstr = new char[pos-s+1]();
    for(size_t k=0;k<pos-s;++k)
        cstr[k] = str[s+k];
    cstr[pos-s] = '\0';
    int res = atoi(cstr);
    delete[] cstr;
    cstr = 0;
    return res;
}

int main(int argc, char* argv[]){
    int N = 0;
    while(1){
        string str1;
        if(getline(cin, str1) != 0 )        //note: if following code use getline(cin,..), here it must be used as well
           N = atoi(str1.c_str());
        if(N < 2) break;
        int* px = new int[N]();
        int* py = new int[N]();                   
        for(int i=0;i<N;++i){
            string str;
            if(getline(cin, str) != 0){
               size_t pos = 0;
               px[i] = parse1stInt(str, pos);
               py[i] = parse1stInt(str, pos);
            }
        }                   
        int res = LAS(px, py, N);
        printf("the longest ascending sequence length is %d\n", res);
        delete[] px;
        px=0;
        delete[] py;
        py=0;               
    }
}

