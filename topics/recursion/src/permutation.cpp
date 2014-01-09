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
        for(;j>0 && num[j-1] >= num[j];--j);
        if(j==0)    break;
        int t = n-1;
        while(t > j){
            if(num[t] > num[j-1])
                break;
            t--;
        }
        myswap(num[t], num[j-1]);
        quicksort(num, j, n-1);        //here needs sort the src[j:count] instead of just iteration
        res.push_back(num);
        output(num);
    }
    return res;
}

int main(int, char**){
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
    }
    return 0;
}
