/*
 * regular expression matching, from leetcode
 * Q: implement regular expression matching with support for '.' and '*'. The matching should cover entire input string(not partial)
 * '.': matches any single char
 * '*': matches 0+ times of preceding single char(instead of '*' in wild char)
 * bool isMatch(const char *s, const char *p)
 * isMatch("aa", "a")  false
 * isMatch("ab", ".*") true !!!
 * isMatch("abcbcd", "a.*c.*d") true
 *
 * I want to explain further more about s="aa", p='a*'
 * its idea is when p[1] == '*', so it compares s[0] and p[0] firstly. when it succeeds, move s one char, to compare s[1] and p[0].
 * As a result, isMatch("aa", "a*") is true.
 * with the same idea, isMatch("ab", "a*") is false
 * Let's take a look at s="ab" and p=".*". as p[1]=='*', we compare s[0] and p[0], then s[1] and p[0]... finally, it is TRUE!
 * besides, any string of s, even empty string, can match ".*" successfully
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
