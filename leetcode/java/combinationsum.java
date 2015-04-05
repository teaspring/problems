/*
 * given a set of candidate numbers(C) and a target number(T), find all unique combinations where
 * the candidate numbers sums to T.
 *
 * note:
 * 0. the same number may be chosen from C unlimited times.
 * 1. all numbers including target are positive
 * 2. elements in a combination must be non-decending order
 * 3. result set cannot have duplicate combinations.
 *
 * test data:
 * {2,3,6,7}, target=7, 
 * result: {7}, {2,2,3}
 * */
import java.io.*;
import java.util.*;

public class combinationsum{
    private Stack<Integer> stk = new Stack<Integer>();  // put candidate numbers
    
    private void plusSum(int[] candidates, int target, ArrayList<ArrayList<Integer>> result){
        if(target == 0){
            result.add(new ArrayList<Integer>(stk));
            return;
        }
        for(int d : candidates){ // candidates in ascending order
            if(target < d)        break;
            if(!stk.isEmpty()
               && stk.peek() > d){ // ensure numbers in stk is in ascending from bottom to top
                continue;
            }
            stk.push(d);
            plusSum(candidates, target - d, result);
            stk.pop();
        }
        return;
    }

    public ArrayList<ArrayList<Integer>> combinationSum(int[] candidates, int target){
        Arrays.sort(candidates); // sort in ascending order
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        stk.clear();
        plusSum(candidates, target, res);
        return res;
    }
}

/*    unit test code is in ../java_unittest/combinationsum_junit/   */
