/*
 * from oj.leetcode. Given a src string and a set of words. break the str into collection of all the words in that set. return all of the
 * word break options. Among each option, separate the words by " "
 * */
#include "../header/preliminary.h"

class Solution {
    void collect(vector<list<int> > &mark, int ind, const string &s, string path, vector<string>& result){
        for(auto& stop : mark[ind]) {
            string sub = s.substr(ind, stop - ind);
            string newpath = path + (ind == 0 ? sub : " " + sub);

            if(stop == s.length()) {
                result.push_back(newpath);
            } else {
                collect(mark, stop, s, newpath, result);
            }
        }
    }

public:
    vector<string> wordBreak(string s, unordered_set<string> &dict){
        vector<list<int> > mark(s.length(), list<int>());

        for(int stop = s.length(); stop >= 0; stop--) {

            if(stop < s.length() && mark[stop].empty())  // key to reduce excessive time complexity
                continue;

            for(int start = stop - 1; start >= 0; start--){
                if(dict.count(s.substr(start, stop - start)))
                    mark[start].push_back(stop);
            }
        }

        vector<string> result;
        collect(mark, 0, s, "", result);
        return result;
    }
}
