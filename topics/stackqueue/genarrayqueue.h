/*
 * ********* <DataStructureInC++> chapter4 stack & queue **********
 * generic queue implementation of array
 */
#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE

template<typename T, int size=100>
class ArrayQueue{                    //size is the capacity of array
    public:
        ArrayQueue(){
            first = last = -1;
        }
        void enqueue(T);
        T dequeue();
        bool isFull(){
            return first==0 && last==size-1 || first==last+1;
        }
        bool isEmpty(){
            return first == -1;
        }
    private:
        int first;                    //the element to pop
        int last;                    //last+1 is the hole to insert
        T storage[size];
}; 

template<typename T, int size>
void ArrayQueue<T,size>::enqueue(T el){
    if(!isFull()){
        if(last == size-1 || last == -1){
            storage[0] = el;
            last = 0;
            if(first == -1)
                first = 0;
        }else{                        //queue not empty, no need to update first
            storage[++last] = el;
        }
    }else{
        cout << "Full queue. \n";
    }
    return;
}

template<class T, int size>
T ArrayQueue<T, size>::dequeue(){
    if(first==-1)
      return 0;
    T tmp = storage[first];
    if(first == last){
        last = first = -1;
    }else if(first == size-1){        // first = (first+1) mode size
        first = 0;
    }else{
        first++;
    }
    return tmp;
}
#endif
