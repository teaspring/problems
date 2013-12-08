/*
 * regular expression matching, from leetcode
 * Q: implement regular expression matching with support for '.' and '*'. The matching should cover entire input string(not partial)
 * '.': matches any single character
 * '*': natches zero or more of preceding element
 * bool isMatch(const char *s, const char *p)
 * isMatch("aa", "a")  false
 * isMatch("ab", ".*") true    ?!
 * isMatch("abcbcd", "a.*c.*d") true
 * */

#include "stdio.h"
#include "assert.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/*
 * recursion breaks down to two cases:  the next char is '*' or not
 * */
bool isMatch(const char *s, const char *p){
    assert(s && p);
    if(*p == '\0')
      return *s == '\0';
    if(*(p+1) != '*'){            //next char is '*', must match current character
        assert(*p != '*');
        return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
    }
    while((*p == *s) || (*p == '.' && *s != '\0')){        //next char is '*', match s with the one after '*' in p 
        if(isMatch(s, p+2))
          return true;
        s++;
    }
    return isMatch(s, p+2);
}

int main(int, char**){
    string s, p;
    while(1){
        printf("source:\n");
        if(getline(cin, s)==0 || s.empty())
          break;
        printf("pattern:\n");
        if(getline(cin, p)==0 || p.empty())
          break;
        bool res = isMatch(s.c_str(), p.c_str());
        printf("result is %s\n", res ? "true" : "false");
    }
    return 0;
}
