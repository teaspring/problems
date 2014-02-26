/*
 * given an array of strings, return all groups of strings that are anagrams. All inputs are in lower-case
 * ps, anagram means words which have same characters with different order, e.g dog and god
 * */
#include "../header/preliminary.h"
#include <set>
#include <map>

typedef multimap<string, int>::iterator        iterType;
typedef pair<string, int>                      pairType;

string wordkey(const string& word){        //count sort word, as its key
    char *A = new char[26];
    memset(A, 0, sizeof(char)*26);
    int n = word.size();
    for(int i=0;i<n;i++){
        A[word[i] - 'a']++;
    }
    for(int i=1;i<26;i++){
        A[i] += A[i-1];
    }
    char *B = new char[n+1];
    for(int i=0;i<n;i++){
        B[A[word[i] - 'a'] - 1] = word[i];
        A[word[i] - 'a']--;
    }
    B[n] = '\0';
    string str(B);
    delete[] A;
    delete[] B;
    return str;
}

vector<string> anagrams(vector<string>& strs){
    vector<string> res;
    int n = strs.size();
    if(n==0)    return res;
    multimap<string, int> mmp;  //pair(key of word, index in strs)
    set<string>    keys;        //save key of word
    for(int i=0;i<n;i++){
        string kstr = wordkey(strs[i]);
        keys.insert(kstr);
        mmp.insert(pairType(kstr, i));
    }
    
    for(set<string>::iterator kIter = keys.begin(); kIter != keys.end(); ++kIter){
        if(mmp.count(*kIter) == 1)    continue;
        pair<iterType, iterType> ret = mmp.equal_range(*kIter);   //(lowerbound, upperbound) multimap::equal_range()
        for(iterType vIter = ret.first; vIter != ret.second; ++vIter){
            res.push_back(strs[vIter->second]);
        }
    }
    return res;
}

void showVector(const vector<string>& vec){
    int n = vec.size();
    for(int i =0;i<n;i++){
        printf("%s, ", vec[i].c_str());
    }
    printf("\n");
}

void test_01(){        //test wordkey()
    string str;
    while(1){
        printf("please word to sort in char:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        printf("sorted: %s\n", wordkey(str).c_str());
    }
}

void test_02(){       //test anagrams()
    string str;
    while(1){
        printf("please input word list:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        vector<string> vec = splitStr2Vector(str);
        vector<string> res = anagrams(vec);
        showVector(res);
    }
}

int main(int, char**){
    test_02();
    return 0;
}
