/*
 * there are total of n courses you have to take, 0 - (n-1). some of it has prerequisites, [0, 1] expresses to take course 0, you have to take course 1 firstly.
 * given the total number of courses and a list of prerequisite pairs, find whether it is possible to finish them all.
 * E.g. input '2, [0,1], [1,0]' is impossible
 * '3, [1,0]' is possible
 * */
#include <iostream>
#include <string>
#include <utility>  // std::pair<>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        unordered_map<int, int> mp; // with pair<base, prerequi>, in map, base as key, and prerequisite as value
        const int n = prerequisites.size();
        for(int i = 0; i < n; ++i) {
            int pre = prerequisites[i].second, base = prerequisites[i].first;
            unordered_map<int, int>::iterator it = mp.find(pre);
            while(it != mp.end()) {
                if(it->second == base)    return false;
                it = mp.find(it->second);
            }
            mp[base] = pre;
        }
        return true;
    }
};
