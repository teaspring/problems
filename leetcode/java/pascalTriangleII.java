/*
 * given an index k(0-based), return kth row of the Pascal's triangle
 * e.g. k=3, return 1,3,3,1
 * */
import java.io.*;
import java.util.*;

public class pascalTriangleII{
    public ArrayList<Integer> getRow(int k){
        ArrayList<Integer> res = new ArrayList<Integer>();
        if(k<0)        return res;
        int[][] dp = new int[2][k+1];
        int last = 0;
        dp[last][0] = 1;
        for(int i=1;i<=k;i++){
            int now = 1-last;
            dp[now][0] = dp[last][0];
            for(int j=1;j<i;j++){
                dp[now][j] = dp[last][j-1] + dp[last][j];
            }
            dp[now][i] = dp[last][i-1];
            last = now;
        }
        for(int i : dp[last]){
            res.add(i);
        }
        return res;
    }

    public void test_01(){
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.println("please input k:");
            String str = scan.nextLine().trim();
            if(str.isEmpty())        break;
            int k = Integer.parseInt(str);
            System.out.println(getRow(k).toString());
        }
        return;

    }
    public static void main(String[] args){
        pascalTriangleII pt = new pascalTriangleII();
        pt.test_01();
        return;
    }
}
