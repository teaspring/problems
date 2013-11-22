/*
* problem on Nov19
* given two string, one as source, another as pattern. please find count of pattern appearance in source string
* 
* test data:
* src("abbbc"), pattern("abc"), count is 3
* src("abbcabccb"), pattern("abc"), count is 10
*/
#include "stdio.h"
#include <iostream>
#include <string>
#include <set>

using namespace std;

/*
 * recurse
 * */
void findsubchar(set<int>* pSet, int m, int* seq, int& k, int& count){
    if(k==m){
        ++count;
        for(int i=0;i<m;i++){
            printf("%d ", seq[i]);
        }
        printf("\n");
        return;
    }
    int a = seq[k-1];
    set<int>::const_iterator iter = pSet[k].begin();
    for(;iter != pSet[k].end();iter++){
        if(*iter > a){
            seq[k++] = *iter;
            findsubchar(pSet, m, seq, k, count);
            seq[--k] = -1;
        }
    }
    return;
}

int findsubseqs(const string& src, const string& pat){
    int count=0;
    int m = pat.size();
    set<int>* pSet = new set<int>[m];
    for(size_t i=0;i<src.size();i++){
        for(size_t j=0;j<pat.size();j++){
            if(src[i] == pat[j]){
                pSet[j].insert(i);
            }
        }
    }
    int i =0;
    int* seq = new int[m]();
    set<int>::const_iterator iter = pSet[0].begin();
    for(;iter != pSet[i].end();iter++){
        seq[i++] = *iter;
        findsubchar(pSet, m, seq, i, count);
        seq[--i] = -1;
    }
    delete[] pSet;
    pSet = 0;
    return count;
}

int main(int argc, char* argv[]){
    string src, pat;
    while(1){
        if(getline(cin, src)==0 || src.empty()){
            break;
        }
        if(getline(cin, pat)==0 || pat.empty()){
            break;
        }
        int res = findsubseqs(src, pat);
        printf("sub sequence count is %d\n", res);
    }
    return 0;
}
