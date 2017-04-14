/*
 * given an array of strings, return all groups of strings that are anagrams. All inputs are in lower-case
 * ps, anagram means words which have same characters with different order, e.g dog and god
 * */
#include "../include/preliminary.h"
#include <set>
#include <map>

typedef multimap<string, int>::iterator  iterType;
typedef pair<string, int>  pairType;

class Solution{

public:
    vector<string> anagrams(vector<string>& strs){
        vector<string> res;
        if(strs.empty())    return res;

        const int n = strs.size();
        multimap<string, int> mmp;  //pair(key of word, index in strs)
        set<string>    keys;        //save key of word
        for(int i = 0;i < n; i++){
            string kstr = wordkey(strs[i]);
            keys.insert(kstr);
            mmp.insert(pairType(kstr, i));
        }
    
        for(set<string>::iterator kIter = keys.begin(); kIter != keys.end(); ++kIter){

            if(mmp.count(*kIter) == 1)    continue;

            pair<iterType, iterType> ret = mmp.equal_range(*kIter);   //(lowerbound, upperbound) multimap::equal_range()

            for(iterType vIter = ret.first; vIter != ret.second; ++vIter){
                res.push_back( strs[vIter->second] );
            }
        }
        return res;
    }

    string wordkey(const string& word){ // count sort word, as its key
        char A[26];
        memset(A, 0, sizeof(A));

        const int n = word.size();
        for(int i = 0; i < n; i++){
            A[word[i] - 'a']++;
        }

        for(int i = 1;i < 26; i++){
            A[i] += A[i-1];
        }

        char B[n+1];
        memset(B, 0, sizeof(B));

        for(int i = 0; i < n; i++){
            int chIndex = word[i] - 'a';
            B[ A[chIndex] - 1 ] = word[i];
            A[chIndex]--;
        }
        B[n] = '\0';

        return string(B);
    }
};

