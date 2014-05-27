/*
 * problem I:
 * given a set of distinct integers S,  return all possible subsets.
 * e.g. S = [1,2,3]
 * output: 
 * [], [1], [1,2], [1,2,3], [1,3], [2], [2,3], [3] 
 *
 * problem II:
 * given a set with duplicate integers
 * e.g. S = [1,2,2]
 * output:
 * [], [1], [1,2], [1,2,2], [2], [2,2]
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include "stdlib.h"
using namespace std;

/*
 * for problem I that S of distinct integers
 * */
void helper(const vector<int>& src, int i, vector<int>& pipe, vector<vector<int> >& res){
    if(i<0)     return;
    res.push_back(pipe);
    int n = src.size();
    if(i==n)    return;
    for(; i<n; ++i){
        pipe.push_back(src[i]);
        helper(src, i+1, pipe, res);
        pipe.pop_back();
    }
    return;
}

vector<vector<int> > subsets(vector<int>& S){
    sort(S.begin(), S.end());
    vector<vector<int> > result;
    vector<int> pipe;
    helper(S, 0, pipe, result);
    return result;
}

/*
 * for problem II that S with duplicate integers
 * */
vector<int> index2Value(const vector<int>& src, const vector<int>& indexes){
    vector<int> values;
    for(size_t i=0; i < indexes.size(); ++i){
        values.push_back(src[indexes[i]]);
    }
    return values;
}

void helper_II(const vector<int>& src, int i, vector<int>& vec, vector<vector<int> >& res){
    res.push_back(index2Value(src, vec));
    int n = src.size();
    for(; i<n; ++i){
        int m = vec.size();
        if(i>0 && (m==0 || i > vec[m-1] + 1) && (src[i-1] == src[i]))        continue;
        vec.push_back(i);        // vec to save index of src instead of value
        helper_II(src, i+1, vec, res);
        vec.pop_back();
    }
}

vector<vector<int> > subsets_II(vector<int>& S){
    sort(S.begin(), S.end());
    vector<vector<int> > result;
    vector<int> vec;

    helper_II(S, 0, vec, result);
    return result;
}

/*****************test****************/
void output(const vector<vector<int> >& res){
    for(size_t i=0; i<res.size(); ++i){
        printf("[");
        if(res[i].size() > 0){
            printf("%d", res[i][0]);
        }
        for(size_t j=1; j<res[i].size(); ++j){
            printf(", %d", res[i][j]);
        }
        printf("]\n");
    }
    return;
}

void test_01(){
    string str;
    while(1){
        printf("please input integer between 1 and 9:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        int n = atoi(str.c_str());
        
        vector<int> S;
        for(int i=0; i<n; ++i){
            S.push_back(n-i);
        }
        output(subsets(S));
    }
}

void test_02(){
    int a[] = {1,2,2,2,1};
    vector<int> S(a, a + sizeof(a)/sizeof(int));
    output(subsets_II(S));
}

int main(int, char**){
    test_02();
    return 0;
}
