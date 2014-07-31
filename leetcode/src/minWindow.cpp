/*
 * minimum windown substring
 * given string S and string T, find the minimum window in S which contains all the characters in T in time O(n)
 * assume only one minimum window in S
 * */
#include "../header/preliminary.h"

/*
 * this method only solve T without duplicate char
 * assume arguments have valid ASCII char, it makes use of int[256] instead of map
 * */
string minWindow_01(const string& S, const string& T){
    int m = T.size();
    int n = S.size();
    if(n < m || n == 0 || m == 0)    return string();
    int i = -1, j=0, t = -1;
    map<char, int> mp;
    while(j < n){
        while(j < n && (int)T.find(S[j]) == -1)    ++j;    // move j
        if(j == n)    break;
        t = j;
        if(i < 0)    i = t;
        if(mp.count(S[t]) == 0){
            mp[S[t]] = 1;
        }else{
            mp[S[t]]++;
        }

        if((int)mp.size() == m && mp[S[i]] > 1){    // move i if duplicate S[i] in window
            for(; t-i+1 > m; ++i){
                if((int)T.find(S[i]) == -1)    continue;
                if(mp[S[i]] == 1)        break;
                mp[S[i]]--;
            }
        }
        ++j;
    }
    if((int)mp.size() < m)    return string();
    return S.substr(i, t-i+1);
}

/*
 * this can solve case of T with duplicate char
 * */
string minWindow_02(const string& S, const string& T){
    int m = T.size();
    int n = S.size();
    if(n < m || n == 0 || m == 0)    return string();
    int need2Find[256] = {0};
    for(int i=0; i<m; ++i){
        need2Find[(int)T[i]]++;
    }
    int hasFound[256] = {0};
    int count=0, length = n, start = 0;
    for(int i=0, j=0; j<n; ++j){
        if(need2Find[(int)S[j]] == 0)    continue;
        hasFound[(int)S[j]]++;
        if(hasFound[(int)S[j]] <= need2Find[(int)S[j]])    count++;
        if(count == m){
            for(;;i++){
                if(need2Find[(int)S[i]] == 0)    continue;
                if(hasFound[(int)S[i]] > need2Find[(int)S[i]]){
                    hasFound[(int)S[i]]--;
                }else{
                    break;
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

void test(){
    while(1){
        cout << "input string S:" << endl;
        string S;
        if(getline(cin, S)==0 || S.empty())    break;
        cout << "input string T:" << endl;
        string T;
        if(getline(cin, T)==0 || T.empty())    break;
        cout << minWindow_02(S, T) << endl;
    }
    return;
}

int main(){
    test();
    return 0;
}
