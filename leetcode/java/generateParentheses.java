/*
 * generate all combinations of well-formed parentheses with given n pairs
 * */
import java.io.*;
import java.util.*;

public class generateParentheses{
    private String makeout(Stack<Integer> stk){
        StringBuilder builder = new StringBuilder();
        for(Integer i : stk){
            builder.append(i == 1 ? "(" : ")");
        }
        return builder.toString();
    }

    private void append(ArrayList<String> res, Stack<Integer> stk, int posiN, int negaN){
        if(posiN==0 && negaN==0){
            res.add(makeout(stk));
            return;
        }
        if(posiN > 0){
            stk.push(1);
            append(res, stk, posiN-1, negaN);
            stk.pop();
        }
        if(posiN < negaN){
            stk.push(-1);
            append(res, stk, posiN, negaN-1);
            stk.pop();
        }
    }

    public ArrayList<String> generate(int n){
        ArrayList<String> arr = new ArrayList<String>();
        if(n < 1)    return arr;
        Stack<Integer> stk = new Stack<Integer>();        
        append(arr, stk, n, n);
        return arr;
    }
    
    public void test_01(){
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.println("please input integer n:");
            String str = scan.nextLine().trim();
            if(str.isEmpty())    break;
            int n = Integer.parseInt(str);
            ArrayList<String> res = generate(n);
            for(String s : res){
                System.out.print(s + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args){
        generateParentheses gp = new generateParentheses();
        gp.test_01();
    }
}
