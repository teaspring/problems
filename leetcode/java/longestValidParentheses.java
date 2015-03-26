/*
 * given a string containing just the characters '(' and ')', find the length of longest valid(well-formed) parentheses substring
 *
 * test case:
 * (()(), result is 4
 * ((())()(, result is 6
 * */

import java.util.List;
import java.util.Stack;
import java.lang.Math;


public class longestValidParentheses{

    /*
    * version accepted by oj.leetcode. use stack to save verified parenthesis pairs count
    * */
    public int longestValidLength(String s){
        final int n = s.length();
        char[] arr = s.toCharArray();
        Stack<Integer> stk = new Stack<Integer>();  // vector<> works as stack<>
        int ans = 0;
        for(char ch : arr){
            if(ch == '('){
                stk.push(-1);
            }else{ // the new tail char is ')'
                if(!stk.empty()){
                    if(stk.peek() == -1){
                        stk.pop();
                        stk.push(1);
                    }else if(stk.size() > 1){  //stk[m - 2] == -1 certainly
                        int now = stk.pop();
                        stk.pop();
                        stk.push(now + 1);
                    }else{   // without new tail ')' contribution to stk, preceding is only positive int
                        stk.clear();
                        continue;
                    }
                    ans = Math.max(ans, sumPrecedingPosi(stk));
                }
            }
        }
        return (ans * 2); // ans is pairs count, * 2 equals to length
    }

    private int sumPrecedingPosi(Stack<Integer> stk){ // previous code keep the @arg stk is not empty
        if(!stk.empty() && stk.peek() > 0){
            int m = stk.size();
            if(m > 1 && stk.get(m - 2) > 0){
                int sum = stk.pop();
                sum += stk.pop();
                stk.push(sum);
            }
        }
        return stk.peek();
    }
};
/* unit test is in ../java_unittest/longestValidParentheses_junit/ */
