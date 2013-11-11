/*
 * from one interview of twitter published on blog.jobbole.com
 * given an integer array which means height of walls. it rains, some water can be kept in the hole between walls. ask the amout of kept rain
 *
 * test data:
 * 2 5 1 2 3 4 7 7 6
 * 2 5 1 3 1 2 1 7 7 6
 * 2 0 1 3 2 4 1 2
 * 4 3 2 1 0 1 2 4        good test case
 * */
#include "../header/preliminary.h"

int max(int a, int b){
    return a > b ? a : b;
}

int min(int a, int b){
    return a < b ? a : b;
}

/*
 * my solution, twice iterations, 1st is from left to right,2nd is reverse
 * */
int rainwall(int* arr, int n){
    int sum1 = 0, w1=0;
    for(int i=1;i<n;i++){
        int h = arr[w1];
        if(arr[i] >= h){        
            for(int j=w1+1; j<i; j++){
                sum1 += (h > arr[j] ? h-arr[j] : 0);
            }
            w1 = i;
        }
    }
    int sum2 = 0, w2=n-1;
    for(int i=n-2;i>=0;i--){
        int h = arr[w2];
        if(arr[i] >= h){
            for(int j=w2-1;j>i;j--){
                sum2 += (h > arr[j] ? h-arr[j] : 0);
            }
            w2 = i;
        }
    }
    if(w1 != w2){                    //two options: [w1, w2] are continuous all same height, or w1, w2 are the two highest wall with same height 
        int i=max(w1, w2)-1;
        int j=min(w1, w2)+1;
        for(;arr[i]==arr[w1] && i>=j;i--);
        if(i >= j)
          return max(sum1, sum2);
    } 
    return sum1 + sum2;
}

/*
 * author's solution, one iteration
 * */
int rainwall02(int* arr, int n){
    int pl=0, pr=n-1;
    int maxl=arr[pl], maxr=arr[pr];
    int volume=0;
    while(pr > pl){                    //avoid duplicate
        if(maxl < maxr){            //move from the lower side wall, it ensures the wall can be height of water
            pl++;
            if(arr[pl] >= maxl){
                maxl = arr[pl];
            }else{
                volume += maxl - arr[pl];
            }
        }else{
            pr--;
            if(arr[pr] >= maxr){
                maxr = arr[pr];
            }else{
                volume += maxr - arr[pr];
            }
        }
    }
    return volume;
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str) == 0 || str.empty())
          break;
        int* arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        int w1 = rainwall(arr, n);
        int w2 = rainwall02(arr, n);
        printf("the kept water is Solution1: %d, Solution2: %d \n", w1, w2);

        delete[] arr;
        arr =0;
    }
    return 0;
}
