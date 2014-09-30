/*
 * given a set of non-overlapping intervals, insert a new interval into the intervals. 
 * You can assume that the intervals were initially sorted according to their start time.
 *
 * 
 * */

#include "../include/preliminary.h"

struct Interval{
    int start;
    int end;
    Interval():start(0), end(0){}
    Interval(int s, int e):start(s), end(e){} 
};

void displayIntervals(const vector<Interval>& intervals){
    for(vector<Interval>::const_iterator iter = intervals.begin();
        iter < intervals.end();
        ++iter){
        printf("[%d, %d] ", iter->start, iter->end);
    }
    printf("\n");
}

/*
 * linear solution, time in O(n)
 * */
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval){
    vector<Interval> res;
    bool inserted = false;
    for(vector<Interval>::const_iterator iter = intervals.begin();
        iter != intervals.end();
        ++iter){
        if(!inserted){
            bool overlapped = (iter->end >= newInterval.start) && (newInterval.end >= iter->start);
            if(overlapped){
                int a = min(newInterval.start, iter->start);
                int b = max(newInterval.end, iter->end);
                res.push_back(Interval(a, b));
                inserted = true;
            }else{
                if(newInterval.end < iter->start){
                    res.push_back(Interval(newInterval.start, newInterval.end));
                    inserted = true;
                }
                res.push_back(Interval(iter->start, iter->end));
            }
        }else{
            int m = res.size();
            if(res[m-1].end < iter->start){
                res.push_back(Interval(iter->start, iter->end));
            }else{
                res[m-1].end = max(res[m-1].end, iter->end);
            }
        }
    }
    if(!inserted){    //don't forget insert it if not yet
        res.push_back(Interval(newInterval.start, newInterval.end));
    }
    return res;
}

void test_01(){
    string str;
    while(1){
        cout << "please input integer start/end of intervals in pairs:" << endl;
        if(getline(cin, str)==0 || str.empty())        break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        vector<Interval> intervals;
        for(int i=0; i < (n>>1); ++i){
            intervals.push_back(Interval(arr[i<<1], arr[(i<<1) + 1]));
        }
        delete[] arr;
        arr=0;

        cout << "please input new Interval to insert:" << endl;
        if(getline(cin, str)==0 || str.empty())        continue;
        arr = new int[str.size()]();
        n = splitStr2IntArray(str, arr);
        if(n < 2)        continue;
        Interval added(arr[0], arr[1]);
        
        displayIntervals(insert(intervals, added));
    }
    return;
}

int main(int, char**){
    test_01();
    return 0;
}
