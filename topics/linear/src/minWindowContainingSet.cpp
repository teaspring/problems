/*
* from leetcode, given a set T of char and a string S. find the minimum window in S which contains all char in T
* input: string S, char* T
* my own solution, illumined by last problem with idea of deque<>, but incorrect
*
* test case:
* S = ADBBEFACBFBD, T = ABC, result is ACB
* S = ADOBECODEBANC, T = ABC, result is BANC
* S = ABCBCBCDAE, T = ABCDE, result is BCDAE
*/
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <set>
#include <queue>
#include <map>

using namespace std;

string minWindowContainingSet(const string& S, set<char>& T){
    int n = S.size();
    deque<int> Q;
    int length=n, begin=0;
    for(int i=0;i<n;++i){
        if(T.find(S[i]) != T.end()){    //it is not time O(1) without hash table
            while(!Q.empty() && S[Q.front()] == S[i]){
                Q.pop_front();
            }
            while(Q.size() > 1 && S[Q.front()] == S[Q.back()]){        //take care of case only 1 element in Q!
                Q.pop_front();
            }
            while(!Q.empty() && S[Q.back()] == S[i]){
                Q.pop_back();
            }
            Q.push_back(i);    //above clauses ensure when pushing i at back, head and tail of Q are not identical chars in S
            if(Q.size() >= T.size() && Q.back() - Q.front()+1 < length){
                length = Q.back() - Q.front() + 1;
                begin = Q.front();
            }
        }
    }
    return S.substr(begin, length);
}

/*
 * one queue<int>[256] to record all occurance index of S for char in T
 * one sorted map<int, char> to record pair of index of S and char in T, to determine whether all char in T have appeared in S
 * */
bool minWindow_01(const string& S, const string& T, int& minWindowLen, int& minWindowBegin){
    int n = S.size();
    size_t m = T.size();
    minWindowLen = 0xff;
    
    int needToFill[256] = {0};
    for(size_t i=0;i<m;++i)
      needToFill[(int)T[i]]++;
    
    queue<int> q[256];
    map<int, char> mp;
    for(int i=0;i<n;++i){
        if(needToFill[(int)S[i]]==0)    continue;

        if((int)q[(int)S[i]].size() < needToFill[(int)S[i]]){
            q[(int)S[i]].push(i);
            mp[i]  = S[i];
        }else{
            int idxToErase = q[(int)S[i]].front();        //str[i] has appeared with required times, need to pop earliest and push latest
            map<int, char>::iterator it = mp.find(idxToErase);    //m.find(pair<>.key)
            mp.erase(it);
            mp[i] = S[i];
            q[(int)S[i]].pop();
            q[(int)S[i]].push(i);
        }

        if(mp.size()==m){
            int end = mp.rbegin()->first;        //map.rbegin() is last valid element
            int begin = mp.begin()->first;
            int len = end - begin + 1;
            if(len < minWindowLen){
                minWindowLen = len;
                minWindowBegin = begin;
            }
        }
    }
    return (mp.size()==m) ? true : false;
}

/*
 * set T can have repeat character which means that char should appear in window of S more than once
 * */
bool minWindow_02(const string& S, const string& T, int& minWindowLen, int& minWindowBegin){
    int n = S.size();
    int m = T.size();
    int need2Find[256] = {0};
    for(int i=0;i<m;++i){
        need2Find[(int)T[i]]++;
    }

    int hasFound[256] = {0};
    int count = 0;
    for(int begin=0, end=0;end<n;++end){
        if(need2Find[(int)S[end]] == 0)
            continue;
        hasFound[(int)S[end]]++;
        if(hasFound[(int)S[end]] <= need2Find[(int)S[end]])
            count++;
        if(count == m){
            while(need2Find[(int)S[begin]] == 0 ||
                   hasFound[(int)S[begin]] > need2Find[(int)S[begin]]){
                if(hasFound[(int)S[begin]] > need2Find[(int)S[begin]])
                    hasFound[(int)S[begin]]--;
                begin++;
            }

            int length = end - begin + 1;
            if(length < minWindowLen){
                minWindowLen = length;
                minWindowBegin = begin;
            }
        }
    }
    return (count==m) ? true : false;
}

int main(int, char**){
    string str;
    while(1){
        cout<<"input set T: "<<endl;
        if(getline(cin, str)==0 || str.empty())
            break;
        string T(str);
        set<char> st;
        int n = str.size();
        for(int i=0;i<n;++i){
            if(isalpha(str[i]))
                st.insert(str[i]);
        }
        cout<<"input string S: "<<endl;
        if(getline(cin, str)==0 || str.empty())
            break;
        int len = 0xffff, begin = 0;
        if(minWindow_01(str, T, len, begin)){
            printf("solution 1: the minimum window containing all char in T is %s\n", str.substr(begin, len).c_str());
        }
        len = 0xffff;
        begin = 0;
        if(minWindow_02(str, T, len, begin)){
            printf("solution 2: the minimum window containing all char in T is %s\n", str.substr(begin, len).c_str());
        }
    }
    return 0;
}


