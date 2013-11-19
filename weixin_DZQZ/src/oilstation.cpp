/*
 * porblem on Oct08
 * we have n oil statioin composing a loop.  oil[i] means the oil can be charged in station i, and cost[i] means the oil cost in the 
 * distance from [i] to [i+1](for [n-1], the next is [0])
 * assume our car has unlimited oil tank, ask whether can start from one station to run all of them
 *
 * test data:
 * oil{3,5,2,4,3,5,6,3}, cost{2,5,3,2,4,7,4,4}, n=8, yes, start=6
 * oli{3,5,2,4,3,5,2,4}, cost{2,5,3,2,4,7,3,2}, n=8, yes, start=7
 *
 * */

#include "../header/preliminary.h"

bool oilstation(int *oil, int *cost, int n, int& start){
    int tank=0;
    bool res=true;
    start = 0;
    for(int i=0;i<n;i++){
        tank += oil[i]-cost[i];
        if(tank < 0){
            res = false;
            start = -1;
        }else{
            if(!res){
                start = i;
                res = true;
            }
        }
    }
    return res;
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str)==0 || str.empty())
          break;
        int* oil = new int[str.size()]();
        int n1 = splitStr2IntArray(str, oil);

        str.clear();
        if(getline(cin, str)==0 || str.empty())
          break;
        int* cost = new int[str.size()]();
        int n2 = splitStr2IntArray(str, cost);

        if(n1 != n2){
            printf("input data is invalid!\n");
        }else{
            int begin=-1;
            bool res = oilstation(oil, cost, n1, begin);
            if(res){
                printf("Success routine is to start from %dth station\n", begin);
            }else{
                printf("Unable to run all of the stations\n");
            }
        }
        delete[] oil;
        oil=0;
        delete[] cost;
        cost=0;
    }
    return 0;
}
