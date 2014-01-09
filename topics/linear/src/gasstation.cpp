/*
 * from oj.leetcode as well
 * we have n gas statioin composing a loop.  gas[i] means the gas can be charged in station i, and cost[i] means the gas cost in the 
 * distance from [i] to [i+1](for [n-1], the next is [0])
 * assume our car has unlimited gas tank, ask whether can start from one station to run all of them
 * 
 * linear algorithm with backtrack
 * 
 * test data:
 * gas{1,2,3,4,5}, cost{3,4,5,1,2}, n=5, start = 3
 * */

#include "../header/preliminary.h"
#include <vector>

int gasstation(vector<int>& gas, vector<int>& cost){
    int tank=0, i=0, start=-1, n=gas.size();
    while(1){
        if(i>=n)    i-=n;
        if(start != -1 && i==start)        break;
        tank += gas[i] - cost[i];
        if(tank<0){
            int j=i;
            i= start==-1 ? i: start;
            while(tank<0){        //careful about this loop block
                --i;
                if(i<0)     i+=n;
                if(i==j)    break;
                tank += gas[i] - cost[i];
            }
            if(i==j)    return -1;
            start = i;
            i=j+1;            
        }else{
            if(start==-1)    start=i;
            ++i;
        }
    }
    return start;
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        cout<<"input gas stations supply array:"<<endl;
        if(getline(cin, str)==0 || str.empty())
          break;
        int* arr = new int[str.size()]();
        int n1 = splitStr2IntArray(str, arr);
        vector<int> vgas;
        for(int i=0;i<n1;++i){
            vgas.push_back(arr[i]);
        }

        str.clear();
        cout<<"input cost array:"<<endl;
        if(getline(cin, str)==0 || str.empty())
          break;
        int* cost = new int[str.size()]();
        int n2 = splitStr2IntArray(str, cost);
        vector<int> vcost;
        for(int i=0;i<n2;++i){
            vcost.push_back(cost[i]);
        }

        if(n1 != n2){
            printf("input data is invalid!\n");
        }else{
            int res = gasstation(vgas, vcost);
            printf("routine should start at station %d\n", res);
        }
        delete[] arr;
        arr=0;
        delete[] cost;
        cost=0;
    }
    return 0;
}
