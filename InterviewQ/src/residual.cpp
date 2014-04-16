/*
* CareeUp, practice8.7 ext
* given 25, 10, 5, 1 cents coin and sum of n cents, list all combinations
* my answer
*/
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

enum enCoin{
    ONE = 0,
    FIVE,
    TEN,
    TWENTYFIVE
};
const int Coins[] = {1,5,10,25};

int combineCoins(int sum, enCoin maxCoin, vector<int>* wallet){
    int cnt = 0;
    if(sum < 0 || maxCoin < ONE)        return 0;

    if(sum == 0 || maxCoin == ONE){  //push n*1 when maxCoin==ONE
        if(maxCoin == ONE){
            for(int i=0; i<sum; i++){
                wallet->push_back(1);
            }
        }

        //output
        vector<int>::iterator iter = wallet->begin();
        while(iter != wallet->end()){
            cout << *iter << ",";
            iter++;
        }
        cout << endl;

        if(maxCoin == ONE){
            for(int i=0; i<sum;i++){
                wallet->pop_back();
            }
        }
        return 1;
    }


    if(sum >= Coins[maxCoin]){    //pure recursion, push and pop vector at In or Out of method call
        wallet->push_back(Coins[maxCoin]);    //recursion will be overused while coin is ONE
        cnt += combineCoins(sum - Coins[maxCoin], maxCoin, wallet);
        wallet->pop_back();
    }

    do{    //downgrade maxCoin to be lower than sum instead of downgrading by recursive    
        maxCoin = enCoin(maxCoin-1);
    }while(sum < Coins[maxCoin]);

    return (cnt + combineCoins(sum, maxCoin, wallet));
}

//CarerUp, practice 8.7, answer on book
int makeChange(int n, int denom){
    int next_denom = 0;
    switch (denom){
    case 25:
        next_denom = 10;
        break;
    case 10:
        next_denom = 5;
        break;
    case 5:
        next_denom = 1;
        break;
    case 1:
        return 1;    //it must be able to count to n for coin ==1, while n can be 0
    default:
        break;
    }
    
    int ways = 0;
    for(int i = 0; i*denom <= n; i++){
        ways += makeChange(n - i*denom, next_denom);
    }
    return ways;
}

int makeChangeExt(int n, int denom, vector<int>& vec){
    int next_denom = 0;
    vector<int>::iterator iter;            //any variable used in branch of switch must be initialized outside switch
    switch(denom){
    case 25:
        next_denom = 10;
        break;
    case 10:
        next_denom = 5;
        break;
    case 5:
        next_denom = 1;
        break;
    case 1:
        for(int k=0; k<n;k++){    //push n * 1
            vec.push_back(1);     //the assert statement will run once more than loop body
        }
        iter = vec.begin();
        while(iter != vec.end()){
            cout << *(iter++) << ',';
        }
        cout << endl;

        for(int k=n; k>0; k--){
            vec.pop_back();
        }        
        return 1;
    default:
        break;
    }
    
    int ways = 0;
    for(int i = 0; i*denom <= n; i++){
        if(i > 0)    vec.push_back(denom);
        ways += makeChangeExt(n - i*denom, next_denom, vec);
    }
    
    //as it uses iteration instead of recursion, the push/pop operation looks asymmetric 
    for(int k = n/denom; k > 0; k--){        //pop all the elements pushed during this method
        vec.pop_back();
    }
    
    return ways;
}

void test_01(){
    int n;
    cin >> n;
    vector<int> vec;
    cout<<"all the coin combination is: " <<endl;    
    int total = combineCoins(n, TWENTYFIVE, &vec);
    cout << "combination count is " << total << endl;
        
    vec.clear();
    //int ways = makeChangeExt(n, 25, vec);
    //cout << "combination count is " << ways << endl;
    return;
}

int main(int, char**){
    test_01();
    return 0;
}
