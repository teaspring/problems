/*
 * problem on Nov 11.
 * given a string of alpha char, find the max substr without duplicate char
 *
 * test data:
 * abcacdfcarfr, result is 5(one option is dfcar)
 * */

#include "../header/preliminary.h"

/*
 * idea is to use an array to save max subarray without duplicate beginning with i
 * */
int maxdistinctsub(const string& str){
    int n=str.size();
    int max=1;
    int* plength = new int[n]();    //plength[i] means most sub length which begins with i
    plength[n-1] = 1;
    for(int i=0;i<n-1;i++){
        if(i>0)
          plength[i] = plength[i-1]-1;
        else
          plength[i] = 1;
        int j=plength[i];
        for(;i+j<n;j++){
            int k = i;
            for(;k<i+j && str[k] != str[i+j];k++);
            if(k<i+j)
              break;
        }
        plength[i] = j;
        if(j > max)
          max = j;        
        if(max == n-i)    break;                //no length greater than max can appear in the rest
    }
    //for test
    printf("method1: the sub array lengths are\n");
    for(int i=0;i<n;i++){
        printf("%d ", plength[i]);
    }
    printf("\n");

    delete[] plength;
    plength=0;
    return max;
}

/*
 * basd on method1, optimize the initial value of plength[i]
*/
int maxdistinctsub_2(const string& str){
    int n=str.size();
    int max=1;
    int* plength = new int[n]();    //plength[i] means most sub length which begins with i
    plength[n-1] = 1;
    int a=0, b=1;                   //the duplicate chars
    for(int i=0;i<n-1;i++){
        if(i>0){
            if(a==i){
                plength[i] = b-a;
                continue;
            }else if(a<i){
                plength[i] = b-i+1;
            }else{
                plength[i] = plength[i-1]-1;
            }
        }
        else{
          plength[i] = 1;
        }
        int j=plength[i];
        for(;i+j<n;j++){
            int k = i;
            for(;k<i+j && str[k] != str[i+j];k++);
            if(k<i+j){                //find duplicate
                a = k;
                b = i+j;
                break;
            }
        }
        plength[i] = j;
        if(j > max)
          max = j;
        if(max == n-i)    break;                //no result greater than max can appear in rest
    }
    //for test
    printf("method2: the sub array lengths are\n");
    for(int i=0;i<n;i++){
        printf("%d ", plength[i]);
    }
    printf("\n");

    delete[] plength;
    plength=0;
    return max;
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str)==0 || str.empty())
          break;
        int x = maxdistinctsub(str);
        printf("the result is %d\n", x);
        x = maxdistinctsub_2(str);
        printf("the result is %d\n", x);
    }
    return 0;
}
