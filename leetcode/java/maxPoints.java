/*
 * given n points on 2D plane, find maximum number of points on one straight line
 * */
import java.io.*;
import java.util.Map;
import java.util.HashMap;
import java.lang.Math;

public class maxPoints{

    public class Point{
        int x;
        int y;

        public Point(int a, int b){
            x = a;
            y = b;
        }
    }

    public int mPoints(Point[] points){
        if(points == null)    return 0;
        if(points.length <= 2)    return points.length;

        Map<Integer, Map<Integer, Integer>> map = new HashMap<Integer, Map<Integer, Integer>>();
        int result = 0;

        for(int i = 0; i < points.length; i++){
            map.clear();
            int overlap = 0, cmax = 0;

            /*
             * choice of the range to check: [i+1, n). Reason:
             * if during checking points[i], points[j] and points[k] are one same line, i < j < k
             * next when checking points[j], any other points which is on line connecting points[j] and points[k]
             * must be on same line with points[i], which has been calculated already
             * */
            for(int j = i+1; j < points.length; j++){ // scan points[i+1...n) to check line which contains [i] and [j]
                int x = points[j].x - points[i].x;
                int y = points[j].y - points[i].y;

                if(x == 0 && y == 0){  // find duplicate points
                    overlap++;
                    continue;
                }

                int gcd = getGCD(x, y);
                if(gcd != 0){
                    x /= gcd;
                    y /= gcd;
                }

                if(map.containsKey(x)){ // for fixed points[i], (x, y) confirms the line slope and one point, so line is fixed
                    if(map.get(x).containsKey(y)){
                        map.get(x).put(y, map.get(x).get(y) + 1);
                    }else{
                        map.get(x).put(y, 1);
                    }
                }else{
                    Map<Integer, Integer> m = new HashMap<Integer, Integer>();
                    m.put(y, 1);
                    map.put(x, m);
                }

                // max tells maximum points among points[i+1...n) which are on same line with points[i]
                cmax = Math.max(cmax, map.get(x).get(y));
            }

            result = Math.max(result, cmax + overlap + 1);
        }
        return result;
    }

    private int getGCD(int a, int b){
        return b == 0 ? a : getGCD(b, a % b);
    }
}

/* unit test is in ../java_unittest/maxPoints_junit */
