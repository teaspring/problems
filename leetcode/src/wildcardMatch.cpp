/*
 * implememnt wildcard pattern matching with support for '?' and '*'
 * '?' macthes any single char
 * '*' macthes any sequences of char, including empty string
 *
 * s = "hi", p = "*?i"    true
 *           p = "*i"    true
 *           p = "*"     true
 *           p = "**a"   false
 *           p = "*?a"   false
 * s = "",   p = "*?"    false
 * s = "aa", p = "a"   false
 * s = "aa", p = "aa"   true
 * s = "aa", p = "aaa"   false
 * s = "aa", p = "*"   true
 * s = "aa", p = "a*"   true
 * s = "ab", p = "?*"   true
 * s = "aab", p = "c*a*b"  false
 * */

using namespace std;

class Solution{

public:
    /*
     *
     * */
    bool isMatch(const char *s, const char *p){
        if(!*p && !*s)    return true;  // both walked totally

        if(*p == *s)      return isMatch(s+1, p+1);  // real char equals, both walk one more char

        if(*p == '?' && *s)    return isMatch(s+1, p+1); // '?' in pattern equals one char in str, both walk one more char

        if(*p != '*')    return false;  // invalid pattern char

        // now *p == '*'
        while(*p == '*')    ++p;  // skip '*'

        if(!*p)    return true;  // '\0'

        // now *p is not '*'
        // below code seems a little confusing
        while(*s){

            const char *ts = s, *tp = p;

            while(*ts && (*ts == *tp || *tp == '?')){

                if(*tp == '*')    break;

                ++ts;
                ++tp;
            }

            if(!*ts && !*tp)    return true;  // both '\0'

            if(*tp == '*')    return isMatch(ts, tp);

            if( !(*ts) )    return false;

            ++s;
        }

        return false;
    }
};

/* unit test is in ../cpp_unittest/wildcardMatch_unittest */
