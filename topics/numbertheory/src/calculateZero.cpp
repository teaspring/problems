/*
 * Eular question 2, calculate among how many 0 in literal of factorial N!
 * 2012/06
 * */
#include "stdio.h"
#include <iostream>
#include <vector>

using namespace std;

typedef vector<unsigned> uvector;

class NumericPractice{
public:
    NumericPractice(){};    
    unsigned GetZeroCountOfFactorial(const unsigned &maxNum);
    unsigned CalculateSum(unsigned max);
    long GetFactorial(unsigned max);
private:
    uvector CalculateMaxPower(unsigned max, unsigned base);
};

//Get count of zero in the factorial result of known parameter
unsigned NumericPractice::GetZeroCountOfFactorial(const unsigned &maxNum){
    //10 is composed of 5 multiplized by 2. since multiple of 2 is much more than 5, 
    //result is dependent on count of 5 in the multiplier 
    unsigned result = 0;
    unsigned Num_Five = maxNum/5;
    unsigned Num_ = maxNum/10;

    uvector powerVec = CalculateMaxPower(maxNum, 5);
    uIter myIter     = powerVec.begin();
    uIter last       = powerVec.end();
    for(;myIter != last; myIter++){
        result += maxNum/(*myIter);
    }
    return result;
}

unsigned NumericPractice::CalculateSum(unsigned max){
    unsigned result = 0;
    while(max){
        result += (max--);
    }
    return result;
}

long NumericPractice::GetFactorial(unsigned max){
    unsigned result = 1;
    while(max){
        result *= (max--);
    }
    return result;
}

uvector NumericPractice::CalculateMaxPower(unsigned max, unsigned base){
    uvector result;
    if(0 == base)        return result;
    unsigned tmp = base;
    while(max/tmp){
        result.push_back(tmp);
        tmp *= base;        
    }
    return result;
}

int main(int, char**){
    return 0;
}
