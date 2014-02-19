/*
 * given numRows, generate the first numRows of Pascal's triangle
 * e.g. given nRows=5, return below:
 * 1
 * 1,1
 * 1,2,1
 * 1,3,3,1
 * 1,4,6,4,1
 * */

#include "stdio.h"
#include <iostream>
#include <string>
#include <vector>
#include "stdlib.h"

using namespace std;

vector<vector<int> > generate(int nRows){
    vector<vector<int> > res;
    if(nRows < 1)    return res;
    vector<int> arr0;
    arr0.push_back(1);
    res.push_back(arr0);
    for(int i=1;i < nRows;++i){
        vector<int> vec;
        vec.push_back(res[i-1][0]);
        for(int j=1;j<i;++j){
            vec.push_back(res[i-1][j-1] + res[i-1][j]);
        }
        vec.push_back(res[i-1][i-1]);
        res.push_back(vec);
    }
    return res;
}

void show(const vector<vector<int> >& tri){
    int n=tri.size();
    for(int i=0;i<n;++i){
        for(size_t j=0;j<tri[i].size();++j){
            printf("%d ", tri[i][j]);
        }
        printf("\n");
    }
}

int main(int, char**){
    string str;
    while(1){
        printf("please input the numRows:\n");
        if(getline(cin, str)==0 || str.empty())
          break;
        int n = atoi(str.c_str());
        show(generate(n));
    }
    return 0;
}
