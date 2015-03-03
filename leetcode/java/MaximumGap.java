/*
 * given a unsorted array, find the maximum gap between the successive elements in its sorted form.
 * try to solve it in time O(n) and space O(n)
 *
 * */
import java.io.*;
import java.lang.Math;

public class MaximumGap{
    public int maximumGap_01(int[] num){
        int maxGap = 0, n = num.length;
        if(n < 2)   return maxGap;

        int min = num[0], max = num[0];
        for(int i = 0; i < n; i++){
            min = Math.min(min, num[i]);
            max = Math.max(max, num[i]);
        }

        /// divide into identical gaps
        boolean[] Engaged = new boolean[n - 1];
        double gap = (double)(max - min) / (double)(n - 1);

        /// assign maximum and minimum for each gap
        Gap[] gaps = new Gap[n - 1];
        for(int i = 0; i < n - 1; i++){
            gaps[i] = new Gap();
        }
        for(int i = 0; i < n; i++){
            int idx = Math.min(
                    (int)Math.floor((double)(num[i] - min) / gap),  n-2);
            Engaged[idx] = true;

            /// lower bound
            if(gaps[idx].low == -1){
                gaps[idx].low = num[i];
            }else{
                gaps[idx].low = Math.min(gaps[idx].low, num[i]);
            }

            /// upper bound
            if(gaps[idx].high == -1){
                gaps[idx].high = num[i];
            }else{
                gaps[idx].high = Math.max(gaps[idx].high, num[i]);
            }
        }

        /// scan gaps
        int lastEngaged = -1;
        while(Engaged[++lastEngagaed])    break;
        for(int i = lastEngaged; i < n - 1; i++){
            if(Engaged[i]){
                maxGap = Math.max(gaps[i].high - gaps[i].low, maxGap); // inner gap
                if(lastEngaged < i){  // inter gap maxGap
                    maxGap = Math.max(gaps[i].low - gaps[lastEngaged].high, maxGap);
                }
                lastEngaged = i;
            }
        }

        return maxGap;
    }

    class Gap{
        int low;
        int high;
        Gap(){
            low = -1;
            high = -1;
        }
        Gap(int x, int y){
            low  = x;
            high = y;
        }
    }
}
