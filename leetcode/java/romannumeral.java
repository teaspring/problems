/*
 * converion between Roman numerals and integers
 * I  - 1
 * IV - 4
 * V  - 5
 * IX - 9
 * X  - 10
 * XL - 40
 * L  - 50
 * XC - 90
 * C  - 100
 * CD - 400
 * D  - 500
 * CM - 900
 * M  - 1000
 *
 * note that: in Roman numeral's defition, integer >= 3999 is invalid
 * */
import java.io.*;
import java.util.*;

public class romannumeral{
    int[] digits = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    String[] alphas = {
        "I",
        "IV",
        "V",
        "IX",
        "X",
        "XL",
        "L",
        "XC",
        "C",
        "CD",
        "D",
        "CM",
        "M"
    };
    public String int2Roman(int num){
        StringBuilder builder = new StringBuilder();
        int j=0, i=12;
        while(num > 0){
            if(num < digits[i]){
                --i;
            }else{
                builder.append(alphas[i].charAt(0));
                if(i % 2 == 1){ // i%2 == 1
                    builder.append(alphas[i].charAt(1));
                }
                num -= digits[i];
            }
        }
        return builder.toString();
    }

    public int roman2Int(String s){
        int res=0, n=s.length(), i=0, j=12;
        while(i < n && j>=0){
            if(j % 2 ==1){  //to match 2 chars
                if(i<n-1 && s.substring(i,i+2).equals(alphas[j])){  //String.substring(i,j) [i,j)
                    res += digits[j];
                    i += 2;
                }else{
                    --j;
                }
            }else{          //to match 1 char
                if(s.substring(i,i+1).equals(alphas[j])){
                    res += digits[j];
                    ++i;
                }else{
                    --j;
                }
            }
        }
        return res;
    }

    public void test_01(){
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.println("please input integer to convert:");
            String str = scan.nextLine().trim();
            if(str.isEmpty())    break;
            int n = Integer.parseInt(str);
            System.out.println(int2Roman(n));
        }
    }

    public void test_02(){
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.println("please input Roman numerals in upper case to convert:");
            String str = scan.nextLine().trim();
            if(str.isEmpty())    break;
            System.out.println(roman2Int(str));
        }
    }

    public static void main(String[] args){
        romannumeral rn = new romannumeral();
        rn.test_02();
    }
}
