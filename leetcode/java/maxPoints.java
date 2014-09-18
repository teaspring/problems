/*
 * given n points on 2D plane, find maximum number of points on one straight line
 * */
import java.io.*;
import java.util.*;

class Point{
    int x;
    int y;
    Point(){x=0; y=0;}
    Point(int a, int b){x=a; y=b;}
}

public class maxPoints{
    public int mPoints(Point[] points){
        if(points == null)    return 0;
        if(points.length <= 2)    return points.length;

        Map<Integer, Map<Integer, Integer>> map
            = new HashMap<Integer, Map<Integer, Integer>>();
        int result = 0;
        for(int i=0; i < points.length; i++){
            map.clear();
            int overlap = 0, max = 0;
            for(int j = i+1; j < points.length; j++){
                int x = points[j].x - points[i].x;
                int y = points[j].y - points[i].y;
                if(x==0 && y==0){  // find duplicate of [i] with [j], so that no need to sort in advance
                    overlap++;
                    continue;
                }
                int gcd = getGCD(x, y);
                if(gcd != 0){
                    x /= gcd;
                    y /= gcd;
                }

                if(map.containsKey(x)){ // (x,y) confirms the line, y/x is its slope
                    if(map.get(x).containsKey(y)){
                        map.get(x).put(y, map.get(x).get(y)+1);
                    }else{
                        map.get(x).put(y,1);
                    }
                }else{
                    Map<Integer, Integer> m = new HashMap<Integer, Integer>();
                    m.put(y, 1);
                    map.put(x, m);
                }
                max = Math.max(max, map.get(x).get(y));
            }
            result = Math.max(result, max + overlap+1);
        }
        return result;
    }

    private int getGCD(int a, int b){
        if(b == 0)    return a;
        else return getGCD(b, a%b);
    }

    public void test(){
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.println("please input string: ");
            String s = scan.nextLine().trim();
            if(s.isEmpty())    break;
            StringTokenizer t = new StringTokenizer(s, " ,");
            int[] arr = new int[t.countTokens()];
            int n=0;
            while(t.hasMoreTokens()){
                arr[n++] = Integer.parseInt(t.nextToken());
            }
            Point[] points = new Point[n/2];
            for(int i=0; i<n/2; i++){
                points[i] = new Point(arr[i*2], arr[i*2+1]);
            }
            System.out.println("max points on one line: " + mPoints(points));
        }
    }

    public static void main(String[] args){
        maxPoints mp = new maxPoints();
        mp.test();
    }
}
