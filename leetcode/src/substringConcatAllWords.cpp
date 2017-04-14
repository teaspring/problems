/*
 * substring with concatenation of all words
 * given a string S, and a list of words L that are all of the same length.
 * Q: Find all starting indices of substring in S that is a concatenation of each word in L exactly.
 *
 * e.g.
 * S="barfoothefoobarfoo", L=["foo", "bar"],           return 0,9,12
 * S="abaababbaba",        L=["ab", "ba", "ab", "ba"], return 1,3
 * S="abababab",           L=["ab", "ba"],             return null
 * S="mississippi",        L=["is", "si"],             return 1,4
 *
 * another question: if words in L has different length?
 * */
#include <string>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

class Solution{

public:
    /*
     * this solution come from the idea of "minWindow", with a sliding window range
     * */
    vector<int> findSubstring(const string& S, vector<string>& L){
        if(S.empty() || L.empty())    return vector<int>();

        const int m = L.size();
        const int n = S.size();
        const int l = L[0].size();
        if(n < l * m)    return vector<int>();

        vector<int> res;
        map<string, int> need2Find, hasFound;  // string is used as key for search in O(1)
        for(int i = 0; i < m; i++){
            if(need2Find.count(L[i]) == 0){
                need2Find[L[i]] = 1;
            }else{
                need2Find[L[i]]++;
            }
        }

        int cnt = 0; // accumulated count of valid words
        vector<int> used(n, 0);    // store beginning

        for(int k = 0; k <= n - l*m; k++){ // k is beginning of new concatenation of length l*m
            if(used[k] != 0)    continue;  // skip the begin index which has been checked

            for(int i = 0; i < m; i++){ // reset accumulate container and counter
                hasFound[L[i]] = 0;
            }
            cnt = 0;

            for(int i = k, j = k; j <= n-l;){ // check substr [i, j+l) whether is valid required concatenation
                string str = S.substr(j, l);

                if(need2Find.count(str) == 0){ // str is not valid word in L
                    used[j] = -1;

                    if(cnt > 0){ // preceding range [i, j] has found valid word already
                        if(used[i] == 0)    used[i] = -1;
                        break;
                    }

                    i++;
                    j++;
                    continue;
                }

                hasFound[str]++;

                if(hasFound[str] <= need2Find[str])    cnt++;

                if(cnt == m){
                    while(j + l -i >= l*m){
                        string head = S.substr(i, l);  // head must be valid word

                        if(hasFound[head] == need2Find[head])    break; // cannot move forward i

                        if(used[i] == 0)    used[i] = -1; // i is not valid begin of concatenation of l*m
                        i += l;
                        hasFound[head]--;
                    }

                    if(j + l - i == l*m){
                        if(used[i] == 0){
                            used[i] = 1;  // now i is verified to be valid begin of concatenation
                            res.push_back(i);
                        }
                    }else{ // j+l-i > l*m, so i has to move forward
                        if(used[i] == 0)    used[i] = -1;
                        i += l;
                        hasFound[S.substr(i, l)]--;
                        cnt--;
                    }
                }

                j += l;
            }
        }
        return res;
    }
};

/* unit test is in ../cpp_unittest/substringConcatAllWords_unittest */
