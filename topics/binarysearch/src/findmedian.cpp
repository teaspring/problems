/*
* integer array A[m], B[n] are sorted in ascending both, find the median of all integers in time O(lg(m+n))
* 
* note: 
* 1.case of m==n is in <IntroductionToAlgorithm> chapter9 median and order statistics, exercise 9.3-8
* 2.case of m!= n is an interview problem
* 
* test case:
*
* -----m==n------
* {1}, {1}
* {1,2}, {3,4}
* {1,3}, {2,4}
* {1,2}, {1,2}
* {1,4}, {2,3}
* 
* -----unnecessarily m equaling to n------
* {1,3,5,8}, {2,4,6,7}
* {1,1}, {2,3,4,5}
* {}, {1,2,3,4}
* {1,2,3}, {}
* {1}, {1}
* {1,2,3,5,6}, {4}
* {1}, {2,3,4}
* {1}, {2,3,4,5}
* {1,2,3,4}, {5}
* {2}, {1,3,4}
* {3}, {1,2,4}
* {1,2,3}, {4,5}
* {6,7,8}, {1,2,3,4,5}
*/

#include "../header/preliminary.h"

/*
 * sorted array A[m] and B[n]
 * */
bool findmediansingle(int *A, int m, int *B, int n, double& res, int tag){
    if(m==0 && n==0){
        return false;
    }else if(n==0){
        res = tag==1 ? A[m/2] : (double)(A[m/2] + A[m/2 - 1])/2;
        return true;
    }else if(m==0){
        res = tag==1 ? B[n/2] : (double)(B[n/2 -1] + B[n/2])/2;
        return true;
    }

    int u=m, v=0, i=0;
    int mid = (m+n)/2;
    if(tag==0){
        while(v<u){               //[v,u)
            i = (v+u)/2;
            int j=(mid-1-i);      //index in B[]
            if(j<-1){
                u=i;              //reduce k to enlarge j
            }else if(j==-1){    //it means all elements in A[] less than A[i] add up to mid
                if(B[0] >= A[i]){    //B[0] is above A[i], out of mid elements below A[i], A[i] is floor of the middle two
                    int high = A[i];
                    int low = i>0 ? A[i-1] : 0;
                    res = (double)(high + low)/2;
                    return true;
                }
                break;
            }else if(j>n-1){    //enlarge k to reduce j
                v=i+1;            
            }else if(A[i] <= B[j]){    //we need to find the middle two elements among the total merged array
                if(j==0 || A[i] >= B[j-1]){ //all elements less than A[i] and B[j] adds up to mid
                    int low = A[i];     //since we focus binary cursor on i, A[i] is fixed as floor of the two middle
                    int high = B[j];
                    if(i<m-1 && A[i+1]<B[j]){  //A[i+1] is closer to A[i] then B[j]
                        high = A[i+1];
                    }
                    res = (double)(low + high)/2;
                    return true;
                }else{
                    v=i+1;    //enlarge i to reduce j
                    continue;
                }
            }else{  //A[i] > B[j]
                if(j==n-1 || A[i] <= B[j+1]){
                    int high = A[i];    //now we fix A[i] as ceil of the two middle
                    int low = B[j];
                    if(i>0 && B[j] < A[i-1]){    //A[i-1] is closer to A[i] than B[j]
                        low = A[i-1];
                    }
                    res = (double)(low+high)/2;
                    return true;
                }else{
                    u = i;    
                    continue;
                }
            }
        }
        return false;
    }else{
        while(v<u){               //[v,u)
            i = (v+u)/2;
            int j=(mid-1-i);      //index in B[]
            if(j<-1){
                u=i;              //reduce k to enlarge j
            }else if(j==-1){  //it means all elements in A[] less than A[i] add up to mid
                if(B[0] >= A[i]){  //B[0] is out of the mid elements below A[i], A[i] is the middle of all
                    res = (char)A[i];
                    return true;
                }
                break;
            }else if(j>n-1){    //enlarge k to reduce j
                v=i+1;  
            }else if(A[i] >= B[j]){    //1.A[i] and B[j] are middle two; 2.max(A[i], B[j]) is middle of all
                if(j==n-1 || A[i] <= B[j+1]){
                    res = (double)A[i];
                    return true;
                }else{
                    u=i;    //reduce i
                }
            }else{
                if(i==m-1 || B[j] <= A[i+1]){
                    res = (double)B[j];        //we need max(A[i], B[j])
                    return true;
                }else{
                    v=i+1;    //enlarge i
                }
            }
        }
        return false;
    }
}

double findmedian(int* A, int m, int* B, int n){
    double res = 0.0;
    int tag=0;
    if((m+n)%2 == 1)
      tag=1;            //1 for odd total count, 0  for even
    if(!findmediansingle(A,m,B,n,res,tag)){
        findmediansingle(B,n,A,m,res,tag);
    }
    return res;
}

/*
 * for two arrays with same size
 * */
bool findmediansingle(int* A, int* B, int n, double& res){  // find total median in array A
    int u=n, v=0;
    while(v<u){        //[v,u)
        int i = (v+u)/2;
        int j = n-1-i;      //index in B[]
        if(A[i] <= B[j]){    //we need to find the middle two elements among the total merged array
            if(j==0 || A[i] >= B[j-1]){ //all elements less than A[i] and B[j] adds up to mid
                int low = A[i];     //since we focus binary cursor on i, A[i] is fixed as floor of the two middle
                int high = B[j];
                if(i<n-1 && A[i+1]<B[j]){  //A[i+1] is closer to A[i] then B[j]
                    high = A[i+1];
                }
                res = (double)(low + high)/2;
                return true;
            }else{
                v=i+1;    //enlarge i to reduce j
                continue;
            }
        }else{  //A[i] > B[j]
            if(j==n-1 || A[i] <= B[j+1]){
                int high = A[i];    //now we fix A[i] as ceil of the two middle
                int low = B[j];
                if(i>0 && B[j] < A[i-1]){    //A[i-1] is closer to A[i] than B[j]
                    low = A[i-1];
                }
                res = (double)(low+high)/2;
                return true;
            }else{
                u = i;    
                continue;
            }
        }
    }
    return false;
}

/*
 * for two arrays with same size
 * */
double findmedian(int* A, int* B, int n){
    double res = 0.0;
    if(!findmediansingle(A, B, n, res)){
        findmediansingle(B, A, n, res);
    }
    return res;
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        cout<<"input 1st sorted int array:"<<endl;
        getline(cin, str);
        int* arr1 = new int[str.size()]();
        int m = splitStr2IntArray(str, arr1);
    
        str.clear();
        cout<<"input 2nd sorted int array:"<<endl;
        getline(cin, str);
        int* arr2 = new int[str.size()]();
        int n = splitStr2IntArray(str, arr2);
        //double r = findmedian(arr1, arr2, n);
        //printf("the median of all the integers is %.1f\n", r);
        
        double r = findmedian(arr1,m,arr2,n);
        printf("the median of all the integers is %.1f\n", r);        
        
        delete[] arr1;
        arr1 = 0;
        delete[] arr2;
        arr2 = 0;    
    }
    return 0;
}
