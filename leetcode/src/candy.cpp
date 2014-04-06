/*
 * there are N children standing in a line. Everyone is assigned a rating value.
 * you are giving candies to these children subjectd to the following requirements:
 * 1.each child must have at least one candy
 * 2.children with a higher rating get more candies than their neighbors.
 * what is the minimum candies you must give?
 *
 * hidden point: for 4 4 3, the minimum candies can be 1+2+1 = 4 
 *
 * test data:
 * 2 5 7 6 5 4 2 3 6 9 4 2
 * 4 4 5 7 6 5 4 4 3 3 2 1 4 6 9 3 2 
 * */
#include "../header/preliminary.h"

int backtrack(vector<int>& ratings, int l, int r, int *candies){
    int n = ratings.size();
    if(l<0 || r>=n)    return 0;
    candies[r] = 1;
    int sum = 1;
    for(int i = r-1; i>l; --i){
        if(ratings[i] == ratings[i+1]){    //ratings[i] >= ratings[i+1]
            candies[i] = 1;
        }else{
            candies[i] = candies[i+1] + 1;
        }
        sum += candies[i];
    }
    int tmp = candies[l+1] + 1;
    if(candies[l] < tmp){    //ratings[l] > ratings[l+1]
        sum += tmp - candies[l];
        candies[l] = tmp;
    }
    return sum;
}

/*
 * key: 
 * 1. do not start backtrack until the decending range closes
 * 2. if [i]=[i-1], neighbor's candy can be 1 in minimum
 * */
int candy(vector<int>& ratings){
    int n = ratings.size();
    if(n==0)    return 0;
    if(n==1)    return 1;
    int *candies = new int[n]();
    candies[0] = 1;
    int sum=1, ki=-1;
    for(int i=1; i<n; ++i){
        if(ratings[i] == ratings[i-1]){
            if(ki > -1)    continue;    //during decending, leave candies[i] as 0 to set it in backtrack()
            candies[i] = 1;
        }else if(ratings[i] > ratings[i-1]){
            if(ki > -1){
                sum += backtrack(ratings, ki, i-1, candies);
                ki = -1;
            }
            candies[i] = candies[i-1] + 1;
        }else{    //decending
            if(ki == -1)    ki = i-1;     //leave candies[i] as 0 to set it in backtrack()
        }
        sum += candies[i];
    }
    if(ki > -1){
        sum += backtrack(ratings, ki, n-1, candies);
    }
    cout<<"candies: ";;
    for(int i=0;i<n;i++){
        printf("%d ", candies[i]);
    }
    printf("\n");
    delete[] candies;
    return sum;
}

void test_01(){
    string str;
    while(1){
        printf("please input rating values of children in a row:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        vector<int> ratings;
        for(int i=0;i<n;i++){
            ratings.push_back(arr[i]);
        }
        printf("minimum sum is %d\n", candy(ratings));
    }
    return;
}

int main(int, char**){
    test_01();
    return 0;
}
