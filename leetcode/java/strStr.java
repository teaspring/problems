/*
 * implement strStr(). return a pointer to the first occurance of needle in haystack, or null.
 * solution: KMP string match algorithm
 * */
import java.io.*;
import java.util.*;

public class strStr{
    private void setPrefix(String pattern, int[] prefix){ //prefix.length == n
        final int n = pattern.length();
        prefix[0] = 0;
        for(int i=1; i<n; ++i){
            int k = prefix[i-1];
            Character ch = new Character(pattern.charAt(i));
            for(; !ch.equals(pattern.charAt(k)) && k>0; k = prefix[k-1]);
            if(ch.equals(pattern.charAt(k))){
                prefix[i] = k+1;
            }else{
                prefix[i] = 0;
            }
        }
        return;
    }

    public String strstr(String haystack, String needle){
        final int n = haystack.length();
        final int m = needle.length();
        if(m==0)    return haystack;
        if(n<m || n==0)        return null;
        int[] prefix = new int[m];
        setPrefix(needle, prefix);
        int i=0, s=0;
        boolean bfind = false;
        while(i<n){
            int k=i-s;
            Character ch = new Character(haystack.charAt(i));
            if(k<0 || (k<m && ch.equals(needle.charAt(k)))){
                ++i;
            }else if(k==m){
                bfind = true;
                break;
            }else{
                s += (k<1) ? 1 : k - prefix[k-1];
            }
        }
        if(bfind || i-s == m){
            return haystack.substring(s, n);
        }
        return null;
    }

    public void test_01(){
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.println("please input string to match in:");
            String haystack = scan.nextLine().trim();
            if(haystack.isEmpty())    break;
            System.out.println("please input pattern string:");
            String needle = scan.nextLine().trim();
            if(needle.isEmpty())    break;
            
            System.out.println(strstr(haystack, needle));
        }
        return;
    }

    public static void main(String[] args){
       strStr ss = new strStr();
       ss.test_01();
    }
}
