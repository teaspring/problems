/*
 * given an array and a value, remove all instances of that value in place and return the new length
 * */

class Solution{

public:
    int removeElement(int A[], int n, int elem){
        int i = -1, j = 0;
        for(; j < n; ++j){ // once scan of quick sort, elem is used as sentinel
            if(A[j] == elem)    continue;
            A[++i] = A[j];
        }
        return i+1;
    }
};

