/*
 * <IntroductionToAlgorithm> exercise 8-4
 * given n red jugs and n blue jugs, all of different shapes and sizes.For every red jug, there is blue jug has the same capacity of water
 * with it.    assume you have a unit operation of selecting one red jug and pour its water into another blue jug. 
 * Q: group all the red jugs and blue jugs in time O(nlgn)
 *
 * test data:
 * 1,3,10,8,12,5,15,7,2,11
 * 5,2,11,3,8,12,1,15,10,7
 * */
#include "../header/preliminary.h"

template<typename T>
void swap(T* pa, T* pb){
    T tmp = *pb;
    *pb = *pa;
    *pa = tmp;
    tmp=0;
}

void sortjugs(int *A, int *B, int n){
    if(n<2)
      return;
    int *p=B, *q=B-1,t=A[n-1], *S=0;
    while(p<B+n){                //quick sort B[] with sentinel of A[n-1]
        while(p<B+n && *p > t){
            p++;
        }
        if(p<B+n){
            if(*p==t){
                S=p;
            }else{                //*p < t
                q++;
                if(S==q)
                  q++;
                swap<int>(p,q);
            }
            p++;
        }
    }
    if(S<q){
        while(S < q){
            *S = *(S+1);
            S++;
        }
        *S = t;                    //S moves to q+1
        q = S-1;
    }else{
        while(S > q+1){            //S moves to q+1
            *S = *(S-1);
            S--;
        }
        *S = t;
    }
    
    p=A;                        //quick sort A[] with sentinel of B[S]
    q=A-1;
    t = *S;
    while(p<A+n-1){
        while(p<A+n-1 && *p>t){
            p++;
        }
        if(p<A+n-1){
            q++;
            swap<int>(p,q);
            p++;
        }
    }
    q++;
    swap<int>(p,q);
    if(S-B != q-A){
        printf("error!!!\n");
        return;
    }
    sortjugs(A,B,S-B);
    sortjugs(q+1,S+1,n-1-(S-B));
    p=0,q=0,S=0;
}

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
        if(n1 != n2){
            printf("different count of red jugs and blue jugs!!!\n");
        }else{
            sortjugs(arr1, arr2, n1);
            printf("red jugs:");
            for(int i=0;i<n1;i++){
                printf(" %d", arr1[i]);
            }
            printf("\n");
            printf("blue jugs:");
            for(int i=0;i<n1;i++){
                printf(" %d", arr2[i]);
            }
            printf("\n");                
        }
        delete[] arr1;
        arr1=0;
        delete[] arr2;
        arr2=0;
    }
    return 0;
}
