/*
 * given numRows, generate the first numRows of Pascal's triangle
 * e.g. numRows=5, return:
 * 1
 * 1,1
 * 1,2,1
 * 1,3,3,1
 * 1,4,6,4,1
 * */

import java.io.*;
import java.util.*;

public class pascalTriangle{
    public ArrayList<ArrayList<Integer>> generate(int nRows){
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        if(nRows < 1)    return res;
        ArrayList<Integer> lst = new ArrayList<Integer>();
        lst.add(1);
        res.add(lst);
        for(int i=1;i<nRows;++i){
            ArrayList<Integer> last = res.get(i-1);
            ArrayList<Integer> now = new ArrayList<Integer>();
            now.add(last.get(0));
            for(int j=1;j<i;++j){
                now.add(last.get(j-1) + last.get(j));
            }
            now.add(last.get(i-1));
            res.add(now);
        }
        return res;
    }

    void show(ArrayList<ArrayList<Integer>> tri){
        for(ArrayList<Integer> arr : tri){
            for(Integer i : arr){
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }
    void test_01(){
        Scanner sc = new Scanner(System.in);
        while(true){
            System.out.println("please input string: ");
            String s = sc.nextLine().trim();
            if(s.isEmpty())        break;
            int n = Integer.parseInt(s);
            show(generate(n));    
        }
    }
    public static void main(String[] args){
        pascalTriangle pt = new pascalTriangle();
        pt.test_01();
    }
}
