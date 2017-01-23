/*
 * given a string of lower case, find the length of longest sub string without duplicate character(s)
 *
 * */

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution{

public:
    /*
     * once scan, in time O(n) and space O(n). smart solution
     * */
    int lengthOfLongestSubstr(const string& str){
        if(str.empty())    return 0;

        const int n = str.size();
        int res = 1;

        int pos[26];    // last position of char [a-z] appeared in s
        for(int i = 0; i < 26; ++i){
            pos[i] = -1;    // -1 as invalid position, it tells no duplicate char
        }
        pos[str[0] - 'a'] = 0;

        vector<int> lengths(n, 0); // longest substr without any duplicate char ending at [i]
        lengths[0] = 1;

        for(int i = 1; i < n; i++){
            lengths[i] = min(lengths[i-1] + 1, i - pos[str[i] - 'a']);    // optimal substructure of DP
            pos[str[i] - 'a'] = i;    // update last occurance of str[i]
            res = max(res, lengths[i]);
        }

        return res;
    }
};

/* unit test is in ../cpp_unittest/lengthOfLongestSubstr_unittest */
