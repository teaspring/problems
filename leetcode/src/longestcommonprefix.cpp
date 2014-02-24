/*
 * find the longest common prefix string amongst an array of strings
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string longestCommonPrefix(const vector<string>& strs){
    int n = strs.size();
    if(n==0)    return string();
    if(n==1)    return string(strs[0]);
    size_t length = strs[0].size();
    for(int i=1;i<n;i++){
        length = min(length, strs[i].size());
    }
    char *res = new char[length+1];
    size_t i=0;
    for(;i<length;++i){
        int j=1;
        for(;j<n && strs[j][i] == strs[j-1][i];++j);
        if(j<n)    break;
        res[i] = strs[0][i];
    }
    res[i] = '\0';
    string prefix(res);
    delete[] res;
    return prefix;
}

int main(int, char**){
    return 0;
}
