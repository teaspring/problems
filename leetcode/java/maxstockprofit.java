/* 
 * Best Time to Buy and Sell Stock
 * given an array for which the ith element is the price of given stock on day i.
 * III.find the maximum profit with at most two transactions
 * */
import java.io.*;
import java.util.*;
import java.lang.Math;

public class maxstockprofit{

    public int maxProfitIII(ArrayList<Integer> prices){
        final int n = prices.size();
        if(n < 2)    return 0;

        final Integer[] arr = prices.toArray(new Integer[0]);
        int[] historyprofit = new int[n];
        int[] futureprofit = new int[n];

        int valley = arr[0];
        for(int i = 1;i < n; ++i){
            valley = Math.min(valley, arr[i]);

            historyprofit[i] = Math.max(historyprofit[i-1], arr[i] - valley); // max profit for days [0, i]
        }

        int peak = arr[n-1], sum = 0;
        for(int i = n-2; i >= 0; --i){
            peak = Math.max(peak, arr[i]);
            futureprofit[i] = Math.max(futureprofit[i+1], peak - arr[i]); // max profit for days [i, n-1]

            // as the investment can only buy low and sell high, so he can transact sell and buy at same day[i]
            sum = Math.max(sum, historyprofit[i] + futureprofit[i]);
        }
        return sum;
    }
}

/* unit test is in ../java_unittest/maxstockprofit_junit */
