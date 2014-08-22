/*
 * implememnt wildcard pattern matching with support for '?' and '*'
 * '?' macthes any single char
 * '*' macthes any sequences of char, including empty string
 * s = "hi", p = "*?i"    true
 *           p = "*i"    true
 *           p = "*"     true
 *           p = "**a"   false
 *           p = "*?a"   false
 *  s = "",  p = "*?"    false
 * */
#include "stdio.h"

using namespace std;

bool isMatch(const char *s, const char *p){
    if(!*p && !*s)    return true;
    if(*p == *s)      return isMatch(s+1, p+1);
    if(*p == '?' && *s)    return isMatch(s+1, p+1);
    if(*p == '*'){
        bool ret = false;
        while(*p == '*')    ++p;
        if(!*p)    return true;
        while(*s){
            const char *ts = s, *tp = p;
            while(*ts && (*ts == *tp || *tp == '?')){
                if(*tp == '*')    break;
                ++ts;
                ++tp;
            }
            if(!*ts && !*tp)    return true;  // both '\0'
            if(*tp == '*'){
                ret |= isMatch(ts, tp);
                return ret;
            }
            if(!*ts)    return false;
            ++s;
        }
        return ret;
    }else
      return false;
}

int main(){
    return 0;
}

