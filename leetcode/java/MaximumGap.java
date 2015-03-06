/*
 * given a unsorted array, find the maximum gap between the successive elements in its sorted form.
 * try to solve it in time O(n) and space O(n)
 *
 * */
import java.io.*;
import java.lang.Math;

public class MaximumGap{
    public int maximumGap(int[] num){
        int maxGap = 0, n = num.length;
        if(n < 2)   return maxGap;

        int min = num[0], max = num[0];
        for(int i = 0; i < n; i++){
            min = Math.min(min, num[i]);
            max = Math.max(max, num[i]);
        }

        /// divide into identical bucks
        boolean[] Engaged = new boolean[n - 1];
        double gap = (double)(max - min) / (double)(n - 1);

        /// assign maximum and minimum for each gap
        Buck[] bucks = new Buck[n - 1];
        for(int i = 0; i < n - 1; i++){
            bucks[i] = new Buck();
        }
        for(int i = 0; i < n; i++){
            int idx = Math.min(
                    (int)Math.floor((double)(num[i] - min) / gap),  n-2);
            Engaged[idx] = true;
            /// lower bound
            if(bucks[idx].low == -1){
                bucks[idx].low = num[i];
            }else{
                bucks[idx].low = Math.min(bucks[idx].low, num[i]);
            }
            /// upper bound
            if(bucks[idx].high == -1){
                bucks[idx].high = num[i];
            }else{
                bucks[idx].high = Math.max(bucks[idx].high, num[i]);
            }
        }
        /// scan bucks
        int lastEngaged = -1;
        while(Engaged[++lastEngaged])    break;
        for(int i = lastEngaged; i < n - 1; i++){
            if(Engaged[i]){
                maxGap = Math.max(bucks[i].high - bucks[i].low, maxGap); // inner buck
                if(lastEngaged < i){  // inter bucks
                    maxGap = Math.max(bucks[i].low - bucks[lastEngaged].high, maxGap);
                }
                lastEngaged = i;
            }
        }
        return maxGap;
    }

    class Buck{  // inner class(private)
        int low;
        int high;
        Buck(){
            low = -1;
            high = -1;
        }
        Buck(int x, int y){
            low  = x;
            high = y;
        }
    }
}
