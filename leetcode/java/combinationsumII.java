/*
 * given a collection of candidate numbers (C) and a target number (T), find all unique combination in C
 * where the candidate numbers sums to T.
 *
 * Note:
 * 0. each number in C can be used only once in one combination.
 * 1. all numbers (including target) will be positive integers
 * 2. elements in a combination result must be in non-descending order
 * 3. the result set cannot have duplicate combinations
 * by the way, C can have duplciate numbers
 *
 * test data: 
 * {1,1,2,2,2,3}, target = 6
 * result: {1,1,2,2}, {1,2,3}, {2,2,2}
 * */
import java.io.*;
import java.util.*;

public class combinationsumII{
    private Stack<Integer> stk = new Stack<Integer>();  // push index of num[]

    private void putStack(int[] num, ArrayList<ArrayList<Integer>> combinations){
        ArrayList<Integer> arr = new ArrayList<Integer>();
        for(int i : stk){
            arr.add(num[i]); // save number instead of index in result
        }
        combinations.add(arr);
        return;
    }

    private void plusSum(int[] num, int target, ArrayList<ArrayList<Integer>> result){
        if(target == 0){
            putStack(num, result);
            return;
        }

        int start = stk.isEmpty() ? 0 : stk.peek() + 1;
        /// num[i] is the first number which can be used for consistent args (stk, target)
        for(int i = start; i < num.length; ++i){
            if(target < num[i])    break;
            if(i > start && num[i] == num[i-1])    continue; // skip duplicate combination!
            stk.push(i);
            plusSum(num, target - num[i], result);
            stk.pop();
        }
        return;
    }

    public ArrayList<ArrayList<Integer>> combinationSumII(int[] num, int target){
        Arrays.sort(num);    //sort in ascending order
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        stk.clear();
        plusSum(num, target, result);
        return result;
    }

    /* unit test is in ../java_unittest/combinatiomsumII_junit/  */

    public void display(ArrayList<ArrayList<Integer>> combinations){
        System.out.println("combinations:");
        for(ArrayList<Integer> arr : combinations){
            for(Integer i : arr){
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }

    public void test_01(){
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.println("please input integer candidates:");
            String str = scan.nextLine().trim();
            if(str.isEmpty())    break;
            StringTokenizer t = new StringTokenizer(str, " ,");
            int[] nums = new int[t.countTokens()];
            int i = 0;
            while(t.hasMoreTokens()){
                nums[i++] = Integer.parseInt(t.nextToken().toString());
            }

            System.out.println("please input integer target:");
            str = scan.nextLine().trim();
            if(str.isEmpty())    break;
            int x = Integer.parseInt(str);

            display(combinationSumII(nums, x));
        }
        return;
    }
}
