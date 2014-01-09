/*
 * from oj.leetcode. 
 * given an integer array for which the ith element is price of a given stock on day i, find solution to get maximum benefit when for at most two transactions
 * obviously, the basic solution is in time O(n^2)
 * 
 * test data:
 * 1,2,4,2,5,7,2,4,9,0          ----- max profit is 6+7=13
 * [1,3], [2,4], [2,6], [2,7]   ----- max profit is 5+5=10
 * */
#include "../header/preliminary.h"
#include <queue>
#include <vector>

/*
 * this solution looks concise but not correct which misses case of transaction merge
 * */
inline int max(int a, int b){
    return a>b ? a: b;
}
inline int min(int a, int b){
    return a<b ? a: b;
}
int twicebuysell_wrong(vector<int>& prices){
    int n = prices.size();
    if(n<2)    return 0;
    int buy=0, sell=0, top1=0, top2=0, sum=0;
    for(int i=1;i<=n;++i){        //1. in linear traverse, keep top2 transaction profit till now 2.merge clause of i==n 
        if(i==n || prices[i] < prices[i-1]){
            if(sell == buy)    continue;
            int tmp = prices[sell] - prices[buy];
            buy = sell;
            if(top1==0){
                sum += tmp;
                top1 = tmp;
            }else if(top2==0){
                sum += tmp;
                top2 = min(top1, tmp);
                top1 = max(top1, tmp);
            }else if(tmp > top2){
                sum += tmp - top2;
                top2 = min(top1, tmp);
                top1 = max(top1, tmp);
            }
        }else if(prices[i] > prices[i-1]){
            if(buy == sell){
                buy = i-1;
            }
            sell = i;
        }
    }
    return sum;
}

/*
 * correct solution below
 * */
vector<int*> scanprices(vector<int>& prices){    //scan price array to get transaction array 
    vector<int*> transactions;
    int n = prices.size();
    if(n<2)        return transactions;
    int buy=0, sell=0;
    for(int i=1;i<=n;++i){
        if(i==n || prices[i] < prices[i-1]){
            if(sell > buy){
                int* tr = new int[2]();
                tr[0] = prices[buy];
                tr[1] = prices[sell];
                transactions.push_back(tr);
                buy = sell;
            }
        }else if(prices[i] > prices[i-1]){
            if(buy == sell){
                buy = i-1;
            }
            sell = i;
        }
    }
    return transactions;
}

int oncetransaction(vector<int*>& trans, int b, int e){    //get max profit in once transaction among trans[b] to trans[e]
    if(e < b)        return 0;
    int buy = trans[b][0], profit = trans[b][1] - trans[b][0];
    for(int i=b+1;i<=e;++i){
        if(trans[i][0] < buy){
            buy = trans[i][0];
        }
        int tmp = trans[i][1] - buy;
        if(profit < tmp){
            profit=tmp;
        }
    }
    return profit;
}

/*
 * this uses dynamic programming, total in time O(n^3), very bad for twice transaction, maybe optional for 3+ transactions 
 * */
int twicebuysell(vector<int>& prices){
    vector<int*> trans = scanprices(prices);
    int n = trans.size(), sum=0;
    if(n<=2){
        for(int i=0;i<n;++i){
            sum += trans[i][1] - trans[i][0];
        }
        return sum;
    }
    
    int **dp = new int*[n];    //dp[i][j] means among transaction[i...j], the max profit for once transaction
    for(int i=0;i<n;++i){
        dp[i] = new int[n]();
    }
    for(int i=0;i<n;++i){
        dp[i][i] = trans[i][1] - trans[i][0];
    }
    
    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j){
            dp[i][j] = oncetransaction(trans, i, j);
        }
    }
    sum=0;
    for(int i=0;i<n-1;++i){
        int tmp = dp[0][i] + dp[i+1][n-1];
        if(sum < tmp)
          sum=tmp;
    }
    for(int i=0;i<n;++i){
        delete[] dp[i];
        dp[i]=0;
    }
    delete[] dp;
    dp=0;
    trans.clear();
    return sum;
}

/*
 * basic solution in time O(n^2)
 * */
int twicebuysell_02(vector<int>& prices){
    vector<int*> trans = scanprices(prices);
    int n = trans.size(), sum=0;
    if(n<=2){
        for(int i=0;i<n;++i){
            sum += trans[i][1] - trans[i][0];
        }
        return sum;
    }
    for(int i=0;i<n-1;++i){
        int tmp = oncetransaction(trans, 0, i) + oncetransaction(trans, i+1, n-1);
        if(sum < tmp){
            sum = tmp;
        }
    }
    return sum;
} 

/*
 * solution 3 in time O(n), should be the best.
 * it analyze the problem of once transaction and find: when traverse, prices[i] will affect result in two ways: 
 * 1. it is lower than historical lowest(valley), so it should be bid moment
 * 2. selling at it will get more profit
 * think of the twice transaction problem in forward and backfward separately!!!
 * */
int twicebuysell_03(vector<int>& prices){
    int n=prices.size();
    if(n<2)        return 0;
    int *historyprofit = new int[n]();
    int *futureprofit  = new int[n]();
    int valley=prices[0], peak=prices[n-1], sum=0;
    for(int i=1;i<n;++i){
        if(valley > prices[i]){
            valley = prices[i];
        }
        historyprofit[i] = max(historyprofit[i-1], prices[i]-valley);
    }
    for(int i=n-2;i>=0;--i){
        if(peak < prices[i]){
            peak = prices[i];
        }
        futureprofit[i] = max(futureprofit[i+1], peak - prices[i]);
        int tmp = historyprofit[i] + futureprofit[i];
        if(sum < tmp)
          sum=tmp;
    }
    delete[] historyprofit;
    delete[] futureprofit;
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

        vector<int> vec;
        for(int i=0;i<n;++i){
            vec.push_back(arr[i]);
        }
        printf("if permit at most two transactions, the max profit is %d\n", twicebuysell_03(vec));

        delete[] arr;
        arr=0;
    }
    return 0;
}
