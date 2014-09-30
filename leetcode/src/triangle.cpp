/*
 * given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 * 2
 * 3,4
 * 6,5,7
 * 4,1,8,3
 * the answer is 2+3+5+1
 * */
#include "../include/preliminary.h"
#include <algorithm>
#include <fstream>

using namespace std;

int sumPath(const vector<vector<int> >& triangle, int* indice){
    int n = triangle.size();
    int sum=0;
    for(int i=0;i<n;++i){
        sum += triangle[i][indice[i]];
    }
    return sum;
}

void copyArray(int *src, int *dst, int n){
    for(int i=0;i<n;i++){
        dst[i] = src[i];
    }
    return;
}

/*
 * permutation of all the indice, inefficient causing Time Limit Exceed
 * */
int minimumTotal_01(vector<vector<int> >& triangle){
    int n = triangle.size();
    int *indice = new int[n]();    //start from {0,0,0,0...} the most left path
    int res = sumPath(triangle, indice);
    while(1){
        int i=n-1;
        while(i>0){
            if(indice[i] == indice[i-1]){
                indice[i]++;
                break;
            }
            --i;
        }
        if(i==0)    break;
        int k = indice[i];
        for(int j=i+1;j<n;j++){    //take care the permutation, reset the following integers eqaul to indice[i]
            indice[j] = k;
        }
        res = min(res, sumPath(triangle, indice));
    }
    delete[] indice;
    return res;
}

/*
 * correct answer from others, using DP.
 * in row [i], for column [j] where j=(0,i-1), dp[i][j] = triangle[i][j] + min(dp[i-1][j-1], dp[i-1][j]), it means current row is just dependent on last row. so define a 2-array of two rows, 
 * */
int minimumTotal_02(vector<vector<int> >& tri){
    int n = tri.size();
    int** dp = new int*[2];
    for(int i=0;i<2;i++){
        dp[i] = new int[n]();
    }
    int last = 0;
    dp[0][0] = tri[0][0];
    for(int i=1;i<n;++i){ //for row [i], the last element is column [i]
        int now = 1 - last; //rotating the two rows for use
        memset(dp[now], 0, sizeof(int)*n);
        dp[now][0] = tri[i][0] + dp[last][0];      //most left path
        dp[now][i] = tri[i][i] + dp[last][i-1];    //most right path
        for(int j=1;j<i;++j){
            dp[now][j] = tri[i][j] + min(dp[last][j-1], dp[last][j]);
        }
        last = now;
    }
    int ans = dp[last][0];
    for(int i=1;i<n;++i){
        ans = min(ans, dp[last][i]);
    }

    for(int i=0;i<2;i++){
        delete[] dp[i];
        dp[i] = 0;
    }
    delete[] dp;
    return ans;
}

void test_01(){
    vector<vector<int> > triangle;
    triangle.push_back(vector<int>());
    triangle[0].push_back(2);
    triangle.push_back(vector<int>());
    triangle[1].push_back(3);
    triangle[1].push_back(4);
    triangle.push_back(vector<int>());
    triangle[2].push_back(6);
    triangle[2].push_back(5);
    triangle[2].push_back(7);
    triangle.push_back(vector<int>());
    triangle[3].push_back(4);
    triangle[3].push_back(1);
    triangle[3].push_back(8);
    triangle[3].push_back(3);
    printf("the minimum path sum is %d\n", minimumTotal_02(triangle));
}

void test_02(){
    ifstream ifs;
    ifs.open("../testdata", ifstream::in);
    if(ifs == NULL)    return;
    vector<vector<int> > triangle;
    string str;
    while(ifs.good()){
        getline(ifs, str);
        if(str.empty())    break;
        int* arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        printf("%s ---- %d\n", str.c_str(), n);
        vector<int> vec;
        for(int i=0;i<n;i++){
            vec.push_back(arr[i]);
        }
        triangle.push_back(vec);
        delete[] arr;
        str.clear();
    }
    printf("the minimum path sum is %d\n", minimumTotal_01(triangle));
    ifs.close();
}

int main(int, char**){
    test_01();
    return 0;
}

