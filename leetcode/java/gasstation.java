/*
 * there are N gas station along a circular route, where the amount of gas at station i is gas[i]
 * you have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1).
 * you begin the journey with an empty tank at one of the gas stations.
 * return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 * */
import java.io.*;
import java.util.*;

public class gasstation{
    public int canCompleteCircuit(int[] gas, int[] cost){
        int tank=0, i=0, start=-1, n = gas.length;
        while(true){
            if(i >= n)    i -= n;
            if(start != -1 && i==start)        break;
            tank += gas[i] - cost[i];
            if(tank < 0){
                int j=i;
                i = start==-1 ? i : start;
                while(tank<0){
                    --i;
                    if(i<0)    i+=n;
                    if(i==j)    return -1;
                    tank += gas[i] - cost[i];
                }
                start = i;
                i=j+1;
            }else{
                if(start == -1)        start = i;
                ++i;
            }
        }
        return start;
    }

    public void test_01(){
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.println("please input gas[]:");
            String str = scan.nextLine().trim();
            if(str.isEmpty())    break;
            StringTokenizer t = new StringTokenizer(str, " ,");
            int[] gas = new int[t.countTokens()];
            int i=0;
            while(t.hasMoreTokens()){
                gas[i++] = Integer.parseInt(t.nextToken());
            }
            
            System.out.println("please input cost[]:");
            str = scan.nextLine().trim();
            if(str.isEmpty())    break;
            t = new StringTokenizer(str, " ,");
            int[] cost = new int[t.countTokens()];
            int j=0;
            while(t.hasMoreTokens()){
                cost[j++] = Integer.parseInt(t.nextToken());
            }
            if(i!=j){
                System.out.println("Error: gas[] and cost[] has different count!");
                continue;
            }
            System.out.println("the start is " + canCompleteCircuit(gas, cost));     
        }
    }

    public static void main(String[] args){
        gasstation gs = new gasstation();
        gs.test_01();
        return;
    }
}
