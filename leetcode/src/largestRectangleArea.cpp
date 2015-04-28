/*
 * given n non-negative integers representing the histogram's bar height where the width of each is 1, find area of
 * largest rectangle in the histogram
 *
 * e.g. {2,1,5,6,2,3}, output 5*2=10
 * */

#include <cstring>
#include <cmath>
#include <vector>
#include <stack>

using namespace std;

class Solution{
public:
    /*
     * time O(n^2), space O(n)
     * */
    int largestRectangleArea_1(const vector<int>& height){   // time limit error for array with extreme peak
        int n = height.size();
        int res = n == 0 ? 0 : height[0];
        if(n==0 || n==1)    return res;
        int m = 0;
        for(int i=0; i<n; i++)    m = max(m, height[i]);    // m is the height of highest bar

        int dp[m+1];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n; i++){
            for(int j = 1; j <= height[i]; j++){
                if(i == 0 || dp[j] == 0){
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
    int largestRectangleArea_2(const vector<int>& height){
        if(height.empty())    return 0;

        const int n = height.size();
        int res = 0;
        stack<int> stk;  // store index

        for(int i = 0; i <= n; i++){  // elegent to merge the tailer process inside for-loop
            int h = (i == n ? 0 : height[i]);
            while(!stk.empty()){
                int p = stk.top();
                if(height[p] < h)    break;

                stk.pop();  // area of any height is calculated when it is poped
                int start = stk.empty() ? -1 : stk.top(); // start is exclusive begin
                res = max(res, (i - 1 - start) * height[p]);
            }
            stk.push(i);
        }
        return res;
    }
};

/* unit test is in ../cpp_unittest/largestRectangleArea_unittest */
