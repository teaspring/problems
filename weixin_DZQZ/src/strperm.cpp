/*
 * problem on Sep29
 * given string A, and string B, ask if the permutation of B's char is substring of A
 * 
 *
 * test data:
 * A: abefg, B: ba, output: true
 * */
#include "../header/preliminary.h"

template<typename T>
void myswap(T* pa, T* pb){
    T tmp = *pb;
    *pb = *pa;
    *pa = tmp;
    tmp = 0;
}

template<typename T>
void quicksort(T* arr, int n){		//sort in ascending
    if(n<1)	return;
    T *p=arr-1, *q=arr;
    T s = *(arr+n-1);
    while(q<arr+n-1){
        if(*q < s){
            ++p;
            myswap<T>(p, q);
        }
        ++q;
    }
    ++p;
    myswap<T>(p, q);
    quicksort<T>(arr, p-arr);
    quicksort<T>(p+1, n-1-(p-arr));
}

template<typename T>
void output(T* arr, int count){
    for(int i=0;i<count;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
}

/*
 * permutation, e.g. 1 2 3 4
 * 1 2 3 4
 * 1 2 4 3
 * 1 3 2 4
 * 1 3 4 2
 * 1 4 2 3
 * 1 4 3 2 
 * 2 1 3 4 ...
 * */
template<typename T>
void perm(T* src, int count){
    quicksort<T>(src, count);				//ensure src is asending
    output<T>(src, count);
    while(1){
        int j = count-1;
        for(;j>0 && src[j]<=src[j-1];j--);
        if(j==0)	break;
        int t = count-1;
        while(t > j){
            if(src[t] > src[j-1])
                break;
            t--;
        }
        myswap<T>(src+t, src+j-1);
        quicksort<T>(src+j, count-j);		//here needs sort the src[j:count] instead of just iteration
        output<T>(src, count);
    }
}

template<typename T>
int mycmp(T* arrA, T* arrB, int n){
    for(int i=0;i<n;i++){
        if(arrA[i] == arrB[i])
	    continue;
        else if(arrA[i] > arrB[i])
	    return 1;
        else
	    return -1;
    }
    return 0;
}

/*
 * for this problem, permutation of cstrB to search in cstrA is brute-force without optimize
 * */
bool substrmatch_1(char* srcA, char* srcB){
    int m = strlen(srcB);
    char* cstrB = new char[m+1];
    memset(cstrB, 0, sizeof(char)*(m+1));
    strcpy(cstrB, srcB);
    cstrB[m] = '\0';

    quicksort<char>(cstrB, m);
    bool res = false;
    if(strstr(srcA, cstrB) != NULL)
        return true;
    while(1){								    //get permutation of cstrB, check if it exists in cstrA
        int j = m-1;
        for(;j>0 && cstrB[j]<=cstrB[j-1];j--);
        if(j==0)	break;
        int t = m-1;
        while(t > j){
            if(cstrB[t] > cstrB[j-1])
                break;
            t--;
        }
        myswap<char>(cstrB+t, cstrB+j-1);
        quicksort<char>(cstrB+j, m-j);		//here needs sort the src[j:count] instead of just iteration
        if(strstr(srcA, cstrB) != NULL){	    //strstr() is time O(m) factually
            res = true;
            break;
        }
    }
    delete[] cstrB;
    cstrB = 0;
    return res;
}

/*
 * optimized solution introduced by author, based on analysis of the search
 * time O(mlgm + nlgn + (n-m+1)m) = O()
 * */
bool substrmatch_2(char* srcA, char* srcB){
    int n = strlen(srcA), m = strlen(srcB);
    char* cstrA = new char[n+1];
    memset(cstrA, 0, sizeof(char)*(n+1));
    strcpy(cstrA, srcA);
	
    char* cstrB = new char[m+1];
    memset(cstrB, 0, sizeof(char)*(m+1));
    strcpy(cstrB, srcB);

    quicksort(cstrB, m);
    quicksort(cstrA, m);
    bool res = false;
    int s = 0;
    while(1){
        if(mycmp<char>(cstrA+s, cstrB, m) == 0){				//compare string, time O(m)
            res = true;
	    break;
	}
        s++;
        if(s > n-m)		break;
        int i=0;
        for(;i<m-1 && cstrA[s+i] <= cstrA[s+m-1];i++);
        if(i<m-1){
            char tmp = cstrA[s+m-1];
            for(int j=s+m-1; j>i;j--)
                cstrA[s+j] = cstrA[s+j-1];
	    cstrA[s+i] = tmp;
	}
    }
	
    delete[] cstrA;
    cstrA = 0;
    delete[] cstrB;
    cstrB = 0;
    return res;
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str)==0 || str.empty())
            break;		
        char* arrA = new char[str.size()];
        strcpy(arrA, str.c_str());
		
        if(getline(cin, str)==0 || str.empty())
            break;
        char* arrB = new char[str.size()];
        strcpy(arrB, str.c_str());
		
        bool res = substrmatch_1(arrA, arrB);
        printf("method1 result is %s\n", res ? "true" : "false");        
        res = substrmatch_2(arrA, arrB);
        printf("method2 result is %s\n", res ? "true" : "false");
		
		delete[] arrA;
        arrA = 0;
        delete[] arrB;
        arrB = 0;
    }
    return 0;
}

