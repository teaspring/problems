/*
 * ********<DataStructureInC++> chapter4 stack & queue ***********
 * generic queue implementation of doubly linked list
 *
 * linked list(STL) support push_back() to insert at tail as it is more efficient than insert at head 
 */
#ifndef DLL_QUEUE
#define DLL_QUEUE

#include <list>
using namespace std;

template<typename T>
class Queue{
    public:
        Queue(){
        }
        void clear(){
            lst.clear();    
        }
        bool isEmpty() const{
            return lst.empty();
        }
        T& front(){                        //get from head
            return lst.front();
        }
        T dequeue(){                    //pop from head, the other side of insertion
            T el = lst.front();
            lst.pop_front();
            return el;
        }
        void enqueue(const T& el){        //insert at tail
            lst.push_back(el);
        }
    private:
        list<T> lst;
};
#endif
