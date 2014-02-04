/*
 * given a string s, partition s such that every substring of the partition is a palindrome. 
 * return the minimum cuts needed for a palindrome partition of s.
 * 
 * test data:
 * a
 * abb
 * abad
 * aaaaaaaaa
 * aaaaaaaaaaaaab
 * baaaaaaaaaaaa
 * */
import java.io.*;
import java.util.*;

public class partitionpalindromeII{
    /*
     * int time O(n^3), and it will cause Time Limit Exceed error either.
     * */
    public int minCut_01(String s){
        if(s==null || s.length()==1)    return 0;
        int n = s.length();
        int[][] mc = new int[n][n+1];    //mc[start][length] means the min cut of substring 
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=n;j++){
                mc[i][j-i] = j-i-1;
            }
        }
        for(int len=2;len<=n;len++){
            for(int end=n;end-len>=0;end--){
                if(len<4 || mc[end-len+1][len-2]==0){
                    Character ch = s.charAt(end-len);
                    if(ch.equals(s.charAt(end-1))){
                        mc[end-len][len] = 0;    //whole palindrome of length l, no cut 
                        continue;
                    }
                }
                for(int i=end-len+1;i<end;i++){
                    int tmp = mc[end-len][i-(end-len)] + mc[i][end-i] + 1;
                    if(tmp < mc[end-len][len]){
                        mc[end-len][len] = tmp;
                    }
                }
            }
        }
        return mc[0][n];
    }
    
    /*
     * get dp[][] of palindrome status of string s in time O(n^2), then find the minimum cuts in O(n^2). in total, O(n^2)
     * */
    public int minCut_02(String s){
        if(s==null || s.length()==1)    return 0;
        int n = s.length();
        boolean[][] dp = new boolean[n][n+1];    //dp[start][end] means where substring is palindrome  
        for(int i=0;i<n;++i){
            for(int j=i+1;j<=n;++j){
                dp[i][j] = false;
            }
            dp[i][i+1] = true;
        }
        for(int len=2;len<=n;++len){    //firstly, get dp[n][n+1]
            for(int end=n;end-len>=0;--end){
                if(len<4 || dp[end-len+1][end-1]==true){
                    Character ch = s.charAt(end-len);
                    if(ch.equals(s.charAt(end-1))){
                        dp[end-len][end] = true;
                    }
                }
            }
        }
        int[] mcl = new int[n+1];    //mcl[i] means min cut of substring [0, i)
        for(int i=2;i<=n;++i){
            if(dp[0][i]){
                mcl[i] = 0;
            }else{
                int in=i-2;
                for(int j=i-1;j>0;--j){  //j must start from i-1! as dp[i-1][i]==1, only at time, in can be minimized to mcl[i-1]
                    if(dp[j][i]){
                        in = min(in, mcl[j]);
                    }
                }
                mcl[i] = in+1;
            }
        }
        System.out.println("mcl[]: " + Arrays.toString(mcl));
        /*
        int[] mcr = new int[n+1];
        for(int i=n-2;i>=0;--i){    //mcr[i] means min cuts of substring [i,n)
            if(dp[i][n]){
                mcr[i] = 0;
            }else{
                int in=n-i-2;
                for(int j=i+1;j<=n;++j){  //j must start from i+1!
                    if(dp[i][j]){
                        in = min(in, mcr[j]);
                    }
                }
                mcr[i] = in+1;
            }
        }
        System.out.println("mcr[]: " + Arrays.toString(mcr));
        */
        return mcl[n];
    }

    public int min(int a, int b){
        return a<b ? a : b;
    }

    public void test(){
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.println("please input String:");
            String str = scan.nextLine().trim();
            if(str.isEmpty())        break;
            System.out.println("the min cut is " + minCut_02(str));
        }
        return;
    }

    public static void main(String[] args){
        partitionpalindromeII pp = new partitionpalindromeII();
        pp.test();
    }
}
