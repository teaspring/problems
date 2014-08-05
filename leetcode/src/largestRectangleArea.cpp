/*
 * given n non-negative integers representing the histogram's bar height where the width of each is 1, find area of
 * largest rectangle in the histogram
 *
 * e.g. {2,1,5,6,2,3}, output 5*2=10
 * */

#include "../header/preliminary.h"

int largestRectangleArea_01(const vector<int>& height){   // time limit error for array with extreme peak
    int n = height.size();
    int res = n == 0 ? 0 : height[0];
    if(n==0 || n==1)    return res;
    int m = 0;
    for(int i=0; i<n; i++)    m = max(m, height[i]);    // m is the height of highest bar
    /*
    int dp[n][m+1];        memset(dp, 0, sizeof(dp));  // time O(n^2), space O(n^2)
    for(int j=1; j<=height[0]; j++)    dp[0][j] = 1;
    for(int i=1; i<n; i++){
        for(int j=1; j<=height[i]; j++){
            dp[i][j] = 1 + dp[i-1][j];
            res = max(res, j * dp[i][j]);
        }
    }
    */
    int dp[m+1];                                   // time O(n^2), space O(n)
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<n; i++){
        for(int j=1; j<=height[i]; j++){
            if(i==0 || dp[j] == 0){
                dp[j] = 1;
            }else{
                dp[j] += 1;
            }
            res = max(res, j * dp[j]);
            memset(dp + height[i] + 1, 0, sizeof(int) * (m+1 - height[i]));
        }
    }
    return res;
}

/*
 * time O(n) and space O(n)
 * */
int largestRectangleArea_02(const vector<int>& height){
    int n = height.size(), res = 0;
    if(n == 0)    return res;
    stack<int> stk;           // store index
    for(int i=0; i<=n; i++){  // elegance in appending one bar of 0 to merge the final process following for-loop
        int h = i == n ? 0 : height[i];
        while(!stk.empty()){
            int p = stk.top();
            if(height[p] < h)    break;
            stk.pop();
            int start = stk.empty() ? -1 : stk.top();
            res = max(res, (i - 1 - start) * height[p]);
        }
        stk.push(i);
    }
    return res;
}

void test_01(){
    int h[] = {2,1,3,1,4,2};
    vector<int> height(h, h + sizeof(h)/sizeof(int));
    cout << largestRectangleArea_02(height) << endl;
}

void test_02(){
    int h[] = {2,1,5,6,2,3};
    vector<int> height(h, h + sizeof(h)/sizeof(int));
    cout << largestRectangleArea_02(height) << endl;
}

void test_03(){
    int h[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11};
    vector<int> height(h, h + sizeof(h)/sizeof(int));
    cout << largestRectangleArea_02(height) << endl;
}

int main(){
    test_01();
    test_02();
    test_03();
    return 0;
}

