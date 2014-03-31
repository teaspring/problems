/*
 * merge:
 * given a collection of intervals, merge all overlapping intervals.
 * 
 * test cases:
 * given  [1,3], [2,6], [8,10], [15,18]
 * return [1,6], [8,10], [15,18]
 *
 * given [1,3], [2,4]
 * */
#include "../header/preliminary.h"

struct Interval{
    int start;
    int end;
    Interval():start(0), end(0){}
    Interval(int s, int e):start(s), end(e){} 
};

bool cmpInterval(const Interval& i1, const Interval& i2){ //for ascending order
    if(i1.start == i2.start){
        return i1.end < i2.end;
    }else{
        return i1.start < i2.start;
    }
}

void displayIntervals(const vector<Interval>& intervals){
    for(vector<Interval>::const_iterator iter = intervals.begin();
        iter < intervals.end();
        ++iter){
        printf("[%d, %d] ", iter->start, iter->end);
    }
    printf("\n");
}

typedef bool (cmpFcn)(const Interval&, const Interval&);  //function pointer for compare function of Interval

void my_swap(Interval& i1, Interval& i2){
    Interval tmp(i2.start, i2.end);
    i2.start = i1.start;
    i2.end   = i1.end;
    i1.start = tmp.start;
    i1.end   = tmp.end;
    return;
}

void my_quicksort(vector<Interval>& intervals, int s, int e, cmpFcn cmp){  // range of [s, e]
    if(s >= e)    return;
    int q = s-1, p = s, t = e;
    while(p < t){
        if(cmp(intervals[p], intervals[t])){ //cmp() return true if i1 is less than i2, so i1 should be swapped to head
            ++q;
            my_swap(intervals[q], intervals[p]);
        }
        ++p;
    }
    ++q;
    my_swap(intervals[q], intervals[p]);
    my_quicksort(intervals, s, q-1, cmp);
    my_quicksort(intervals, q+1, e, cmp);
}

vector<Interval> merge(vector<Interval>& intervals){
    //sort(intervals.begin(), intervals.end(), cmpInterval);  //std::sort(), <algorithm>
    my_quicksort(intervals, 0, intervals.size()-1, cmpInterval);
    displayIntervals(intervals);
    vector<Interval> res;
    for(vector<Interval>::const_iterator iter = intervals.begin();
        iter != intervals.end();
        ++iter){
        if(res.empty()){
            res.push_back(Interval(iter->start, iter->end));
            continue;
        }
        int m = res.size();
        if(res[m-1].end >= iter->start){
            res[m-1].end = max(res[m-1].end, iter->end);
        }else{
            res.push_back(Interval(iter->start, iter->end));
        }
    }
    return res;
}

void test_01(){  // test merge()
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
        displayIntervals(merge(intervals));
    }
    return;
}

int main(int, char**){
    test_01();
    return 0;
}
