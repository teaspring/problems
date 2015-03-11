/*
 * there are N children standing in a line. each child is assigned a rating value.
 * you are giving candies to these children subjected to the following requirements:
 * 1. each child must have at least 1 candy
 * 2. children with a higher rating get more than their neighnors
 * what is the minimum candies you must have?
 *
 * hidden point: 
 * for 4 4 3, the minimum candies can be 1+2+1=4
 * */
import java.io.*;
import java.util.*;

public class candy{
    public int minCandy(int[] ratings){
        int n = ratings.length;
        if(n < 2)    return n;  // 0 or 1
        int[] candies = new int[n];
        candies[0] = 1;
        int sum = 1, ki = -1;
        for(int i = 1; i < n; i++){
            if(ratings[i] == ratings[i-1]){
                if(ki > -1)    continue;  // within a decending range
                candies[i] = 1;
            }else if(ratings[i] < ratings[i-1]){
                if(ki == -1)    ki = i-1; // [i-1] is start of decending range in possible
                continue;
            }else{    // greater than preceding
                if(ki > -1){
                    sum += backtrack(ratings, ki, i-1, candies);
                    ki = -1;
                }
                candies[i] = candies[i-1] + 1;
            }
            sum += candies[i];
        }
        if(ki > -1){
            sum += backtrack(ratings, ki, n-1, candies);
        }
        return sum;
    }

    /*
     * process the decending range with backtrack, [l, r] inclusive
     *
     * note:
     * 1. candies[l] > candies[l+1], while candies[r-1] >= candies[r]
     * 2. candies[l] is set value already
     * */
    private int backtrack(int[] ratings, int l, int r, int[] candies){
        int n = ratings.length;  // ratings and candies has same size
        if(r <= l)    return 0;
        candies[r] = 1;
        int sum = 1;
        for(int i = r-1; i > l; i--){
            int tmp = (ratings[i] == ratings[i+1] ? 0 : candies[i+1]) + 1;
            candies[i] = tmp;
            sum += candies[i];
        }
        int tmp = candies[l+1] + 1;
        if(tmp > candies[l]){  // complement candies[l] if necessary
            sum += tmp - candies[l];
            candies[l] = tmp;
        }
        return sum;
    }

    /* unittest code in ../java_unittest/candy_junit/ */
    /*
    public void test(){
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.println("please input string: ");
            String s = scan.nextLine().trim();
            if(s.isEmpty())        break;
            StringTokenizer t = new StringTokenizer(s, " ,");
            int[] arr = new int[t.countTokens()];    //define int[] 
            int i = 0;
            while(t.hasMoreTokens()){
                arr[i++] = Integer.parseInt(t.nextToken());
            }
            int sum = minCandy(arr);
            System.out.println(sum);
        }
    }
    */
 }
 
