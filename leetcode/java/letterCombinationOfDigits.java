/*
 * given a digit string, return all possible letter combinations that the number could be represent.
 * a mapping of digit to letters(just like on the telephone buttons)
 * 2-abc, 3-def, 
 * questions necessary to ask during interview:
 * 1. how to process 1, 0?
 * 2. what should the result be while no valid combination? empty vector<> or empty string in vector<>?
 * */
import java.io.*;
import java.util.*;

public class letterCombinationOfDigits{
    public ArrayList<String> letterCombinations(String digits){
        ArrayList<String> res = new ArrayList<String>();
        if(digits == null || digits.length()==0){
            res.add(new String());
            return res;
        }
        int n = digits.length();
        String[] chars = {
            " ",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        //int[] count = {1,0,3,3,3,3,3,4,3,4};    //count Array is not needed as String in chars[] has length()
        int[] number = new int[n];
        int[] index = new int[n];
        for(int i=0;i<n;i++){
            number[i] = Integer.parseInt(Character.toString(digits.charAt(i)));
        }
        while(true){
            StringBuilder builder = new StringBuilder();
            for(int i=0;i<n;i++){
                builder.append(chars[number[i]].charAt(index[i]));
            }
            res.add(builder.toString());
            int k=n-1;
            if(index[k] < chars[number[k]].length() - 1){
                index[k]++;
                continue;
            }
            while(k>=0 && index[k] >= chars[number[k]].length()-1){
                index[k] = 0;
                k--;
            }
            if(k<0)        break;
            index[k]++;
        }
        return res;
    }
    
    public static void main(String[] args){
       Scanner scan = new Scanner(System.in);
       letterCombinationOfDigits lcd = new letterCombinationOfDigits();
       while(true){
           System.out.println("please input digits:");
           String str = scan.nextLine().trim();
           if(str.isEmpty())    break;
           ArrayList<String> res = lcd.letterCombinations(str);
           for(String s : res){
               System.out.print(s);
               System.out.print(", ");
           }
           System.out.println();
       }
    }
}
