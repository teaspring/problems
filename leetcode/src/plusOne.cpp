/*
 * given a non-negative number represented as an array of digits, plus one to the number
 * the digits are stored such that the most significant digit is at the head of the list
 * test data:
 * 9
 * 899
 * 8791238989123
 * */

#include "stdio.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * as argument integer is represented in vector, the transmission to int is risky of overflow
 * */
vector<int> plusOne(vector<int>& digits){
    int m = digits.size();
    if(m == 0)    return vector<int>();
    int n = m + 1;
    int arr[n];
    int i=m-1, j=n-1, over=1;
    for(; i>=0; --i, --j){
        int curr = digits[i] + over;
        arr[j] = curr % 10;
        over = curr / 10;
    }
    if(over){
        arr[j--] = 1;  // [j] is next significant digit to write, so j+1 is current valid most significant
    }
    return vector<int>(arr+j+1, arr+n);
}

void displayVector(vector<int>& vec){
    for(size_t i=0; i<vec.size(); ++i){
        printf("%d", vec[i]);
    }
    printf("\n");
    return;
}

void test_01(){
    vector<int> input;
    input.push_back(9);
    vector<int> res = plusOne(input);
    displayVector(res);
}

void test_02(){
    vector<int> input;
    input.push_back(8);
    input.push_back(9);
    input.push_back(9);
    vector<int> res = plusOne(input);
    displayVector(res);
}

int main(int, char**){
    test_01();
    test_02();
    return 0;
}
