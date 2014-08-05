/*
 * given n non-negative integers representing the histogram's bar height where the width of each is 1, find area of
 * largest rectangle in the histogram
 *
 * e.g. {2,1,5,6,2,3}, output 5*2=10
 * */
import java.io.*;
import java.util.*;

public class largestRectangleArea{
    public int largest(int[] height){
        int n = height.length, res = 0;
        if(n==0)    return res;
        Stack<Integer> stk = new Stack<Integer>();  // store index
        for(int i=0; i<=n; i++){  // append one more bar of 0 to merge the final process
            int h = i==n ? 0 : height[i];
            while(!stk.isEmpty()){
                int p = stk.peek();
                if(height[p] < h)    break;
                stk.pop();
                int start = stk.isEmpty() ? -1 : stk.peek();
                res = Math.max(res, (i - 1 - start) * height[p]);
            }
            stk.push(i);
        }
        return res;
    }
}

