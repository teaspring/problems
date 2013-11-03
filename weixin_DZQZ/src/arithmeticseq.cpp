/*
* question on Sep05. it is a little complicated and be splited to some sub question
* complete in 4 hours
* test case:
  1 2 3 4 5     ascending
  2 1 0 -1 -2     decending
  1 1 1 1 1 0     step==0
  2 1 0 1 -1 2 0 0 0 1 0    mixed
*/
#include "../header/preliminary.h"

inline int absolute(int x){
    if(x < 0)    return 0-x;
    else    return x;
}
/*
* bi-search the integer array. return index if yes.return -1 if no
*/
int bisearch(int *arr, int n, int x, int asc){    //decending
    if(n<1)    return -1;
    if(n == 1)
    return arr[0] == x ? 0 : -1;
    int v=0, u=n, m=0;
    while(v<u){
        m = (v+u)/2;
        if(arr[m]==x)
          return m;
        else{        
            if(asc){            //ascending
                if(arr[m]<x)     v = m+1;
                else    u = m;
            }else{            //decending
                if(arr[m]>x)     v = m+1;
                else     u = m;
            }
        }
    }
    if(v>n-1)    
      return -1;
    return    arr[v]==x ? v : -1;
}

/*
* given sorted integer array, either decending or ascending
* time O(n^2lgn), space O(1)
* it is unable to handle case of step==0, as bisearch is wrong, traverse must be used, leading to O(n^3)
*/
int arithmeticSorted(int *arr, int n, int& start, int& step){
    int asc = 0;
    if(n>1 && (arr[1]-arr[0])>0)
        asc = 1;
    int d = absolute(arr[n-1]-arr[0])/2;
    int resLen = 1;

    for(int i=0;i<n;++i){
        for(int k=1;k<=d;k++){
            int s = i;
            int count = 0;
            int next = 0;
            int t = arr[s];
            while(next > -1){        //next is relative, s is absolute
                ++count;
                if(asc)
                  t += k;
                else
                  t -= k;
                s += next+1;
                next = bisearch(arr+s,n-s,t,asc);    //bi-search process a lot of duplicate value
            }
            if(count > resLen){
                start = i;
                step = asc ? k : 0-k;
                resLen = count;
            }
        }
    }
    return resLen;
}

/*
* time O(n^2), space (n^2)
*/
int arithmeticLinear(int *arr, int n, int& end, int& step){
    int max=0, min=0;
    for(int i=0;i<n;++i){
        if(arr[i] > max) 
            max = arr[i];
        else if(arr[i] < min)  
            min = arr[i];
    }
    int d = (max-min)/2;
    int maxLen = 1;
    int*** stepCount = new int**[2];
    for(int k=0;k<2;++k){        //[0] for positive step, [1] for negative
        stepCount[k] = new int*[n];
        for(int i=0;i<n;++i){
            stepCount[k][i] = new int[d+1]();    //allow step == 0
            for(int j=0;j<d+1;++j){    //stepCount[k][i][j] is the max arith progression length from arr[i] to arr[0], in step of j
            stepCount[k][i][j] = 1;        //default length is 1
            }
        }
    }
    for(int i=1;i<n;++i){
        for(int j=i-1; j>-1;--j){            
            int s = arr[i] - arr[j];
            if(absolute(s)>d)    continue;   
            int** ppCount = 0;       
            if (s<0)    
                ppCount = stepCount[1];
            else
                ppCount = stepCount[0];        // s==0 belong to positive step
            s = absolute(s);
            if(ppCount[i][s] < ppCount[j][s]+1){    //s is not different every time definitely
                ppCount[i][s] = ppCount[j][s]+1;
                if(ppCount[i][s]>maxLen){
                    maxLen = ppCount[i][s];
                    end = i;
                    step = arr[i] - arr[j];
                }
            }    
            ppCount = 0;
        }
    }

    for(int k=0;k<2;++k){
        for(int i=0;i<n;++i){        //delete temporary data structure
            delete[] stepCount[k][i];
            stepCount[k][i] = 0;
        }
        delete[] stepCount[k];
        stepCount[k] = 0;     
    }
    delete[] stepCount;   
    stepCount = 0;
    return maxLen;
}

int main(int argc, char *argv[]){
    string str;
    while(1){
        if(getline(cin, str) ==0 || str.empty())
            break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        int b=0, d=0, l=0;
        l = arithmeticSorted(arr, n, b, d);    //sorted, either ascending or decending
        printf("arithmeticSorted(): the longest arith progression is ");
        for(int i=0;i<l;++i)
            printf(" %d", arr[b]+i*d);
        printf("\n");

        int e=0;
        d=0;
        l = arithmeticLinear(arr, n, e, d);   
        printf("arithmeticLinear(): the longest arith progression is ");
        for(int i=0;i<l;++i)
            printf(" %d", arr[e]-(l-1-i)*d);
        printf("\n");
   
        delete[] arr;
        arr = 0;
    }
    return 0;
}
