/*
 * given a string S, find the longest palindrome substring in S. Assum that the maximum length of S is 1000, and there exists one unique longest palindrome substring.
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

inline int min(int a, int b){
    return a<b ? a : b;
}

string longestPalindrome(const string& S){
    if(S.empty())    return string();
    int n = S.size();
    char *pMix = new char[2*n+1];
    pMix[0] = '#';
    for(int i=0, k=1;i<n || k<2*n+1;k++){
        if(pMix[k-1] == '#')    pMix[k] = S[i++];
        else    pMix[k] = '#';
    }
    int *p = new int[2*n+1]();
    p[0] =1;        //radius of longest palindrome including center
    int id=0, mx = id+p[id];//id is center of longest palindrome, mx is exclusive edge index of it
    for(int i=1;i<2*n+1;i++){
        if(2*id >= i)        p[i] = min(p[2*id-i], mx-i);
        else                 p[i] = 1;
        while(i-p[i] >= 0 && i+p[i]<2*n+1 && pMix[i-p[i]] == pMix[i+p[i]])
          p[i]++;
        if(p[i] > p[id]){
            id = i;
            mx = i+p[i];
        }
    }

    char *cstr = new char[2*p[id]+1];
    memset(cstr, 0, sizeof(char)*(2*p[id]+1));
    int k=0;
    for(int i=id-p[id]+1; i<id+p[id];i++){
        if(pMix[i]=='#')    continue;
        cstr[k++] = pMix[i];
    }
    cstr[k] = '\0';
    string res(cstr);
    
    delete[] p;
    delete[] pMix;
    delete[] cstr;
    return res;
}

int main(int, char**){
    string str;
    while(1){
        cout<<"please input string:"<<endl;
        if(getline(cin, str)==0 || str.empty())
          break;
        printf("%s\n", longestPalindrome(str).c_str());
    }
    return 0;
}

