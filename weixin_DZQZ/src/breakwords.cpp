/*
 * problem on Oct14, given a set of words in dictionary, confirm whether a given string can be splited to these words
 * recurse -> dynamic programming
 *
 * */

#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool dictionaryContains(const string& str, string* dict){            //it should match str among a set of words
    return 0;
}

/*
 * optimized dynamic programming, use 1-D array to save status of str[0,i) instead of 2-D array
 * its logic is if both of str[0,i) and str[i,j) are true, str[0,j) is true definitely. with{hello, kitty, hellokitty}, it will
 * check "hello" and "kitty" seperately without checking "hellokitty", maybe it is another problem of grammar:)
 * */
bool wordbreak(const string& str){
    int n = str.size();
    if(n==0)
      return true;
    bool wb[n+1];
    memset(wb, 0, sizeof(bool)*(n+1));
    for(int i=1;i<=n;++i){
        if(wb[i]==false && dictionaryContains(str.substr(0,i)))
          wb[i] = true;
        if(wb[i]){
            if(i==n)
              return true;
            for(int j=i+1;j<=n;++j){
                if(wb[j] == false && dictionaryContains(str.substr(i,j-i))) 
                  wb[j] = true;
                if(j==n && wb[j])
                  return true;
            }
        }
    }
    return false;
}

int main(int, char**){
    return 0;
}
