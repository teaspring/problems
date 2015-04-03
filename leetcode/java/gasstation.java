/*
 * there are N gas station along a circular route, where the amount of gas at station i is gas[i]
 * you have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1).
 * you begin the journey with an empty tank at one of the gas stations.
 * return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 * */
import java.io.*;
import java.util.*;

public class gasstation{
    public int completeCircuit(int[] gas, int[] cost){
        final int n = gas.length;
        if(n < 1)    return -1;

        int start = 0; // start station
        int i = 0; // passed station
        int tank = gas[0] - cost[0];

        while(true){
            while(tank < 0){
                --start;
                if(start == -1)    start += n;

                if(start == i)     return -1; // no station to move back
                tank += gas[start] - cost[start];
            }

            ++i;
            if(i == n)    i -= n;

            if(i == start)    break; // passed all stations
            tank += gas[i] - cost[i];
        }
        return start;
    }
}

/* unit test is in ../java_unittest/gasstation_junit */
