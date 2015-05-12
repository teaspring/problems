/*
 * regular expression matching, from leetcode
 *
 * Q: implement regular expression matching with support for '.' and '*', which should cover entire input string(not partial)
 * '.': matches any single char
 * '*': matches 0+ times of preceding single char(instead of '*' in wild char)
 *
 * bool isMatch(const char *s, const char *p)
 * isMatch("aa", "a")  false
 * isMatch("ab", ".*") true !!!
 * isMatch("abcbcd", "a.*c.*d") true
 *
 * my own understanding about s="aa", p='a*':
 *
 * 1. its idea is when p[1] == '*', so it compares s[0] and p[0] firstly. when it succeeds, move one char ahead in s
 * to compare s[1] and p[0]. As a result, isMatch("aa", "a*") is true.
 *
 * 2. with the same idea, isMatch("ab", "a*") is false
 *
 * 3. Let's take a look at s="ab" and p=".*". as p[1]=='*', we compare s[0] and p[0], then s[1] and p[0]... finally, it is TRUE!
 *
 * 4. in this way, any string of s even empty string can match ".*"
 * */

#include <cassert>

using namespace std;

/*
 * recursion breaks down to two cases:  the next char is '*' or not
 * */
bool isMatch(const char *s, const char *p){
    assert(s && p);

    if(*p == '\0')    return *s == '\0';

    if(*(p+1) != '*'){  // p[1] is not '*', so s[0] must match p[0]

        assert(*p != '*');

        return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
    }

    while((*p == *s) || (*p == '.' && *s != '\0')){ // p[1] is '*', match s[0] and p[0] recursely with moving s

        if(isMatch(s, p+2))    return true;  // p[1] '*' evaluates 0 occurance of p[0]

        s++;
    }

    return isMatch(s, p+2);
}

