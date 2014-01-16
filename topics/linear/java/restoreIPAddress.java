/*
 * from oj.leetcode. given a string containing only digits, restore it by returning all possible IP address combinations.
 *
 * test case:
 * 1111
 * 0000
 * 00000 //should return empty!
 * 010010  //any {001, 01} are invalid
 * */

import java.io.*;
import java.util.*;

public class restoreIPAddress{
    private int max(int a, int b){
        return a>b ? a : b;
    }
    /*
     * key of this algorithm is skip all the invalid cases
     * */
    public ArrayList<String> restoreIpAddress(String s){
        ArrayList<String> res = new ArrayList<String>();
        if(s == null || s.length() < 4 || s.length() > 12)    return res;
        final int n = s.length();

        ArrayList<Integer>    dom1 = new ArrayList<Integer>();
        for(int i=1; i<4;++i){
            int tmp = new Integer(s.substring(0, i));
            if(tmp > 255 || tmp<0 || (tmp<10 && i>1) || (tmp<100 && i>2)){
                continue;
            }
            dom1.add(i);    //exclusive end of domain 1
        }
        if(dom1.isEmpty())    return res;

        ArrayList<Integer> dom4 = new ArrayList<Integer>();
        for(int i=n-1; i>=n-3;i--){
            int tmp = new Integer(s.substring(i, n));
            if(tmp > 255 || tmp < 0 || (tmp<10 && n-i>1) || (tmp<100 && n-i>2)){
                continue;
            }
            dom4.add(i);    //inclusive start of domain4
        }
        if(dom4.isEmpty())    return res;

        for(int q : dom1){
            for(int e : dom4){
                if(e-q > 6 || e-q < 2)    continue;
                for(int p=q+1;p<e;p++){ //based on q and e, find the exclusive end of domain2(equals to inclusive start of domain3)
                    int mx = max(p-q, e-p);
                    if(mx > 3)    continue;
                    String grp2 = s.substring(q,p);
                    String grp3 = s.substring(p,e);
                    int ip2 = new Integer(grp2);
                    int ip3 = new Integer(grp3);
                    if(ip2 > 255 || ip2<0 || (ip2<10 && p-q>1) || (ip2<100 && p-q>2)
                    || ip3 > 255 || ip3<0 || (ip3<10 && e-p>1) || (ip3<100 && e-p>2)){
                        continue;
                    }
                    StringBuilder builder = new StringBuilder(s.substring(0, q));
                    builder.append(".");
                    builder.append(grp2);
                    builder.append(".");
                    builder.append(grp3);
                    builder.append(".");
                    builder.append(s.substring(e, n));
                    res.add(builder.toString());
                }
            }
        }
        return res;
    }
    
    public void test(){
        Scanner scan = new Scanner(System.in);
        while(true){
            String s = scan.nextLine();
            if(s.isEmpty())        break;
            ArrayList<String> res = restoreIpAddress(s);
            System.out.println(res.toString());
        }

    }

    public static void main(String[] args){
        restoreIPAddress rIP = new restoreIPAddress();
        rIP.test();
    }
}
