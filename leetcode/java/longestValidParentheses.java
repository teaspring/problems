/*
 * given a string containing just the character '(' and ')', find the length of the longest valid(well-formed) parentheses substring
 * for "(()", it is length of 2
 *
 * test case:
 * ())()       result is 2
 * )()(())     result is 6
 * */
import java.io.*;
import java.util.*;

public class longestValidParentheses{
    private int max(int a, int b){
        return a>b ? a : b;
    }

    public int longestValidLength(String s){
        ArrayList<Integer> arr = new ArrayList<Integer>();
        int ans=0, n=s.length();
        for(int i=0; i<n; ++i){
            char ch = s.charAt(i);
            if(ch == '('){
                arr.add(-1);
                continue;
            }

            if(arr.size() > 0){  // coming ')'
                int m = arr.size();
                if(arr.get(m-1) == -1){  // ...( waiting for ')'
                    arr.set(m-1, 1);
                    ans = max(ans, 1);
                }else if(m > 1 && arr.get(m-2) == -1){  // ...(() waiting for ')'
                    int sum = arr.get(m-1) + 1;
                    arr.remove(m-1);
                    arr.remove(m-2);
                    arr.add(sum);
                    ans = max(ans, sum);
                }else{        // invalid ')'
                    if(arr.get(m-1) > 0){   //multiple seperator equals to one 
                        arr.add(0);
                    }
                    continue;
                }

                while(arr.size()>1 && arr.get(arr.size()-2) > 0){  //merge consecutive valid parentheses
                    m = arr.size();
                    int sum = arr.get(m-1) + arr.get(m-2);
                    arr.remove(m-1);
                    arr.remove(m-2);
                    arr.add(sum);
                    ans = max(ans, sum);
                }
            }
        }
        return (ans*2);
    }

    public void test_01(){
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.println("please input parentheses:");
            String str = scan.nextLine().trim();
            if(str.isEmpty())    break;
            System.out.println(longestValidLength(str));
        }
    }

    public static void main(String[] args){
        longestValidParentheses lvp = new longestValidParentheses();
        lvp.test_01();
    }
}
