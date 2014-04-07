/*
 * given an input string, reverse the string word by word. one word is constituted by non-space char.
 * necessary clarification:
 * 1. reversed result should not contain leading/tailing space
 * 2. after reversed, multiple spaces between words reduced to one single space
 * */
import java.io.*;
import java.util.*;
import java.lang.Character;     //class Character

public class reverseWords{
    private StringBuilder reduceSpaces(String src){
        StringBuilder builder = new StringBuilder();
        for(int i=0; i<src.length(); ++i){
            if(Character.isSpaceChar(src.charAt(i)))    continue;
            if(i>0 && Character.isSpaceChar(src.charAt(i-1))){
                int m = builder.length();
                if(m>0 && !Character.isSpaceChar(builder.charAt(m-1))){
                    builder.append(" ");        
                }
            }
            builder.append(src.charAt(i));
        }
        return builder;
    }

    private void swapCharInStr(StringBuilder builder, int l, int r){
        char ch = builder.charAt(l);
        builder.setCharAt(l, builder.charAt(r));
        builder.setCharAt(r, ch);
        return;
    }

    private void reverseItem(StringBuilder builder, int b, int e){
        int mid = (b + e) / 2 ;
        for(int i=b; i<mid; ++i){
            swapCharInStr(builder, i, --e);
        }
        return;
    }

    public String reverse(String s){
        StringBuilder builder = reduceSpaces(s);
        if(builder.length() == 0)    return new String();
        int n = builder.length();
        for(int b = 0, e = 0; b<n && e<=n; ++e){
            if(e<n && !Character.isSpaceChar(builder.charAt(e)))    continue;
            if(b < e-1)        reverseItem(builder, b, e);
            b = e+1;
        }
        reverseItem(builder, 0, n);
        return builder.toString();
    }

    public static void test_01(){
        reverseWords rw = new reverseWords();
        Scanner sc = new Scanner(System.in);
        while(true){
            System.out.println("please input words in sequence to reverse:");
            String str = sc.nextLine().trim();
            if(str.isEmpty())        break;
            str = rw.reverse(str);
            System.out.println(str + ", leng of " + str.length());
        }
        return;
    }

    public static void main(String[] args){
        test_01();
        return;
    }
}
