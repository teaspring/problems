/*
 * CrackCodingInterview, BitManipulation exer5.7. 
 * an int array A[] contains 0-n except one integer which is missing. the elements are represented in binary, and the 
 * only operation to access them is "fetch jth bit of A[i]".
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int fetchBit(int ele, int pos){
    if(pos<0 || pos > 31)    return 0;
    while(pos-- > 0){
        ele = (ele >> 1);
    }
    return (ele & 1);
}

int findMissingBitInt(vector<int>& elements, int column){
    if(column > 31)        return 0;            
    if(elements.size() == 1){                                    //exit criterial not covered in book, one bug to fix
        return fetchBit(elements[0], column) == 1 ? 0 : 1;
    }
    vector<int> odds;
    vector<int> evens;
    for(size_t i=0; i<elements.size(); ++i){
        int bit = fetchBit(elements[i], column);
        if(bit == 1){
            odds.push_back(elements[i]);
        }else if(bit == 0){
            evens.push_back(elements[i]);
        }else{
            continue;
        }
    }
            
    if(odds.size() >= evens.size()){
        return((findMissingBitInt(evens, column+1) << 1) | 0);
    }else{
        return((findMissingBitInt(odds,  column+1) << 1) | 1);
    }            
}

int main(int, char**){
    return 0;
}
