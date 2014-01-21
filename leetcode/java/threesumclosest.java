/*
 * from oj.leetcode. Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
 * Return the sum of the three integers. Each input would have exactly one solution.
 *
 * test data:
 * 0 2 1 -3, target=1
 * -1 -1 1 1 3, target=-1
 * -4 -4 -3 0 2 6 9 10, target=4  
 * */
import java.io.*;
import java.util.*;

public class threesumclosest{
    public int absminus(int a, int b){
        return a-b>0 ? a-b : b-a;
    }
    public int threeSumClosest(int[] arr, int target){
        Arrays.sort(arr);    //sort in ascendinag
        //System.out.println(Arrays.toString(arr));
        boolean found=false;
        int res=0, dist=0xfff;
        for(int i=0;dist!=0 && i<arr.length-2;++i){
            if(i>0 && arr[i]==arr[i-1])        continue;    //skip duplicate arr[i]
            for(int l=i+1, r=arr.length-1;l<r;){
                if(l > i+1 && arr[l]==arr[l-1]){    //skip duplicate arr[l]
                    l++;
                    continue;
                }
                if(r < arr.length-1 && arr[r]==arr[r+1]){    //skip duplicate arr[r]
                    r--;
                    continue;
                }
                int tmp = absminus(arr[l] + arr[r] + arr[i], target);
                if(tmp < dist){
                    dist = tmp;
                    res = arr[i] + arr[l] + arr[r];
                    if(dist==0)            break;    //exit while nothing else can be closer than 0
                }
                //if(lastDist < tmp)    break;    //NOTE: track distance descending is not needed which will skip correct answer! because
                //the minus of target-arr[i]-arr[l]-arr[r] will be +,-,+,- so the absminus will not be descending absolutely
                if(arr[l] + arr[r] > target-arr[i]){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return res;
    }

    private int[] parseIntArray(String s){
        int len = s.length();
        StringTokenizer t = new StringTokenizer(s, " ,");
        List<Integer> list = new ArrayList<Integer>();
        while(t.hasMoreTokens()){
            list.add(Integer.parseInt(t.nextToken().toString())); 
        }
        int[] res = new int[list.size()];
        for(int i=0;i<list.size();i++){    //have not enabled ArrayList.toArray(), so have to copy it to array one by one
            res[i] = list.get(i);
        }
        return res;
    }

    public void test(){
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.println("input integer array:");
            String str = scan.nextLine().trim();
            if(str.isEmpty())    break;
            int[] arr = parseIntArray(str);

            System.out.println("input target integer:");
            str = scan.nextLine().trim();
            if(str.isEmpty())    break;
            int target = Integer.parseInt(str);
            System.out.println("the 3sum closest is " + threeSumClosest(arr, target));
        }
        
    }
    public static void main(String[] args){
        threesumclosest cl = new threesumclosest();
        cl.test();
    }
}
