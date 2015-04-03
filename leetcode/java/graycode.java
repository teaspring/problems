/*
 * Gray code is a binary numeral system where two successive values differ in only one bit. the coding result is not unique.
 * one opional coding algorithm:
 * 1. flip lowest bit(0th bit from the right)
 * 2. flip the next bit following 1st bit of 1 from low to high
 * 
 * test case:
 * n=3,
 * 000
 * 001
 * 011
 * 010
 * 110
 * 111
 * 101
 * 100
 * */
import java.io.*;
import java.util.*;

public class graycode{

    public ArrayList<Integer> generate_01(int n){
        int x = 0, bin = 0;
        ArrayList<Integer> res = new ArrayList<Integer>();
        res.add(x);
        if(n < 1)    return res;

        while(true){
            bin = 1 - bin;
            if(bin == 1){
                x ^= 1;
            }else{
                int a = 1, i = 0;
                while(i < n-1 && (x & a) == 0){
                    a = a << 1;
                    ++i;
                }

                if(i == n-1)    break;
                x = x ^ (a << 1);
            }
            res.add(x);
        }

        return res;
    }

    public ArrayList<Integer> generate_02(int n){
        ArrayList<Integer> res = new ArrayList<Integer>();
        res.add(0);

        final int count = 1 << n;
        for(int i = 1; i < count; i++){
            res.add(indexedGrayCode(i));
        }

		return res;
    }

    private int indexedGrayCode(int k){
        return k ^ (k >> 1);
    }
}

/* unit test is in ../java_unittest/grayCode_junit/ */
