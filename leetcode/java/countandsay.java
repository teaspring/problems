/*
 * the count-and-say sequence is the sequence of integers as below:
 * 1 is readoff as "one 1" so next is 11
 * 11 is readoff as "two 1" so next is 21
 * 21 -> 1211 -> 111221 -> 312211-> 13112221 ...
 * given integer n and find the nth sequence in string, n is 1-based
 * */
import java.io.*;
import java.util.*;

public class countandsay{
    private String getNext(String a){
        int n = a.length();
        StringBuilder builder = new StringBuilder();
        int i=0;
        while(i<n){
            int k=i+1;
            for(;k<n && a.charAt(k) == a.charAt(k-1);++k);
            builder.append(k-i);
            builder.append(a.charAt(i));
            i=k;
        }
        return builder.toString();
    }

    public String countAndSay(int n){
        if(n<1)        return new String();
        int l=1;
        String str = new String("1");
        for(; n>1; --n){
            str = getNext(str);
        }
        return str;
    }

    public void test_01(){
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.println("please input nth:");
            String str = scan.nextLine().trim();
            if(str.isEmpty())    break;
            int n = Integer.parseInt(str);
            System.out.println(countAndSay(n));
        }
    }

    public static void main(String[] args){
        countandsay cs = new countandsay();
        cs.test_01();
        return;
    }
}
