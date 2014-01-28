/*
 * given an unsorted array of integers, find length of the longest consecutive elements sequence. implement it in time O(n)
 * */
import java.io.*;
import java.util.*;

public class longestConsecutive{
    /*
     * very smart and sophiscated structure design
     * */
    public int longestconsecutivesequence(int[] num){
        HashMap<Integer, Integer> mp = new HashMap<Integer, Integer>();    //Collection<Integer...>
        int maxlen = 1;
        int n = num.length;
        for(int i=0;i<n;i++){
            if(mp.containsKey(num[i]))    continue;
            mp.put(num[i], 1);
            int leftbound = 0;
            if(mp.containsKey(num[i]-1))    leftbound = mp.get(num[i]-1);
            int rightbound = 0;
            if(mp.containsKey(num[i]+1))    rightbound = mp.get(num[i]+1);
            int sum = 1 + leftbound + rightbound;
            mp.put(num[i]-leftbound, sum);
            mp.put(num[i]+rightbound, sum);
            if(sum > maxlen){
                maxlen = sum;
            }
        }
        return maxlen;
    }
    
    public int[] splitStr2IntArray(String str, String delimeters){
        StringTokenizer t = new StringTokenizer(str, delimeters);
        int[] arr = new int[t.countTokens()];
        for(int i=0;t.hasMoreTokens();i++){
            arr[i] = Integer.parseInt(t.nextToken().toString());
        }
        return arr;
    }
    public void test(){
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.println("input integer array:");
            String str = scan.nextLine().trim();
            if(str.isEmpty())    break;
            int[] num = splitStr2IntArray(str, " ,");
            System.out.println("length of longest consecutive sequence is " + longestconsecutivesequence(num));
        }
    }
    public static void main(String[] args){
        longestConsecutive lc = new longestConsecutive();
        lc.test();
    }
}
