/*
 * implement strStr(). return a pointer to the first occurance of needle in haystack, or null.
 * solution: KMP string match algorithm
 * */
import java.io.*;
import java.util.*;

public class strStr{
    /*
     * prefix[i] = l means prefix with length l of s can be suffix of s, while s is prefix with length i+1 of pattern
     * */
    private void setPrefix(String pattern, int[] prefix){
        final int n = pattern.length();
        prefix[0] = 0;

        char[] arr = pattern.toCharArray();
        for(int i = 1; i < n; ++i){
            int k = prefix[i-1];
            char ch = arr[i];
            for(; ch != arr[k] && k > 0; k = prefix[k-1]);
            if(ch == arr[k]){
                prefix[i] = k + 1;
            }else{
                prefix[i] = 0;
            }
        }
        return;
    }

    /*
     * use KMP algorithm to search string
     * */
    public String strstr(String haystack, String needle){
        final int n = haystack.length();
        final int m = needle.length();

        if(m == 0)    return haystack;
        if(n < m || n == 0)        return null;

        int[] prefix = new int[m];
        setPrefix(needle, prefix);

        char[] hArr = haystack.toCharArray();
        char[] nArr = needle.toCharArray();
        int i = 0, s = 0;  // i is cursor offset in haystack while s is needle offset in haystack
        boolean bfind = false;
        while(i < n){
            if(i < s){
                ++i;
                continue;
            }else if(i - s == m){
                bfind = true;
                break;
            }

            int k = i - s; // k is prefix length inside needle which has been compared equal already
            if(hArr[i] == nArr[k]){
                ++i; // needle stays while cursor moving
            }else{
                s += (k == 0) ? 1 : k - prefix[k-1];  // needle moves
            }
        }

        if(bfind || i - s == m){
            return haystack.substring(s, n);
        }
        return null;
    }
    /* unit test is in ../../java_unittest/strStr_junit/ */
}
