/*
 * there are N children standing in a line. each child is assigned a rating value.
 * you are giving candies to these children subjected to the following requirements:
 * 1. each child must have at least one candy\
 * 2. children with a higher rating get more than their neighnors
 * what is the minimum candies you must have?
 *
 * */
import java.io.*;
import java.util.*;

public class candy{
    private int minCandy(int[] ratings){
        int n = ratings.length;
        if(n==0 || n==1)    return n;
        int[] candies = new int[n];    //to structure with fixed size, Array is good choice
        candies[0] = 1;
        int sum=1, ki=-1;
        for(int i=1;i<n;i++){
            if(ratings[i] == ratings[i-1]){
                if(ki > -1){
                    candies[i] = 0;
                    continue;
                }else{
                    candies[i] = 1;
                }
            }else if(ratings[i] < ratings[i-1]){
                if(ki == -1)    ki=i-1;
                candies[i] = 0;
                continue;
            }else{    //ratings: [i] > [i-1]
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
        System.out.println(Arrays.toString(candies));
        return sum;
    }

    /*
     * In arguments, int[] cannot be modified, so it must be ArrayList<> 
     * */
    private int backtrack(int[] ratings, int l, int r, int[] candies){
        int n=ratings.length, m=candies.length;
        if(l<0 || r >= n || r >= m)        return 0;
        candies[r] = 1;
        int sum = 1;
        for(int i=r-1; i>l;i--){    //ratings: [i] >= [i+1]
            int tmp = (ratings[i] == ratings[i+1] ? 1 : candies[i+1]+1); 
            candies[i] = tmp;
            sum += candies[i];
        }
        int tmp = candies[l+1] + 1;
        if(tmp > candies[l]){
            sum += tmp - candies[l];
            candies[l] = tmp;
        }
        return sum;
    }

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

    public static void main(String[] args){
        candy cd = new candy();
        cd.test();
    }
 }
 
