/* 
 * Best Time to Buy and Sell Stock
 * given an array for which the ith element is the price of given stock on day i.
 * III.find the maximum profit with at most two transactions
 * */
import java.io.*;
import java.util.*;

public class maxstockprofit{
    private int min(int a, int b){
        return a<b ? a:b;
    }
    private int max(int a, int b){
        return a>b ? a:b;
    }

    public int maxProfitIII(ArrayList<Integer> prices){
        int n = prices.size();
        if(n<2)        return 0;
        int[] historyprofit = new int[n];
        int[] futureprofit = new int[n];
        int valley = prices.get(0), peak = prices.get(n-1), sum=0;
        for(int i=1;i<n;++i){
            int pr = prices.get(i);
            valley = min(valley, pr);
            historyprofit[i] = max(historyprofit[i-1], pr - valley);
        }
        for(int i=n-2;i>=0;--i){
            int pr = prices.get(i);
            peak = max(peak, pr);
            futureprofit[i] = max(futureprofit[i+1], peak - pr);
            sum = max(sum, historyprofit[i] + futureprofit[i]);  //at most twice transactions, may degrade to once
        }
        return sum;
    }
    
    public static void main(String[] args){
        return;
    }
}
