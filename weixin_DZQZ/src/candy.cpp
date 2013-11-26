/*
 * problem on Oct 04,2013 
 * we have several children to give candy. Assume each child is assigned an integer weight.
 * rule: nobody can have no candy. for any adjacent children, the one with higher weight must have more candy than neighbors. 
 * ask the minimum candy
 *
 * test data:
 * weights: 1,2,1,3,2,4,6,9,5 
 * candy:   1,2,1,2,1,2,3,4,1
 *
 * weights: 1,2,4,3,2,1,8
 *
 * solution: for each segment of single side trend, we give candy starting from 1 increasingly
 * */

#include "../header/preliminary.h"

/*
 * my own solution, time O(n), space O(n)
 * */
int distributecandy(int* W, int n){
    if(n==0)
      return 0;
    else if(n==1)
      return 1;
    
    int *candy = new int[n]();
    int *p = W, *q = W+1;
    while(q != W+n){
        while(q < W+n && (*q - *(q-1))*(*(p+1) - *p)>0){        //[p,q) are single side trend
            ++q;
        }
        int *s = candy, *e = candy;     //s is trouhg, e is peak
        if(*(q-1) > *p){        
            s += (p-W);     //s<e
            e += (q-1-W);
        }else{
            s += (q-1-W);   //s>e
            e += (p-W);
        }
        int i=1;
        for(;s!=e;++i){     //move s towards s, starting from candy of 1
            *s = i;
            if(s<e)
              ++s;
            else
              --s;
        }
        if(*s < i){         //if crest has been assigned but lower than currently need, set it
            *s = i;
        }
        p = q-1;
    }
    int sum=0;
    printf("candies: ");
    for(int i=0;i<n;i++){
        printf("%d ", candy[i]);
        sum += candy[i];
    }    
    printf("\n");
    
    delete[] candy;
    candy=0;
    return sum;
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str)==0 || str.empty())
          break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        int res = distributecandy(arr, n);
        printf("minimum candy is %d\n", res);

        delete[] arr;
        arr=0;
    }
    return 0;
}
