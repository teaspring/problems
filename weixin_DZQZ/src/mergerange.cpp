/*
 * problem on Oct14, 2013
 * given some ranges like [i,j], operations of below
 * 1. merge linked ones. 
 * e.g [1,2], [2,3], [2,4], [5,10], [5,7], [6,8]  => [1,4], [5,10]
 * 2. wash removing the one which is parent of some others
 * e.g [1,2], [1,3], [1,4], [5,8], [5,9], [6,8], [6,9] => [1,2], [6,8]
 * note: input data are not sorted already naturally
 *
 * */
#include "../header/preliminary.h"
#include <vector>
#include <algorithm>
#include <numeric>

struct interval{
    int s;    //start
    int e;  //end
    interval(int a, int b):s(a), e(b){}
    ~interval(){}
};

inline int max(int& a, int& b){
    return a>b ? a : b;
}

void displayranges(const vector<interval>& ranges){
    vector<interval>::const_iterator iter = ranges.begin();
    for(;iter != ranges.end();iter++){
        printf("[%d,%d] ", iter->s, iter->e);
    }
    printf("\n");
    return;
}

/*
 * comparable function for sort of STL
 * */
bool isfront(const interval& a, const interval& b){
    if(a.s == b.s){
        return a.e < b.e;
    }else{
        return a.s < b.s;
    }
}

vector<interval> merge(vector<interval>& ranges){
    sort(ranges.begin(), ranges.end(), isfront);
    displayranges(ranges);
    vector<interval> res;
    vector<interval>::const_iterator prev=ranges.begin(), iter=ranges.begin()+1;
    for(;iter <= ranges.end();iter++){
        if(iter == ranges.end() || iter->s > prev->e){            //exceed edge or unlinked
            int end = prev->e;
            for(vector<interval>::const_iterator tmp=prev+1;tmp != iter;tmp++){
                if(end < tmp->e){
                    end = tmp->e;
                }
            }                  
            res.push_back(interval(prev->s, end));        //for [1,3][1,4][5,10],[6,9],[7,8], merge to [1,4] [5,10] 
            prev = iter;
        }
    }
    return res;
}

vector<interval> wash(vector<interval>& ranges){
    sort(ranges.begin(), ranges.end(), isfront);
    vector<interval> res;
    vector<interval>::const_iterator prev=ranges.begin(), curr=prev+1;
    for(;curr != ranges.end();curr++){
        if(curr->s > prev->s){
            if(curr->e > prev->e){        //for [5,8],[5,9],[6,8],[6,9] skip [5,8],[5,9],[6,9]
                res.push_back(*prev);
            }                    //else curr->e == prev->e, prev is parent
            prev = curr;
        }                        //else curr->s == prev->s, curr is parent
    }
    res.push_back(*prev);       //insert the remaining prev
    return res;
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str)==0 || str.empty()){
            break;
        }
        int* arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        vector<interval> ranges;
        for(int i=0;i<n/2;++i){
            ranges.push_back(interval(arr[2*i], arr[2*i+1]));
        }
        vector<interval> res1 = merge(ranges);
        printf("the merge result is:\n");
        displayranges(res1);
        
        vector<interval> res2 = wash(ranges);
        printf("the wash result is:\n");
        displayranges(res2);
        
        delete[] arr;
        arr=0;
        res1.clear();
        res2.clear();
        ranges.clear();
    }
    return 0;
}
