/*
 * given a string s consists of upper/lower-case alphabets and empty space characters ' ', return length of last word in the string.
 * if the last word does not exist, return 0;
 * Note: A word is defined as a character sequenece without space 
 * */
import java.io.*;
import java.util.*;

public class lengthOfLastWord{
    public int lengthLastWord(String s){
        int l1 = 0, l2 = 0;
        for(int i = 0; i < s.length(); ++i){
            if(s.charAt(i) == ' '){
                if(l1 != 0){
                    l2 = l1;
                    l1 = 0;
                }
                continue;
            }
            ++l1;
        }
        return l1 > 0 ? l1 : l2;
    }

    public void test_01(){
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.println("please input string");
            String str = scan.nextLine().trim();
            if(str.isEmpty())        break;
            System.out.println(lengthLastWord(str));
        }
        return;
    }

    public static void main(String[] args){
        lengthOfLastWord lo = new lengthOfLastWord();
        lo.test_01();
        return;
    }
}
