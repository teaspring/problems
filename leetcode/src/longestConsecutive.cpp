/*
 * given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 * complete it in time O(n)
 *
 * test case:
 * [100, 4, 200, 1, 3, 2], the longest consecutive sequence is [1,2,3,4], length is 4
 *
 * */

#include "../include/preliminary.h"
#include <unordered_map>

class Solution{

public:
    /*
     * hash_map<>(unordered_map<>) must be used
     * 1. how to enable map[i] present consecutive sequence length covering it ?
     * 2. how to process upper(right)/lower(left) bound ?
     * */
    int longestConsecutive_01(vector<int> &num){
        if(num.empty())    return 0;

        unordered_map<int, int> uii; // uii[k] tells longest consecutive width of which k is either leftbound or right bound

        int maxlen = 1;

        for(auto &val : num){
            // NOTE: operator[] is overused, while key not in, after operator[] is called, size increases by 1
            if(uii[val] != 0)    continue;

            uii[val] = 1;

            int leftbound = uii[val - 1], rightbound = uii[val + 1];

            // if leftbound = 0 and rightbound = 0, uii[val] = 1 remains
            uii[val - leftbound] = uii[val + rightbound] = 1 + leftbound + rightbound;

            maxlen = max(maxlen, 1 + leftbound + rightbound);
        }

        return maxlen;
    }

    /*
     * revise on solution1. it calls find() instead of operator[]
     * */
    int longestConsecutive_02(vector<int> &num){
        if(num.empty())    return 0;

        unordered_map<int, int> uii;

        int maxlen = 1;

        unordered_map<int, int>::const_iterator it = uii.end();

        for(auto &val : num){
            it = uii.find(val);
            if(it != uii.end())    continue;

            uii[val] = 1;

            int leftbound = 0;

            it = uii.find(val - 1);
            if(it != uii.end())    leftbound = it->second;

            int rightbound = 0;

            it = uii.find(val + 1);
            if(it != uii.end())    rightbound = it->second;

            uii[val - leftbound] = uii[val + rightbound] = 1 + leftbound + rightbound;

            maxlen = max(maxlen, 1 + leftbound + rightbound);
        }

        return maxlen;
    }
};

/* unit test is in ../cpp_unittest/longestConsecutive_unittest */
