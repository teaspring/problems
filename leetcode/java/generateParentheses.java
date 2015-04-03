/*
 * generate all combinations of well-formed parentheses with given n pairs
 * */
import java.io.*;
import java.util.ArrayList;
import java.util.Stack;

public class generateParentheses{

    public ArrayList<String> generate(int n){
        ArrayList<String> result = new ArrayList<String>();
        char[] pool = new char[2*n];
        outputParentheses(n, n, pool, 0, result);

		return result;
    }

    private void outputParentheses(int l, int r, char[] arr,
            int count, ArrayList<String> result){
        if(l == 0 && r == 0){
            result.add(new String(arr));
            return;
        }

        if(l > 0){
            arr[count] = '(';
            outputParentheses(l - 1, r, arr, count + 1, result);
        }

        if(l < r){
            arr[count] = ')';
            outputParentheses(l, r - 1, arr, count + 1, result);
        }

        return;
    }
}

/* unit test is in ../java_unittest/generateParentheses_junit */
