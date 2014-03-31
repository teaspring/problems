/*
 * given a set of non-overlapping intervals, insert a new interval into the intervals(merge if necessary)
 * you may assume that the intervals were initially sorted according to their start times
 *
 * */
import java.io.*;
import java.util.*;
import java.lang.*;

public class insertIntervals{
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

    public ArrayList<Interval> insert(ArrayList<Interval> intervals, Interval newInterval){
        ArrayList<Interval> res = new ArrayList<Interval>();
        boolean inserted = false;
        for(Interval i : intervals){
            if(!inserted){
                boolean overlapped = (i.end >= newInterval.start) && (newInterval.end >= i.start);
                if(overlapped){
                    int a = Math.min(newInterval.start, i.start);
                    int b = Math.max(newInterval.end, i.end);
                    res.add(new Interval(a, b));
                    inserted = true;
                }else{
                    if(newInterval.end < i.start){
                        res.add(new Interval(newInterval.start, newInterval.end));
                        inserted = true;
                    }
                    res.add(new Interval(i.start, i.end));
                }
            }else{
                int m = res.size();
                if(res.get(m-1).end < i.start){
                    res.add(new Interval(i.start, i.end));
                }else{
                    Interval tmp = res.get(m-1);
                    res.remove(m-1);
                    res.add(new Interval(tmp.start, Math.max(tmp.end, i.end)));
                }
            }
        }
        if(!inserted){
            res.add(newInterval);
        }
        return res;
    }

    public static void main(String[] args){
        return;
    }
}

