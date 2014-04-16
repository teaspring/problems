/* 
 * class for Poker card process, Jun02, 2012
 * data structure selection: list rather than vector, because when WashCard, it needs fast delete/remove, 
 */
#include "stdafx.h"
#include <vector>
#include <list>
#include <ctime>
#include "windows.h"

typedef std::pair<char, char> cpair;
typedef std::list<cpair> cpList;

template<typename T> void Swap(T &left, T &right);
class PokerCard{
public:
    PokerCard();
    ~PokerCard();
    //steps to wash card
    void RandomShuffle(int round);    
    void Display();

private:
    void InitVector(const char source[13], cvector* dest);
    void DoubleBack(unsigned newBegin);
    void Reverse();
    void SplitMerge(unsigned begin);

    cpList Result;
};

PokerCard::PokerCard(){
    char initCards[13] = {'2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A'};
    char type[4] = {'C', 'D', 'H', 'S'};            //club, diamond, heart, spade
    for(int i=0; i<4; i++){
        for(int j=0; j<13; j++){
            this->Result.push_back(cpair(type[i], initCards[j]));
        }
    }
}

PokerCard::~PokerCard(){
    this->Result.clear();
}

//if parameter is 3, [1, 2, 3, 4, 5, 6, 7, 8] => [4, 5, 6, 7, 8, 9, 1, 2, 3]
void PokerCard::DoubleBack(unsigned newBegin){    
    cpList::iterator iter = this->Result.begin();
    for(unsigned i=0; i < newBegin ; i++){
        this->Result.push_back(*iter);        
        //this->Result.erase(iter);
        iter++;
    }
    this->Result.erase(this->Result.begin(), iter);
}

//[1, 2, 3, 4, 5, 6, 7, 8] => [8, 7, 6, 5, 4, 3, 2, 1]
void PokerCard::Reverse(){
    cpList::iterator Begin = this->Result.begin();
    cpList::iterator End = this->Result.end();

    size_t half = this->Result.size() / 2;
    for(size_t i=0; i<half; ++i){
        Swap(*(Begin++), *(--End));
    }
}

//[1, 2, 3, 4, 5, 6, 7, 8] with parameter 3 => [4, 1, 5, 2, 6, 3, 7, 8]
void PokerCard::SplitMerge(unsigned begin){
    cpList::iterator firstBegin = this->Result.begin();
    cpList::iterator secondEnd  = this->Result.end();
    cpList::iterator secondBegin = firstBegin;
    for(unsigned i = 0; i<begin; i++){
        secondBegin++;    
    }
    cpList::iterator firstEnd = secondBegin;

    unsigned size = this->Result.size();
    unsigned limit = begin > (size/2) ? size - begin : begin;
    for(unsigned i = 0; i<limit; i++){
        //insert secondBegin before fistBegin, then remove secondBegin
        this->Result.insert(firstBegin++, *secondBegin);
        this->Result.erase(secondBegin++);        
    }    
}

void PokerCard::RandomShuffle(int round){    
    FILETIME ftime;
    unsigned offset1 = 0;
    unsigned offset2 = 0;
    while(round--){
        GetSystemTimeAsFileTime(&ftime);
        offset1 = ftime.dwLowDateTime % 52;
        this->SplitMerge(offset1);
        this->Reverse();
        
        offset2 = ftime.dwHighDateTime % 52;
        this->DoubleBack(offset2);
        this->Reverse();
        this->SplitMerge(offset1);            
    }
}

void PokerCard::Display(){
    cpList::iterator Begin = this->Result.begin();
    cpList::iterator End = this->Result.end();
    int count = 0;
    std::cout << "Now the cards are: " << std::endl;
    while(Begin != End){
        std::cout << (*Begin).first << "-" << (*Begin).second << ", ";
        if(++count % 10 == 0){
            std::cout << std::endl;
        }
        Begin++;
    }
    std::cout << std::endl;
}

template<typename T> 
void Swap(T &left, T &right){
    T tmp = left;
    left = right;
    right = tmp;
    T = 0;
}

void test_01(){        
    PokerCard myCard = PokerCard();
    myCard.Display();        
    myCard.RandomShuffle(5);
    myCard.Display();
}

int main(int, char**){    // it needs test case code
    return 0;
}
