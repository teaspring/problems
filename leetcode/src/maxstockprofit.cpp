/*
 * Best Time to Buy and Sell Stock
 * III.Given an array for which the ith element is the price of a given stock on day i. Find the maximum profit with at most two transactions
 * test data: 
 * gas{1,2,3,4,5}, cost{3,4,5,1,2}
 * */
#include "../include/preliminary.h"
using namespace std;

int maxProfitIII(const vector<int> &prices){
    int n = prices.size();
    if(n<2)        return 0;
    int *historyprofit = new int[n]();
    int *futureprofit = new int[n]();
    int valley = prices[0], peak = prices[n-1], sum=0;
    for(int i=1;i<n;++i){
        valley = min(valley, prices[i]);
        historyprofit[i] = max(historyprofit[i-1], prices[i]-valley);
    }

    for(int i=n-2;i>=0;--i){
        peak = max(peak, prices[i]);
        futureprofit[i] = max(futureprofit[i+1], peak - prices[i]);
        sum = max(sum, historyprofit[i] + futureprofit[i]);  //max twice transactions, which means once transaction is accepted
    }
    delete[] historyprofit;
    historyprofit = 0;
    delete[] futureprofit;
    futureprofit=0;
    return sum;
}

int main(int, char**){
    string str;
    while(1){
        printf("please input prices[]:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        vector<int> prices;
        for(int i=0;i<n;++i){
            prices.push_back(arr[i]);
        }
        printf("the maxprofitIII is %d\n", maxProfitIII(prices));
        delete[] arr;
        arr=0;
    }
    return 0;
}

