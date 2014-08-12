/*
 * substring with concatenation of all words
 * given a string S, and a list of words L, that are all of the same length. Find all starting indices of substring in S
 * that is a concatenation of each word in L exactly.
 * e.g.
 * S="barfoothefoobarfoo", L=["foo", "bar"],           return 0,9,12,15
 * S="abaababbaba",        L=["ab", "ba", "ab", "ba"], return 1,3
 * S="abababab",           L=["ab", "ba"],             return null
 * S="mississippi",        L=["is", "si"],             return 1,4
 *
 * a question can be asked: if words in L has different length?
 * */
#include "../header/preliminary.h"

bool isfull(int *arr, int n){
    for(int i=0; i<n; i++){
        if(arr[i] == 0)    return false;
    }
    return true;
}

void checkOnce(string str, vector<string>& L, int *used, vector<int> *headpos, 
            int start, vector<int>& res){
    if(isfull(used, L.size())){
        res.push_back(start);
        return;
    }
    if(str.empty())     return;
    vector<int> options = headpos[(int)str[0]];
    int n = str.size();
    for(size_t i=0; i<options.size(); i++){
        int t = options[i];    // index in L
        if(used[t] == 1)    continue;    // if used already
        string src = L[t];
        int m = src.size();
        if(n < m)    continue;    // if length overflow
        int j = m-1;
        while(j>=0 && src[j] == str[j])    j--;
        if(j>=0)    continue;
        used[t] = 1;
        checkOnce(str.substr(m, n-m), L, used, headpos, start, res);
        used[t] = 0;
    }
    return;
}

vector<int> findSubstring(string S, vector<string>& L){
    vector<int> res;
    if(S.empty() || L.empty() || L[0].empty())    return res;
    int l = L.size(), m = L[0].size(), n = S.size();
    if(n < l * m)    return res;
    vector<int> headpos[256];
    for(int i=0; i<256; i++){
        headpos[i] = vector<int>();
    }
    int used[l];
    memset(used, 0, sizeof(used));
    for(int i=0; i<l; i++){
        if(L[i].empty())    continue;
        headpos[(int)L[i][0]].push_back(i);
    }
    for(int i=0; i<n; i++){
        checkOnce(S.substr(i, n-i), L, used, headpos, i, res);
    }
    return res;
}

class Solution{
public:
    vector<int> findSubstring(string S, vector<string>& L){
        vector<int> res;
        int m = L.size(), n = S.size();
        if(m==0 || n==0)    return res;
        int l = L[0].size();
        if(n < l*m)    return res;
        map<string, int> need2Find, hasFound;  // string is used as key for search in O(1)
        for(int i=0; i<m; i++){
            if(need2Find.count(L[i]) == 0){
                need2Find[L[i]] = 1;
            }else{
                need2Find[L[i]]++;
            }
        }
        int cnt = 0;
        int used[n];    // store beginning j
        memset(used, 0, sizeof(used));
        set<int> st;    // store result for search duplicate
        for(int k = 0;k <= n-l*m; k++){
            if(used[k] == 1)  continue;
            hasFound.clear();
            for(int i=0; i<m; i++){
                hasFound[L[i]] = 0;
            }
            cnt = 0;

            for(int i=k, j=k; j <= n-l;){
                if(used[j] == 0)    used[j] = 1;
                string str = S.substr(j, l);
                if(need2Find.count(str) == 0){
                    j++;
                    continue;
                }
                hasFound[str]++;
                if(hasFound[str] <= need2Find[str])    cnt++;
                if(cnt == m && j+l-i >= l*m){
                    for(;;){
                        string tmp = S.substr(i, l);
                        if(need2Find.count(tmp) == 0){
                            i++;
                            continue;
                        }
                        if(hasFound[tmp] > need2Find[tmp]){
                            hasFound[tmp]--;
                            i += l;
                        }else{
                            break;
                        }
                    }
                    if(j+l-i == l*m && st.count(i) == 0){  // NOTE: check if length valid and not found yet
                        st.insert(i);
                        res.push_back(i);
                    }
                }
                j += l;
            }
        }
        return res;
    }

    void test_01(){
        const string arr[] = {"bar", "foo"};
        vector<string> L(arr, arr + sizeof(arr)/sizeof(string));
        string S("foobarfoo");
        vector<int> res = findSubstring(S, L);
        displayVector(res);
    }

    void test_02(){
        const string arr[] = {"ab", "ba", "ab", "ba"};
        vector<string> L(arr, arr + sizeof(arr)/sizeof(string));
        string S("abaababbaba");
        vector<int> res = findSubstring(S, L);
        displayVector(res);
    }

    void test_03(){
        const string arr[] = {"ab", "ba"};
        vector<string> L(arr, arr + sizeof(arr)/sizeof(string));
        string S("abababab");
        vector<int> res = findSubstring(S, L);
        displayVector(res);
    }

    void test_04(){
        const string arr[] = {"is", "si"};
        vector<string> L(arr, arr + sizeof(arr)/sizeof(string));
        string S("mississippi");
        vector<int> res = findSubstring(S, L);
        displayVector(res);
    }
};

int main(){
    Solution s;
    s.test_01();
    s.test_02();
    s.test_03();
    s.test_04();
    return 0;
}
