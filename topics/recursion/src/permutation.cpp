/*
 * permutation
 * */
#include "../header/preliminary.h"
#include <vector>

void myswap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void quicksort(vector<int>& vect, int b, int e){        //sort in ascending
    if(b >= e)        return;
    int p=b-1, q=b;
    while(q<e){
        if(vect[q] < vect[e]){
            ++p;
            myswap(vect[p], vect[q]);
        }
        ++q;
    }
    ++p;
    myswap(vect[p], vect[e]);
    quicksort(vect, b, p-1);
    quicksort(vect, p+1, e);
}

void output(vector<int>& vec){
    int n = vec.size();
    for(int i=0;i<n;i++){
        cout<<vec[i]<<" ";
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
 *
 * take note that this solution skip duplicate numbers!!!
 * */
vector<vector<int> > perm(vector<int>& num){
    vector<vector<int> > res;
    int n = num.size();
    if(n==0)        return res;
    if(n==1){
        res.push_back(num);
        return res;
    }
    quicksort(num, 0, n-1);     //ensure src is asending    
    output(num);
    res.push_back(num);
    while(1){
        int j = n-1;
        for(;j>0 && num[j-1] >= num[j];--j);//reversely from tail, find first digit([j-1]) less than its right([j])
        if(j==0)    break;
        int t = n-1;
        while(t > j){
            if(num[t] > num[j-1])    break; //reversely from tail, find the first digit greater than [j-1], at least it is [j]
            t--;
        }
        myswap(num[t], num[j-1]);
        quicksort(num, j, n-1); //here sort the src[j:n) to set that part as ascending for later process
        res.push_back(num);
        output(num);
    }
    return res;
}

void test_01(){
    string str;
    while(1){
        cout<<"input integers to permute:"<<endl;
        if(getline(cin, str)==0 || str.empty())
          break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        vector<int> num;
        for(int i=0;i<n;++i){
            num.push_back(arr[i]);
        }
        perm(num);
        delete[] arr;
        arr = 0;
    }
    return;
}

/*
 * method without recursice
 * current logic is based on the source string in ascending, final is descending.
 * 123, 132, 213, 231, 312, 321
 * */
void Swap(char *a, char *b){        //swap char
    char t = *a;
    *a = *b;  
    *b = t;  
}

void Reverse(char *a, char *b){  
   while (a < b)  
       Swap(a++, b--);  
}  

bool Next_permutation(char *a){  
    char *pEnd = a + strlen(a);  
    if (a == pEnd)        return false;  
    char *p, *q, *pFind;  
    pEnd--;  
    p = pEnd;  
    while (p != a){  
        q = p; 
        --p;
        if (*p < *q){  
            pFind = pEnd;  
            while (*pFind <= *p){  
                --pFind;
            }
            Swap(pFind, p);  
            Reverse(q, pEnd);  
            return true;  
        }  
    }  
    Reverse(p, pEnd);  
    return false;  
}  
int QsortCmp(const void *pa, const void *pb){  
    return *(char*)pa - *(char*)pb;  
}  

void Perm2(char* src){
     //qsort(src, strlen(src), sizeof(src[0]), QsortCmp);  
     int i = 1;  
     do{  
        printf("%d, \t%s\n", i++, src);  // \t make the next item output align 
     }while (Next_permutation(src)); 
}

void test_02(){
    string str;
    while(1){
        cout << "input string to permute:" << endl;
        if(getline(cin, str)==0 || str.empty())        break;
        int n = str.size();
        char *cstr = new char[n + 1];
        for(int i = 0; i<n; ++i){
            cstr[i] = str[i];
        }
        cstr[n] = '\0';
        Perm2(cstr);
        
        delete[] cstr;
        cstr = 0;
    }
    return;
}

/*
 * permutation via recursion 
 * */

bool IsSwap(char *src, int b, int e){  
    for(int i = b; i < e; i++){
       if (src[i] == src[e])  return false;  
    }
    return true;  
}

int layer = 0;
// with recursive, with regard to avoid swap duplicate by call IsSwap()
void AllRange(char *src, int k, int m){    
    if (k < m){       
        for (int i = k; i <= m; i++){
            if(IsSwap(src, k, i)){
                if(k!=i){
                    printf("Swap %d and %d\n", k, i);
                    Swap(src + k, src + i);                  
                }            
                AllRange(src, k + 1, m);  //output string when k==m-1
                if(k != i){
                    Swap(src + k, src + i);
                }
            }
        }
    }
    return;
}  
   
void Perm3(char *src){  
    AllRange(src, 0, strlen(src) - 1);  
}  

int main(int, char**){
    test_02();
    return 0;
}
