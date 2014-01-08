/*
 * *************<DataStructureInC++> chapter4 stack & queue************
 * generic stack implementation of doubly linked list
 *
 */
#ifndef LL_STACK
#define LL_STACK

#include <list>
using namespace std;

template<typename T>
class LLStack{
    public:
        LLStack(){        
        }
        void clear(){
            lst.clear();
        }
        bool isEmpty() const{
            return lst.empty();
        }
        T& topEl(){
            return lst.back();
        }
        T pop(){
            T el = lst.back();            //pop from tail
            lst.pop_back();
            return el;
        }
        void push(const T& el){
            lst.push_back(el);            //insert at tail
        }
    private:
        list<T> lst;
};
#endif
