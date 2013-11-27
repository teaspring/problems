/*
 * problem on Oct10,2013
 * given several software versions in string: 2.0, 3.1.1, 3.1, 1.5.2 etc, find the max one
 * 
 * test data:
 * 1.0, 1.0.1
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include "stdlib.h"
using namespace std;

const int MaxNum=10;            //in version notation, the max number

template<typename T>
void myswap(T& a, T& b){
    T tmp = b;
    b = a;
    a = tmp;
    return;
}

/*
 * A[] is key, B[] is value
 * */
int countsortonce(int* A, int* B, int n){
    int* C = new int[MaxNum+1]();
    for(int i=0;i<n;++i){
        C[A[i]]++;
    }
    for(int i=1;i<MaxNum+1;++i){
        C[i] += C[i-1];
    }
    int k=0, i=MaxNum;
    for(;i>0 && C[i]-C[i-1] == 0;--i);
    if(i>0){
        k = C[i]-C[i-1];    // k means how many keys equal to max 
    }else{
        k = C[0];           //don't forget edge
    }
    int* D = new int[n]();
    for(int i=n-1;i>=0;--i){
        D[C[A[i]]-1] = B[i];
        C[A[i]]--;
    }
    for(int i=0;i<n;++i){   //count sort is ascending naturally, reverse it to be decending
        B[i] = D[n-1-i];
    }

    delete[] C;
    C=0;
    delete[] D;
    D=0;
    return k;
}

void maxversion(string* version, int n){
    int* index = new int[n]();
    for(int i=0;i<n;++i){
        index[i] = i;
    }
    int m=n;
    int* key = new int[m]();
    size_t pos = 0;
    while(m > 1){
        for(int i=0;i<m;++i){
            size_t j=pos;
            for(;j<version[index[i]].size() && version[index[i]][j] != '.';++j);
            if(j==pos)
              key[i] = 0;
            else
              key[i] = atoi(version[index[i]].substr(pos, j-pos).c_str());
        }
        m = countsortonce(key, index, m);       //we need sort in descending
        memset(key, 0, sizeof(int)*m);
        int k=0;
        for(int i=0;i<m;++i){            //among all optional string, go forwards the pos in longest str
            if(version[index[k]].size() < version[index[i]].size())
              k = i;
        }
        for(;pos<version[index[k]].size() && version[index[k]][pos] != '.';++pos);
        if(pos < version[index[k]].size())
          ++pos;            //pos is the one after '.'
    }
    int d = index[0];
    printf("the max version is %s\n", version[d].c_str());

    delete[] index;
    index=0;
    delete[] key;
    key=0;
    return;
}
      
int main(int argc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str)==0 || str.empty())
          break;
        int n = atoi(str.c_str());
        string* pstr = new string[n];
        for(int i=0;i<n;++i){
            if(getline(cin, pstr[i])==0 || pstr[i].empty())
                continue;
        }
        maxversion(pstr, n);
        delete[] pstr;
        pstr=0;
    }
    return 0;
}
