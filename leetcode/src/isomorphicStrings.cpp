/*
 * given two strings s and t, determine if they are isomorphic.
 * Definition: two strings are isomorphic if the characters in s can be replaced to get t. No two characters may map to one character, but
 * a char may map to itself
 *
 * "egg", "add" => true
 * "foo", "bar" => false
 * "paper", "title" => true
 * "ab", "aa"  => false
 * "aa", "cb"  => false
 * "ab", "ca"  => true
 *
 * it is not bi-directional mapping, but no two chars can map one same char
 * */
#include <iostream>
#include <string> // string::operator[] and ::at() to get char
#include <set>

using namespace std;

class Solution{
public:
    bool isIsomorphic_01(string s, string t) {
        if(s.size() != t.size())    return false;
        if(s.empty())    return true;

        int offsets[128] = {0};  // 128 ASCII characters, 1st one is NULL
        set<int> mapped;

        const int n = s.size();
        for(int i = 0; i < n; i++) {
            int pos1 = s.at(i) - (char)NULL;
            int pos2 = t.at(i) - (char)NULL;

            if(offsets[pos1] == 0) {
                offsets[pos1] = pos2;

                set<int>::iterator it = mapped.find(pos2);
                if(it != mapped.end())    return false;  // no two char can map to one same char
                mapped.insert(pos2);
            } else if(offsets[pos1] != pos2) {
                return false;
            }
        }
        return true;
    }

    // better solution
    // it compares chars' index in either strings
    bool isIsomorphic_02(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}; // to save the char position in either string
        const int n = s.size();
        for(int i = 0; i < n; i++) {
            if(m1[(int)s[i]] != m2[(int)t[i]])    return false;
            m1[(int)s[i]] = i+1;  // default value is 0, so use 1-based as char position
            m2[(int)t[i]] = i+1;
        }
        return true;
    }
};
