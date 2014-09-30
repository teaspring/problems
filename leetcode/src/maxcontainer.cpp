/*
 * given n non-negative integers a1,a2...an, where each represents a point at (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at(i, ai) and (i,0). For two lines , which together with x-axis forms a container, such that the container
 * contains the most water.
 * */
#include "../include/preliminary.h"

int maxArea(vector<int> &height){
    int s=0, e=height.size()-1;
    if(e<1)        return 0;
    int area = 0;
    int maxL=0, maxR=0;
    while(s<e){
        int tmp = min(height[e], height[s])*(e-s);        //min() is in <algorithm>
        if(area < tmp)    area = tmp;
        maxL = height[s];
        maxR = height[e];
        if(height[s] < height[e]){
            s++;
            while(s<e && height[s] <= maxL)    s++;    //skip hopeless points
        }else{
            e--;
            while(s<e && height[e] <= maxR)    e--;    //skip hopeless points 
        }     
    }
    return area;
}

int main(int, char**){
    string str;
    while(1){
        cout<<"please input integer array:"<<endl;
        if(getline(cin, str)==0 || str.empty())        break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        vector<int> num;
        for(int i=0;i<n;i++){
            num.push_back(arr[i]);
        }
        printf("max area is %d\n", maxArea(num));
    }
    return 0;
}

