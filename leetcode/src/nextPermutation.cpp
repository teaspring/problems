/*
 * implement next permutation, which rearranges numbers into lexicographically next greater permutation of numbers.
 * if such arrangement is not possible, it must be in accending order. the replacement is in-place
 * e.g 
 * 1,2,3 -> 1,3,2
 * 3,2,1 -> 1,2,3
 * 1,1,5 -> 1,5,1
 * 
 * */
#include "../header/preliminary.h"

void swap(int& a, int & b){
    int tmp = b;
    b = a;
    a = tmp;
    return;
}

void reverse(vector<int>& num){
    int n = num.size();
    for(int i=0;i<(n>>1); ++i){
        swap(num[i], num[n-1-i]);
    }
    return;
}

void quicksort(vector<int>& vec, int b, int e){  //sort [b,e]
    if(b >= e)    return;
    int p=b-1, q=b;
    while(q < e){
        if(vec[q] < vec[e]){
            ++p;
            swap(vec[p], vec[q]);
        }
        ++q;
    }
    ++p;
    swap(vec[p], vec[e]);
    quicksort(vec, b, p-1);
    quicksort(vec, p+1, e);
}

void nextPermutation(vector<int> &num){
    int n = num.size();
    /*
    int i=n-1, j=i-1;   //abandoned code block, it is in tim O(n^2), replaced by O(n) 
    for(; i>0; --i){
        j=i-1;
        for(; j>=0 && num[j] >= num[i]; --j);    //stops at [j] < [i] 
        if(j>=0)    break;
    }
    swap(num[j], num[i]);
    */
    int i=n-2;
    for(; i>=0 && num[i] >= num[i+1]; --i);
    if(i<0){
        reverse(num);
        return;
    }
    int j=n-1;
    while(j > i+1){ //at least, j==i+1
        if(num[j] > num[i])    break;
        --j;
    }
    swap(num[i], num[j]);
    quicksort(num, i+1, n-1);
    return;
}

int main(int, char**){
    string str;
    while(1){
        printf("please input integer array:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        vector<int> nums;
        for(int i=0;i<n;i++){
            nums.push_back(arr[i]);
        }
        nextPermutation(nums);
        for(int i=0;i<n;i++){
            printf("%d ", nums[i]);
        }
        printf("\n");

        delete[] arr;
    }
    return 0;
}
