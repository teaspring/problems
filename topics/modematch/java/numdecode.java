/*
 * from oj.leetcode. A message containing letters from A-Z is being encoded to numbers using 'A'-1, 'B'-2,...'Z'-26. given an encoded
 * message containing digits, determine the total number of ways to decode it.
 * 
 * test data:
 * 1010101010101010
 * 2525225
 *
 * Post think:
 * 1. for such problem of string split, if asking for optional composition count, it should use DP instead of recurse
 * 2. if asking for all composition output, recurse with stack is always needed
 * */
import java.io.*;
import java.util.*;

public class numdecode{
    public int numDecodings_01(String s){
        if(s == null || s.isEmpty())    return 0;
        int[] grps = getGroups_04(s);
        return decodePath_04(grps, 0, s.length());
    }
    
    /*
     * abandoned methods with overused structure and worse efficiency
     * */
    private ArrayList<ArrayList<Integer>> getGroups_01(String s){
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        final int n = s.length();
        for(int i=0;i<n;++i){
            ArrayList<Integer> curr = new ArrayList<Integer>();
            for(int j=i+1;j<=n && j<=i+2; ++j){
                int tmp = new Integer(s.substring(i,j));
                if(tmp > 26 || tmp<1 || (tmp<10 && j-i > 1))    continue;
                curr.add(tmp);
            }
            res.add(curr);
        }
        return res;
    } 
    private int decodePath_01(ArrayList<ArrayList<Integer>> groups, int ind, int n){
        if(ind==n)    return 1;
        if(ind>n || ind<0)    return 0;
        ArrayList<Integer> curr = groups.get(ind);
        if(curr.isEmpty())    return 0;
        int sum=0;
        for(int i : curr){
            sum += (i>9 ? decodePath_01(groups, ind+2, n) : decodePath_01(groups, ind+1, n));
        }
        return sum;
    }

    /*
     * 1.reverse scan from tail
     * 2.return int[n][2], [i][1]==1 means substr[i,i+2) is valid encoded number, 0 means invalid for substr[i,i+2) 
     * */
    private int[][] getGroups_02(String s){
        final int n = s.length();
        int[][] res = new int[n][2];
        for(int end=n; end>0; --end){
            /* below statement is not needed, because here for substr ends at [end] exclusively, it can skip [end] if it >10 */
            //if(end<n && res[end][0]==0 && res[end][1]==0)    continue;
            for(int start=end-1; start >= end-2 && start>=0; --start){
                int tmp = new Integer(s.substring(start, end));
                if(tmp>26 || tmp<1 || (tmp<10 && end-start > 1))    continue;
                if(tmp<10)      res[start][0]++;
                else            res[start][1]++;
            }
        }
        return res;
    }

    /*
     * rework based on decodePath_01()
     * but this caused Time Limit Exceeded error for test case of large input 
     * @params: int[n][2] groups
     * */
    private int decodePath_02(int[][] groups, int ind, int n){
        for(;ind<n;++ind){
            if(groups[ind][1]==1){
                return decodePath_02(groups, ind+1, n) + decodePath_02(groups, ind+2, n);
            }else if(groups[ind][0]==1){
                continue;
            }
            break;
        }
        if(ind==n)    return 1;
        else return 0;
    }

    /*
     * optimize decodePath_02(), used DP instead of recurse!
     * @params: int[n][2] groups
     * */
    private int decodePath_03(int[][] groups, int ind, final int n){
        if(groups[0][0] + groups[0][1]==0)    return 0;
        int[] dp = new int[n+1];
        dp[0] = 1;
        for(int i=1;i<=n;++i){
            if(i<n && groups[i][0] + groups[i][1] == 0){
                dp[i] = 0;
                continue;
            }
            if(groups[i-1][0]==1)           dp[i] += dp[i-1];
            if(i>1 && groups[i-2][1]==1)    dp[i] += dp[i-2];
        }
        return dp[n];
    }

    /*
     * simplify and optimize getGroups_03(), return int[n].basis: res[i]=1 means it only support number <10, if 2, it support >10 as well
     * return like 11112122010
     * */
    private int[] getGroups_04(String s){
        final int n = s.length();
        int[] res = new int[n];
        for(int end=n; end>0; --end){
            for(int start=end-1; start >= end-2 && start>=0; --start){
                int tmp = new Integer(s.substring(start, end));
                if(tmp>26 || tmp<1 || (tmp<10 && end-start > 1))    continue;
                res[start]++;
            }
        }
        return res;
    }
    /*
     * optimize decodePath_03(), based on int[n]
     * */
    private int decodePath_04(int[] groups, int ind, final int n){
        if(groups[0]==0)    return 0;
        int[] dp = new int[n+1];
        dp[0] = 1;
        for(int i=1;i<=n;++i){
            if(i<n && groups[i] == 0){
                dp[i] = 0;
                continue;
            }
            if(groups[i-1]>0)           dp[i] += dp[i-1];
            if(i>1 && groups[i-2]>1)    dp[i] += dp[i-2];
        }
        System.out.println("dp[] is : " + Arrays.toString(dp));
        return dp[n];
    }

    /*
     * copy from Discussion of oj.leetcode. the simplest solution, once iteration, constant space, certainly the best!
     * use two variables for DP 
     * */
    public int numDecodings_02(String s){
        if(s==null || s.isEmpty() || s.charAt(0)=='0')        return 0;
        int cur_2=1, cur_1=1, cur=0;
        for(int i=2; i<=s.length(); i++){    //cur_2 is count in front of [i-2], cur_1 is count in frout of [i-1]
            if(s.charAt(i-1) != '0')    cur += cur_1;
            if(s.charAt(i-2)=='1' || (s.charAt(i-2)=='2' && s.charAt(i-1)<'7'))    cur += cur_2;
            cur_2 = cur_1;
            cur_1 = cur;
            cur=0;
        }
        return cur_1;
    }

    public void test(){
        Scanner scan = new Scanner(System.in);
        while(true){
            String str = scan.nextLine();
            System.out.println(numDecodings_02(str));
            if(str.isEmpty())    break;
        }
    }
    public static void main(String[] args){
        numdecode nd = new numdecode();
        nd.test();    
    }
}
