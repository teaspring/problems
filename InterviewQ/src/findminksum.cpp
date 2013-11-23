/*
 * given two sorted integer array A[] and B[], for S = {A[i] + B[j]}, find the min k sum
 *
 * min heap is perfect data structure. and pay attention to the inserted elements in every round
 *
 * test data:
 * {1,2,3,4}, {20,30,40}, k=7
 * */

#include "../header/preliminary.h"

struct hNode{
    int a;
    int b;
    int sum;
    hNode(int i, int j, int r):a(i),b(j),sum(r){}
    ~hNode(){}
};

/*
 * for overload operator:
 * assignment should be defined inside class
 * arithmetic and relational operator function are defined outside class 
 * */
bool operator<(const hNode lhd, const hNode rhd){
    return lhd.sum < rhd.sum;
}

inline int Left(int i){
    return 2*i;
}

inline int Right(int i){
    return 2*i+1;
}

inline int Parent(int i){
    return i/2;
}

void myswap(hNode *pa, hNode *pb){
    hNode tmp = *pb;
    *pb = *pa;
    *pa = tmp;
}

template<typename T>
T minpop(T *A, int& size, int n){
    T res = A[1];
    A[1]=0;
    int i = 1;
    while(i<size){
        int l = Left(i);
        int r = Right(i);
        int less = i;
        if(l<=size && A[l] != 0){
            less = l;
        }
        if(r<=size && A[r] != 0){
            if(A[less]==0 || *(A[r]) < *(A[less])){
                less = r;
            }
        }
        if(less == i)
          break;
        if(A[i]==0){                //swap [less] and [i], and A[less] will not be 0 now
            A[i] = A[less];
            A[less] = 0;
        }else{
            myswap(A[less], A[i]);
        }
        i = less;
    }
    --size;
    return res;
}

template<typename T>
void mininsert(T *A, int n, int& size, T ele){                        //there will be 0 element in array 
    if(size > n)
      return;
    int i=size+1;
    A[i] = ele;
    while(i>1){                                //move A[i] upwards if it is less than parent
        int p = Parent(i);
        if(p>0 && *(A[p]) < *(A[i]))        //for insertion, [p] will not be 0
          break;
        myswap(A[p], A[i]);
        i = p;
    }
    ++size;
    return;
}

void display(hNode* pnode, int* A, int* B){
    printf("A[%d] + B[%d] = %d\n", pnode->a, pnode->b, A[pnode->a]+B[pnode->b]);
    return;
}

void displayheap(hNode** ppheap, int n, int *A, int *B){            //for debug
    printf("currently the heap is:\n");
    for(int i=1;i<n;i++){
        if(ppheap[i] == 0)
          break;
        hNode* tmp = ppheap[i];
        printf("%d: A[%d] + B[%d] = %d\n",i, tmp->a, tmp->b, A[tmp->a]+B[tmp->b]);        
    }
    return;
}

void findminksum(int *A, int m, int *B, int n, int k){
    int count=0;
    int* xA = new int[m]();                        //xA[i] means for A[i], the next optional pair index in B
    hNode** minheap = new hNode*[k+1];            //heap in array, root is [1]
    memset(minheap, 0, sizeof(hNode*)*k);
    int s = 0;
    mininsert(minheap, k, s, new hNode(0,0,A[0]+B[0]));
    while(count<k){
        hNode* root = minpop<hNode*>(minheap, s, k);
        ++count;
        display(root, A, B);
        int i = root->a;
        if(xA[i] < n-1){
            xA[i]++;
            mininsert<hNode*>(minheap, k, s, new hNode(i, xA[i], A[i]+B[xA[i]]));
        }
        if(xA[i]==1 && i<m-1){
            mininsert<hNode*>(minheap, k, s, new hNode(i+1, 0, A[i+1]+B[0]));
        }
        delete root;                //release the unused object
        root = 0;
    }

    for(int i=0;i<k;i++){
        if(minheap[i] != 0){
            delete minheap[i];
            minheap[i] = 0;
        }
    }
    minheap = 0;
    delete[] xA;
    xA=0;
    return;
}

/*
 * input array should be sorted already in ascending
 * */
int main(int argc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str)==0 || str.empty())
          break;
        int *arr1 = new int[str.size()]();
        int n1 = splitStr2IntArray(str, arr1);

        if(getline(cin, str)==0 || str.empty())
          break;
        int *arr2 = new int[str.size()]();
        int n2 = splitStr2IntArray(str, arr2);
        
        if(getline(cin, str)==0 || str.empty())
          break;
        int k = atoi(str.c_str());
        findminksum(arr1, n1, arr2, n2, k);
        
        delete[] arr1;
        arr1 = 0;
        delete[] arr2;
        arr2 = 0;
    }
    return 0;
}
