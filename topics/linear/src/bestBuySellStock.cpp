/*
 * from leetcode. 
 * 
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

/*
 * problem 1, solution 1:
 * deque is good structure for this problem: only one element(lower) at head and one(higher) at tail need to consider
 * in time O(n), space O(n)
 * disadvantage: deque store elements all time, but only the one at front and back possible useful. this structure is overused absolutely
 * */
int bestbuysellstock01_01(const int *A, int n, int& buy, int& sell){
    if(n<2)        return 0;
    deque<int> q;    //store index of price
    for(int i=0;i<n;++i){
        if(q.empty()){
            q.push_back(i);
        }else if(A[i] < A[q.front()]){  //store index of lower price in front
            q.push_front(i);
        }else if(A[i] > A[q.back()]){   //store index of higher price in back
            if(q.size() > 1){   //pop abandoned potential sell price
                q.pop_back();
            }
            q.push_back(i);
        }
    }

    while(q.size() > 2 && q.front() > q.back()){
        q.pop_front();
    }
    if(q.back() < q.front()){    //q.back() is supposed to be later than q.front()
        return 0;            //no sell price higher than bit, no operation to do
    }
    sell = q.back();
    buy = q.front();
    q.clear();
    int res = A[sell] - A[buy];
    return res;
}

/*
 * problem 1, solution 2: mention as i traverse from left(earlier) to right(later), we just need to update index of min, and max diff
 * remain time O(n) without data strucure. 
 * */
int bestbuysellstock01_02(const int *A, int n, int& buy, int& sell){
    int min=0, maxDiff=0;
    buy = sell = 0;
    for(int i=1;i<n;++i){
        if(A[i] < A[min]){
            min = i;
        }else{
            int diff = A[i] - A[min];
            if(diff > maxDiff){
                maxDiff = diff;
                buy = min;
                sell = i;
            }
        }
    }
    return maxDiff;
}

/*
 * problem 2: if permit keep buying and selling
 * as a personal investor, this is easy. ideal solution is buying at all lowest and selling at all highest
 * */
int keepbuysellstock(int *A, int n){
    int sum=0, buy=0, sell=0;
    for(int i=1;i<n;++i){
        if(A[i] >= A[i-1]){     //increasing
            if(buy == sell){
                buy = i-1;
            }
            sell = i;
        }else{      //falling down
            if(sell > buy){
                sum += A[sell] - A[buy];
                sell = buy = i-1;
            }
        }
    }
    if(sell > buy)
        sum += A[sell] - A[buy];
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
        int b=0, s=0;
        int res = bestbuysellstock01_01(arr, n, b, s);
        cout<<"problem 1 solution 1:";
        if(res > 0){
            printf("the best solution is buy on day %d in $%d and sell on day %d in $%d, with benefite %d\n", 
                        b, arr[b], s, arr[s], res);
        }else{
            printf("no solution to buy and sell at all!\n");
        }

        b=0;
        s=0;
        res = bestbuysellstock01_02(arr, n, b, s);
        cout<<"problem 1 solution 2:";
        if(res > 0){
            printf("the best solution is buy on day %d in $%d and sell on day %d in $%d, with benefite %d\n", 
                        b, arr[b], s, arr[s], res);
        }else{
            printf("no solution to buy and sell at all!\n");
        }

        printf("problem 2:if permit keep buying and selling stock, the maximum benefite is %d\n", keepbuysellstock(arr, n));

        delete[] arr;
        arr=0;
    }
    return 0;
}
