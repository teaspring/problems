/*
 * given an array S of n integers, find all unique quadruplets in array which gives sum of target.
 * requirement: elements in a quadruplets are in non-decending; the set must not contain duplicate quadruplets.
 * solution: it can follow 3sum, and the key point is to skip the duplicate num[i,j,l,r] seperately
 * */
import java.io.*;
import java.util.*;

public class foursum{
    public ArrayList<ArrayList<Integer>> fourSum(int[] num, int target){
        if(num.length < 4)    return new ArrayList<ArrayList<Integer>>();
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        Arrays.sort(num);
        for(int i=0;i<num.length-3;i++){
            if(i>0 && num[i] == num[i-1])    continue;         //skip duplicate num[i]
            for(int j=i+1;j<num.length-2;j++){
                if(j>i+1 && num[j]==num[j-1])    continue;     //skip duplicate num[j]
                for(int l=j+1, r=num.length-1;l<r;){
                    if(l>j+1 && num[l]==num[l-1]){             //skip duplicate num[l]
                        l++;
                        continue;
                    }
                    if(r < num.length-1 && num[r]==num[r+1]){  //skip duplicate num[r]
                        r--;
                        continue;
                    }
                    int tmp = num[i] + num[j] + num[l] + num[r];
                    if(tmp==target){
                        ArrayList<Integer> arr = new ArrayList<Integer>();
                        arr.add(num[i]);
                        arr.add(num[j]);
                        arr.add(num[l]);
                        arr.add(num[r]);
                        res.add(arr);
                        //break;    //can not break here!! because the solution is not exactly one and there will be other options later
                        l++;
                    }else if(tmp < target){
                        l++;
                    }else{
                        r--;
                    }
                }
            }
        }
        return res;
    }

    private int[] parseIntArray(String s, String delimeter){
        StringTokenizer t = new StringTokenizer(s, delimeter);
        ArrayList<Integer> arr = new ArrayList<Integer>();
        while(t.hasMoreTokens()){
            arr.add(Integer.parseInt(t.nextToken().toString()));
        }
        int[] res = new int[arr.size()];
        for(int i=0;i<arr.size();i++){
            res[i] = arr.get(i);
        }
        return res;
    }

    public void test(){
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.println("input integer array:");
            String str = scan.nextLine().trim();
            if(str.isEmpty())    break;
            int[] num = parseIntArray(str, " ,");

            System.out.println("input target integer:");
            str = scan.nextLine().trim();
            if(str.isEmpty())    break;
            int target = Integer.parseInt(str);
            ArrayList<ArrayList<Integer>> res = fourSum(num, target);
            for(int i=0;i<res.size();i++){
                System.out.println(res.get(i).toString());
            }
        }
        return;
    }

    public static void main(String[] args){
        foursum fs = new foursum();
        fs.test();
    }
}
