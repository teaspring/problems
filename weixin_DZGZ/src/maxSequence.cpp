/* 
 * question on Jul 19: 
 * one array of all 0 and 1, calculate the longest sequence with the same counts of 0 and 1
 * 
 * test data:
 * 1 1 1 1 0 0 0 0    returns 8
 * 1 1 1 1 0 0 0 1    returns 6
 * 1 1 0 1 0 0 0 0 1
 * */
#include "../header/preliminary.h"
using namespace std;

/*
 * target sequence begin from arr[0]
 * return: length of longest balance sequence
 * */
int longestBalanceSequence(int arr[], int N){
    int sum=0;
    for(int i=0;i<N;i++)
        sum += (arr[i]==0)? (-1) : 1;
    if(sum==0)    return N;
    for(int i=N-1;i>0;i--){
        sum -= (arr[i]==0)? (-1) : 1;
        if(sum == 0)
          return i;                //return length
    }
    return 0;
}

/*
 * no limit of the sequence beginning from where
 * */
int longestBalanceSequenceExt(int* arr, int N){
    int* subSum = new int[N]();    
    subSum[0] = (arr[0]==0) ? -1 : 1; 
    for(int i=1;i<N;i++){
        subSum[i] = subSum[i-1] + (arr[i]==0? -1 : 1);
    }
    int longest = 0;
    for(int cur=-1;cur<N && (N-cur)>longest;cur++){    //if arr[i]==0, it is balanced serial from head
        int tmp = (cur==-1)? 0 : subSum[cur];
        int j=N-1;
        for(;j>cur && subSum[j] != tmp;j--);
        if(j==cur)    continue;
        if((j-cur) > longest)    longest=(j-cur);        
    }
    delete[] subSum;
    subSum = 0;
    return longest;
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str)==0 || str.empty()) 
          break;
        int* arr = new int[str.size()]();
        int len = splitStr2IntArray(str, arr);
        int res = longestBalanceSequenceExt(arr, len);
        printf("the longest balance sequence length is %d\n", res);

        delete[] arr;
        arr = 0;
    }
    return 0;
}
