/*
 * given a string of lower characters, find the length of longest sub string without repeat character
 * */
import java.util.*;
import java.io.*;

public class lengthOfLongestSubstr{
    private int min(int a, int b){
        return a<b ? a : b;
    }
    public int lengthoflongestsubstr(String s){
        if(s.isEmpty())        return 0;
        int[] pos = new int[26];
        for(int i=0;i<26;i++){
            pos[i] = -1;
        }
        pos[s.charAt(0) - 'a'] = 0;
        int[] length = new int[s.length()];
        length[0] = 1;
        int res=1;
        for(int i=1;i<s.length();i++){
            char ch = s.charAt(i);
            length[i] = min(length[i-1] + 1, i - pos[ch - 'a']);
            pos[ch - 'a'] = i;
            if(length[i] > res)    res = length[i];
        }
        return res;
    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        lengthOfLongestSubstr ls = new lengthOfLongestSubstr();
        while(true){
            String str = scan.nextLine().trim();
            if(str.isEmpty())    break;
            System.out.println(ls.lengthoflongestsubstr(str));
        }
        return;
    }
}
