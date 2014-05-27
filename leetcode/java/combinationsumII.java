/*
 * given a collection of candidate numbers (C) and a target number (T), find all unique combination in C where the candidate numbers sums to T. Each number in C may only be used only once in the combination.
 * Note:
 * 1. all numbers (including target) will be positive integers
 * 2. elements in a combination must be in non-descending order
 * 3. the solution set must not contain duplicate combinations
 * hidden: candidate numbers can have duplciate
 *
 * test data: 
 * {1,1,2,2,2,3}, target = 6
 * result: {1,1,2,2}, {1,2,3}, {2,2,2}
 * */
import java.io.*;
import java.util.*;

public class combinationsumII{
    private ArrayList<ArrayList<Integer>> combinations = new ArrayList<ArrayList<Integer>>();
    private Stack<Integer> stk = new Stack<Integer>();    //put index of candidate nums
    
    private void putStack(int[] num){
        ArrayList<Integer> arr = new ArrayList<Integer>();
        for(int i : stk){
            arr.add(num[i]);
        }
        combinations.add(arr);
        return;
    }

    private void plusSum(int[] num, int target){
        if(target==0){
            putStack(num);
            return;
        }
        int n = num.length;
        int last = stk.isEmpty() ? 0 : stk.peek() + 1;
        for(int i=last; i<n; ++i){
            if(target < num[i])        break;
            if(i > last && num[i]==num[last])    continue;    // key statement to skip duplicate combination
            stk.push(i);
            plusSum(num, target - num[i]);
            stk.pop();
            last = i;
        }
        return;
    }

    public ArrayList<ArrayList<Integer>> combinationSum2(int[] num, int target){
        Arrays.sort(num);    //sort in ascending order
        combinations.clear();
        stk.clear();
        plusSum(num, target);
        return combinations;
    }

    /***************test***************/
    public void display(){
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
            
            combinationSum2(nums, x);
            display();
        }
        return;
    }

    public static void main(String[] args){
        combinationsumII cs = new combinationsumII();
        cs.test_01();
        return;
    }
}
