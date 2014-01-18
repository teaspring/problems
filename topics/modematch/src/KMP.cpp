/*
 * one copy of implementation of KMP string match algorithm
 * for string match problem that match a string T with pattern P, the KMP(Knuth-Morris-Pratt) algorithm is popular at its linear time O(n)
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

inline int max(int a, int b){
    return a>b ? a : b;
}
/*
 * for KMP algorithm, the most important part is the preprocess of pattern P, to get int prefix[P]
 * it means for P[0...i], the greatest k that prefix of P(P[0..k-1]) matches suffix of P(P[i-k+1, i])
 * generally, this pattern preprocess is in time O(P)
 * */
void setPrefix(const string& pattern, int *prefix){        //prefix should be [n]
    const int n = pattern.size();
    prefix[0] = 0;
    for(int i=1;i<n;i++){
        int k=prefix[i-1];    //because index is 0-based, and length is 1-based. so k=prefix[i-1] is just the next potential matched char
        for(;pattern[k] != pattern[i] && k>0; k=prefix[k-1]);
        if(pattern[k] == pattern[i])    prefix[i] = k+1;    //here k is index of 0-based, so prefix[i] should be 1-based
        else                            prefix[i] = 0;
    }
    return;
}

bool isMatchKMP(const string& str, const string& pattern){
    int n=str.size(), m=pattern.size();
    if(n<m)             return false;
    if(n==0 && m==0)    return true;
    if(m==0)            return false;
    int *prefix = new int[m]();
    setPrefix(pattern, prefix);    //get prefix array
    int i=0, s=0;
    bool bfind = false;
    while(i<n){
        if(s>i||(i-s<m && pattern[i-s] == str[i])){
            ++i;
        }else if(i-s==m){
            bfind=true;
            break;
        }else{    //shift pattern at least 1
            s += (i-s<=1)? 1 : max(1, prefix[i-s-1]);
        }
    }
    delete[] prefix;
    return bfind || i-s==m;     //note if i reaches n, it must be detected as well
}

int main(int, char**){
    while(1){
        string pat;
        cout<<"please input matching pattern:"<<endl;
        if(getline(cin, pat)==0 || pat.empty())
          break;
        string str;
        cout<<"please input string to match in:"<<endl;
        if(getline(cin, str)==0 || str.empty())
          break;
        printf("%s\n", isMatchKMP(str, pat) ? "true" : "false");
    }
    return 0;
}
