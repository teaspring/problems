/*
 * valid a string whether is palindrome, considering only alphanumeric char and ignoring cases.
 *
 * NOTE: during interview, it is good to ask what about empty string? here we consider empty string is palindrome
 * */
import java.util.*;
import java.io.*;

public class validPalindrome{
    public boolean isPalindrome(String s){
        if(s.isEmpty())    return true;
        int i=0, j=s.length()-1;
        while(i<j){
            if(!Character.isLetterOrDigit(s.charAt(i))){    //static isLetterOrDigit()
                ++i;
                continue;
            }
            if(!Character.isLetterOrDigit(s.charAt(j))){
                --j;
                continue;
            }
            Character a = new Character(s.charAt(i));    //create one Charactder object to call equals()
            if(Character.isLetter(a))    a = Character.toLowerCase(a);
            char b = s.charAt(j);
            if(Character.isLetter(b))    b = Character.toLowerCase(b);
            if(!a.equals(b))    break;            //equals() is not static
            ++i;
            --j;
        }
        return i>=j;
    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        validPalindrome vp = new validPalindrome();
        while(true){
            System.out.println("please input string to valid:");
            String str = scan.nextLine();
            System.out.println(vp.isPalindrome(str) ? "true" : "false");
        }
    }
}


