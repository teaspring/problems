/*
 * given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively
 *
 * below is one possible representation of "great"
 *       great
 *       /   \
 *      gr   eat
 *     / \   /  \
 *    g   r e    at
 *              /  \
 *             a    t
 *
 * to scramble the string, we may choose any non-leaft node and swap its two children.
 * e.g. if we choose "gr" and swap its two children, it looks like below:
 * check if two strings are scrambled.
 *       rgeat
 *       /   \
 *      rg   eat
 *     / \   /  \
 *    r   g e    at
 *              /  \
 *             a    t
 *  now we say "great" is a scrambled string of "rgeat"
 *
 *  given two strings s1 and s2, determine if s2 is a scrambled string of s1
 */

#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{

public:
    bool isScramble(string s1, string s2){
        if(s1.empty() || s2.empty() || s1.length() != s2.length())    return false;

        if(s1 == s2)    return true;

        // firstly verify the two strings with characters
        const int n = s1.length();

        const char* arr1 = s1.c_str();
        vector<char> vec1(arr1, arr1 + n);

        const char* arr2 = s2.c_str();
        vector<char> vec2(arr2, arr2 + n);

        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());

        vector<char>::iterator it1 = vec1.begin(), it2 = vec2.begin();
        while(it1 != vec1.end()){
            if(*(it1++) != *(it2++))    return false;
        }

        // divide-and-conquer
        for(int i = 1; i < n; i++){
            if(isScramble(s1.substr(0, i), s2.substr(0, i))
               && isScramble(s1.substr(i, n-i), s2.substr(i, n-i))){
                return true;
            }

            if(isScramble(s1.substr(0, i), s2.substr(n-i, i))
               && isScramble(s1.substr(i, n-i), s2.substr(0, n-i))){
                return true;
            }
        }

        return false;
    }
};

/* unit test is in ../cpp_unittest/scrambleString_unittest */
