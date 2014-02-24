/*
 * find the longest common prefix string amongst an array of strings
 * */
import java.io.*;
import java.util.*;

public class longestcommonprefix{
    public String longestCommonPrefix(String[] strs){
        int n = strs.length;
        if(n==0)    return new String();
        if(n==1)    return new String(strs[0]);
        int length = strs[0].length();
        for(int i=1;i<n;i++){
            if(length > strs[i].length()){
                length = strs[i].length();
            }
        }
        StringBuilder builder = new StringBuilder();
        int i=0;
        for(;i<length;++i){
            Character ch = new Character(strs[0].charAt(i));
            int j;
            for(j=1;j<n && ch.equals(strs[j].charAt(i));++j);
            if(j<n)    break;
            builder.append(ch);
        }
        return builder.toString();
    }

    public static void main(String[] args){
        return;
    }
}
