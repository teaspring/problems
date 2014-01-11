/*
 * from leetcode, linear algorithm with backtrack
 * we have several children to give candy. Assume each child is assigned an integer weight.
 * rule: nobody can have no candy. for any adjacent children, the one with higher weight must have more candy than neighbors. 
 * ask the minimum candy
 * 
 * hidden point: do not assume same ratings neighbouring children should get the same candies. for ratings {1,2,2}, minimum candies are {1,2,1}
 * 
 * test data: 
 * 3,3,3,10(1,1,1,2)
 * 7,7,3,3(2,2,1,1)
 * 4 7 7 9 8 7 6 5 4(1,2,1,5,4,3,2,1)
 *
 * solution: for each segment of single side trend, we give candy starting from 1 increasingly
 * */

#include "../header/preliminary.h"

/*
 * answer from leetcode, good code
 * iterate arrays of weight and candy at the same time.
 * */
int candy(int* ratings, int n){
    if(n==0)
      return 0;
    else if(n==1)
      return 1;

    int* candies = new int[n]();
    candies[0] = 1;
    int sum=1;
    for(int i=1;i<n;++i){
        if(ratings[i] > ratings[i-1]){
            candies[i] = candies[i-1] + 1;
            sum += candies[i];
        }
        /*
        else if(ratings[i] == ratings[i-1]){
            candies[i] = candies[i-1];
            sum += candies[i];
        }
        */
        else{                        //ratings[i] <= ratings[i-1]
            if(candies[i-1] >= 2){
                candies[i] = 1;
                sum += 1;
            }else{
                int k=i;
                candies[k] = 1;
                sum += 1;
                while(k>0 && ratings[k] < ratings[k-1] && candies[k] >= candies[k-1]){    //supplement candy
                    candies[k-1]++;
                    sum++;
                    k--;
                }
            }
        }
    }
    printf("candies: ");
    for(int i=0;i<n;i++){
        printf("%d ", candies[i]);
    }    
    printf("\n");
    
    delete[] candies;
    candies=0;    
    return sum;
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str)==0 || str.empty())
          break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        int res = candy(arr, n);
        printf("minimum candies in total are %d\n", res);

        delete[] arr;
        arr=0;
    }
    return 0;
}
