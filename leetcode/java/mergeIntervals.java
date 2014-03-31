/*
 * given a collection of intervals, merge all overlapping intervals.
 *
 * */
import java.io.*;
import java.util.*;
import java.util.Comparator;
import java.lang.*;

public class mergeIntervals{
    class Interval{
        int start;
        int end;
        Interval(){
            start = 0;
            end   = 0;
        }
        Interval(int s, int e){
            start = s;
            end   = e;
        }
    }
    
    class IntervalComparator implements Comparator{
        public int compare(Object o1, Object o2){    //it should return 0 for equalization 
            Interval i1 = (Interval)o1;
            Interval i2 = (Interval)o2;
            if(i1.start == i2.start){
                if(i1.end < i2.end){
                    return -1;
                }else if(i1.end > i2.end){
                    return 1;
                }else{
                    return 0;
                }
            }else{
                return i1.start < i2.start ? -1 : 1;
            }
        }    
    }

    private void displayIntervals(ArrayList<Interval> intervals){
        for(Interval i : intervals){
            System.out.print("[" + i.start + ", " + i.end + "] ");
        }
        System.out.println();
        return;
    }

    public ArrayList<Interval> merge(ArrayList<Interval> intervals){
        Comparator comp = new IntervalComparator();
        Collections.sort(intervals, comp);
        displayIntervals(intervals);

        ArrayList<Interval> res = new ArrayList<Interval>();
        for(Interval i : intervals){
            if(res.isEmpty()){
                res.add(new Interval(i.start, i.end));
                continue;
            }
            int m = res.size();
            if(res.get(m-1).end >= i.start){
                Interval tail = res.get(m-1);
                res.remove(m-1);
                res.add(new Interval(tail.start, Math.max(tail.end, i.end)));
            }else{
                res.add(new Interval(i.start, i.end));
            }
        }
        return res;
    }

    public void test_01(){
        Scanner s = new Scanner(System.in);
        while(true){
            System.out.println("please input intervals in pairs of interger:");
            String str = s.nextLine().trim();
            if(str.isEmpty())    break;
            StringTokenizer st = new StringTokenizer(str, " ,");
            int[] arr = new int[st.countTokens()];
            int n = 0;
            while(st.hasMoreTokens()){
                arr[n++] = Integer.parseInt(st.nextToken());
            }
            ArrayList<Interval> intervals = new ArrayList<Interval>();
            for(int i=0; i<(n/2); ++i){
                intervals.add(new Interval(arr[2*i], arr[2*i+1]));
            }
            displayIntervals(merge(intervals));
        }
    }

    public static void main(String[] args){
        mergeIntervals mi = new mergeIntervals();
        mi.test_01();
        return;
    }
}
