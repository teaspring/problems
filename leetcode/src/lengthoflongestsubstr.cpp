/*
 * given a string of lower case, find the length of longest substring without repeat characters
 *
 * */

#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

inline int min(int a, int b){
    return a<b ? a : b;
}
int lengthOfLongestSubstring(const string& s){
    if(s.empty())    return 0;
    int pos[26];    //position of 'a' to 'z'
    for(int i=0;i<26;++i){
        pos[i] = -1;
    }
    pos[s[0]-'a'] = 0;
    int *length = new int[s.size()]();
    length[0] = 1;
    int res = 1;
    for(size_t i=1; i<s.size();i++){
        length[i] = min(length[i-1]+1, i - pos[s[i]-'a']);    //optimal substructure of Dynamic Programming
        pos[s[i]-'a'] = i;    //don't forget it
        if(res < length[i])        res = length[i];
    }
    delete[] length;
    return res;
}

int main(int, char**){
    string str;
    while(1){
        cout<<"please input string:"<<endl;
        if(getline(cin, str)==0 || str.empty())        break;
        printf("%d\n", lengthOfLongestSubstring(str));
    }
    return 0;
}
