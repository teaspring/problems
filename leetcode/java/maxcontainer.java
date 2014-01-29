/*
 * given n non-negative integers a1,a2...an, where each represents a point at coordicate (i,ai). n vertical lines are drawn such that the
 * two endpoints of the line i is at (i, ai) and (i,0). Find two lines, which together with x-axis forms a container, such that the 
 * container contains the most water
 * */
import java.io.*;
import java.util.*;

public class maxcontainer{
    public int maxArea(int[] height){
        int s=0, e=height.length-1;
        int area = 0;
        while(s<e){
            int tmp = min(height[s], height[e]) * (e-s);
            if(area < tmp)        area=tmp;
            if(height[s] < height[e]){
                s++;
                while(s<e && height[s] <= height[s-1])    s++;  //skip hopeless points
            }else{
                e--;
                while(s<e && height[e] <= height[e+1])    e--;  //skip hopeless points
            }
        }
        return area;
    }

    public static void main(String[] args){
        return;
    }
}

