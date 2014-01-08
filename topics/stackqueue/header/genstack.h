/*
 * *********** <DataStructureInC++> chapter4 Stack & Queue *************
* generic stack implementation of vector
*
*/
#ifndef STACK
#define STACK

#include <vector>
using namespace std;

template<typename T, int capacity=30>
class Stack{
    public:
        Stack(){
            pool.clear();    
        }
        void clear(){
            return pool.empty();
        }
        bool isEmpty() const{
            return pool.empty();    
        }
        T& topEl(){                    //tail
            return pool.back();
        }
        T pop(){                       //pop from tail
            T el = pool.back();
            pool.pop_back();
            return el;
        }
        void push(const T& el){        //insert at tail
            pool.push_back(el);
        }
    private:
        vector<T> pool;
};

#endif
