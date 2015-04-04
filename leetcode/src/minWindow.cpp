/*
 * minimum windown substring
 * given string S and string T, find the minimum window in S which contains all the characters in T in time O(n)
 * assume only one minimum window in S
 * */
#include "../include/preliminary.h"

class Solution{

public:
    /*
    * it can solve case of T with duplicate char
    * */
    string minWindow(const string& S, const string& T){
        const int m = T.size();
        const int n = S.size();
        if(n == 0 || m == 0 || n < m)    return string();

        int need2Find[256] = {0};
        for(int i = 0; i < m; ++i){
            need2Find[(int)T[i]]++;
        }

        int hasFound[256] = {0};
        int count = 0, length = n, start = 0;
        for(int i = 0, j = 0; j < n; ++j){ // i is inclusive left bound of window, j is inclusive right bound
            if(need2Find[(int)S[j]] == 0)    continue;

            hasFound[(int)S[j]]++;
            if(hasFound[(int)S[j]] <= need2Find[(int)S[j]])    count++;

            if(count == m){
                for(;;i++){ // move left bound to narrow the window
                    if(need2Find[(int)S[i]] == 0)    continue;

                    if(hasFound[(int)S[i]] <= need2Find[(int)S[i]]){ // cannot narrow
                        break;
                    }else{
                        hasFound[(int)S[i]]--;
                    }
                }

                if(length > j-i+1){
                    start  = i;
                    length = j-i+1;
                }
            }
        }
        return count == m ? S.substr(start, length) : string();
    }
};

/* unit test is in ../cpp_unittest/minWindow_unittest */
