/*
 * given a sorted array of integers, find the starting and ending position of a given target
 *
 * test case:
 * 1,1   x=1, x=0, x=2
 * 1,2,2,3,4,  x=3, x=2, x=4
 * 1,  x=1,0,2
 * */

#include "../include/preliminary.h"

vector<int> searchRange(int A[], int n, int x){
    vector<int> res;
    if(n==0 || (n==1 && x != A[0])){
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
    if(n==1 && x==A[0]){
        res.push_back(0);
        res.push_back(0);
        return res;
    }
    
    int v=0, u=n, m;
    while(v<u){
        m = (v+u)>>1;
        if(A[m]==x){
            break;
        }else if(A[m] > x){
            u=m;
        }else{
            v=m+1;
        }
    }
    if(v >= u){
        res.push_back(-1);
        res.push_back(-1);
        return res; 
    }
    int mid = m;
    if(m==0 || A[m-1]<x){
        res.push_back(m);
    }
    if(res.size() < 1){
        u=m;
        while(v<u){
            m = (v+u) >> 1;
            if(A[m] < x){
                if(A[m+1]==x){
                    res.push_back(m+1);
                    break;
                }else{
                    v = m+1;
                }
            }else{
                if(A[m-1]<x){
                    res.push_back(m);
                    break;
                }else{
                    u=m;
                }
            }
        }
    }
    if(res.size()<1){
        res.push_back(m);
    }

    if(mid==n-1 || A[mid+1] > x){
        res.push_back(mid);
        return res;
    }
    if(res.size()<2){
        v=mid, u=n;
        while(v<u){
            m = (v+u)>>1;
            if(A[m] > x){
                if(A[m-1]==x){
                    res.push_back(m-1);
                    break;
                }else{
                    u=m-1;
                }
            }else{
                if(A[m+1]>x){
                    res.push_back(m);
                    break;
                }else{
                    v=m+1;
                }
            }
        }
    }
    if(res.size()<2){
        res.push_back(m);
    }
    return res;
}

void test_01(){
    string str;
    while(1){
        printf("please input sorted integer array:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        
        printf("please input sorted integer array:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        int target = atoi(str.c_str());
        vector<int> res = searchRange(arr, n, target);
        for(size_t i=0;i<res.size();i++){
            printf("%d ", res[i]);
        }
        printf("\n");
        delete[] arr;
    }
}

int main(int, char**){
    test_01();
    return 0;
}

