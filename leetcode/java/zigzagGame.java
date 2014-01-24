/*
 * the string "paypalishiring" is written in a zigzag pattern on a given number of rows like this: 
 * p     i     n
 * a   l s   i g
 * y a   h r
 * p     i
 * */
import java.io.*;
import java.util.*;

public class zigzagGame{
    public String convert(String s, int nRows){
        if(nRows==0)    return new String();
        if(nRows==1)    return new String(s);
        StringBuilder pBuilders[] = new StringBuilder[nRows];    //StringBuilder is perfect container for insert/append char
        for(int r=0;r<nRows;r++){
            pBuilders[r] = new StringBuilder();
        }
        boolean up = false;
        for(int i=0, r=0;i<s.length();i++){
            pBuilders[r].append(s.charAt(i));
            if(up)      r--;
            else        r++;
            
            if(r==-1){
                r = 1;
                up = false;
            }
            if(r==nRows){
                r = nRows-2;
                up = true;
            }
        }
        StringBuilder res = new StringBuilder();
        for(int r=0;r<nRows;r++){
            res.append(pBuilders[r].toString());
        }
        return res.toString();
    }


    public static void main(String[] args){
        Scanner scan  = new Scanner(System.in);
        zigzagGame zg = new zigzagGame();
        while(true){
            System.out.println("please input string:");
            String str = scan.nextLine();
            if(str.isEmpty())    break;
            
            System.out.println("please input nRows:");
            String sRows = scan.nextLine();
            if(sRows.isEmpty())    break;
            int nRows = new Integer(sRows);
            
            System.out.println(zg.convert(str, nRows));            
        }
    }
}
