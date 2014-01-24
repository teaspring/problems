/*
 * given a String S, find the longest palindrome substring in it. assume the length of string is less than  1000 and there only one unique
 * result of longest palindrome substring
 * */
import java.io.*;
import java.util.*;

public class longestPalindrome{
    private int min(int a, int b){
        return a<b ? a : b;
    }
    public String maxPalindrome(String S){
        if(S == null || S.length()==0)    return new String();
        int n = S.length();
        char[] pMix = new char[2*n+1];
        pMix[0] = '#';
        for(int i=0, k=1;i<n || k<2*n+1; k++){
            if(pMix[k-1]=='#')    pMix[k] = S.charAt(i++);
            else                  pMix[k] = '#';
        }
        int[] p = new int[2*n+1];    //radius of palindrome substring which centre is [i], including center
        p[0] = 1;
        int id=0, mx=id+p[id];        //id is center of longest palindrome substring till now, mx is the exclusive edge of it
        for(int i=1;i<2*n+1;i++){
            if(mx > i)      p[i] = min(p[2*id-i], mx-i);
            else            p[i] = 1;
            while(i-p[i]>=0 && i+p[i]<2*n+1 && pMix[i-p[i]]==pMix[i+p[i]])
                p[i]++;
            if(p[i] > p[id]){
                id = i;
                mx = i+p[i];
            }
        }
        char[] res = new char[2*p[id]];
        int k=0;
        for(int i=id-p[id]+1;i<id+p[id];i++){
            if(pMix[i]=='#')    continue;
            res[k++] = pMix[i];
        }
        return new String(res);        
    }
    
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        longestPalindrome lp = new longestPalindrome();
        while(true){
            System.out.println("input string:");
            String str = scan.nextLine();
            if(str.isEmpty())    break;
            System.out.println(lp.maxPalindrome(str));
        }
    }
}
