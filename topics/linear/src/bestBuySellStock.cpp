/*
 * from oj.leetcode. 
 * given an integer array for which the ith element is price of a given stock on day i, find solution to get maximum benefit for below constraints:
 * 1). if you were only permitted to buy one share and sell one share
 * 2). if you can keep buying and selling
 *
 * obviously, the brute force in time O(n^2).we have to find a better solution
 * 
 * test data:
 * 2,1,3,5,4,0,6.  b-0, s-6
 * 2,1,3,5,4,0,1.  b-1, s-5
 * 6,5,4,3,2,1.    no buy-sell solution at all
 * */
#include "../header/preliminary.h"
#include <queue>
#include <vector>

/*
 * Problem 1: time O(n), memory O(1)
 * */
int bestbuysellstock(const int *A, int n, int& buy, int& sell){
    int low = 0, sum = 0;
    buy = sell = 0;
    for(int i = 1; i < n; ++i) {
        if(A[i] < A[low]){
            low = i;
        } else {
            int diff = A[i] - A[low];
            if(sum < diff){
                sum = diff;
                buy = low;
                sell = i;
            }
        }
    }
    return sum;
}

/*
 * Problem 2: no limit of buying and selling counts
 * */
int keepbuysellstock(int *A, int n){
    int sum = 0;
    for(int i = 1; i < n; ++i){
        if(A[i] >= A[i-1]) {
            sum += A[i] - A[i-1]; // every increasing days counts
        }
    }
    return sum;
}

int main(int, char**){
    string str;
    while(1){
        cout<<"please input integer array of stock price:"<<endl;
        if(getline(cin, str)==0 || str.empty())
          break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        printf("the max profit is %d\n", keepbuysellstock(arr, n));

        delete[] arr;
        arr=0;
    }
    return 0;
}
