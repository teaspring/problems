/*
 * ******************<DataStructureInC++> chapter3 Linked List**********************
* generic skip list
*
* very cool, and need patience to read
* */
#include<iostream>
#include "stdlib.h"
#include"math.h"

const int maxLevel = 4;

template<typename T>
class SkipListNode{
public:
    SkipListNode(){
        next = 0;
    }
    ~SkipListNode(){}
    T key;
    SkipListNode** next;        //SkipNode<T>[] list, which size equals to the level where the node stands
}; 

template<typename T>
class SkipList{
public:
    SkipList();
    void choosePowers();
    int chooseLevel();
    T* skipListSearch(const T&);
    void skipListInsert(const T&);
private:
    typedef SkipListNode<T> *nodePtr;  
    nodePtr root[maxLevel];        //the first node of each level
    int powers[maxLevel];
};

template<typename T>
SkipList<T>::SkipList(){
    for (int i=0; i<maxLevel; i++)
        root[i] = 0;
}

template<typename T>
void SkipList<T>::choosePowers(){
    powers[maxLevel-1] = (2 << (maxLevel-1)) - 1;   // 2^maxLevel -1
    for(int i=maxLevel-2, j=0; i>=0; i--, j++)
        powers[i] = powers[i+1] - (2 << j);            // 2^(j+1)
}

template<typename T>
int SkipList<T>::chooseLevel(){
    int i, r = rand() % powers[maxLevel-1] + 1;  //band
    for(i = 1; i < maxLevel; i++)
    {
        if( r < powers[i])                // return a level < the highese level
            return i-1;                    // return the highest level 
    }
    return i-1;
}

template<typename T>
T* SkipList<T>::skipListSearch(const T& key)
{
    nodePtr prev, curr;
    int lvl;                            // find the highest non-null level
    for(lvl = maxLevel-1; lvl >= 0 && !root[lvl]; lvl--);
    prev = curr = root[lvl];
    while(1){
        if(key == curr->key)            //success if equal        
            return &curr->key;
        else if(key < curr->key){        // if smaller, go down if possible,
            if(lvl == 0)
                return 0;
            else if(curr == root[lvl])    //by one level starting from the predecessor which can be the root
                curr = root[--lvl];
            else curr = *(prev->next + --lvl);
        }
        else {                            //if greater, go to the next non-null node on the same level 
            prev = curr;
            if(*(curr->next + lvl) != 0)
                curr = *(curr->next + lvl);
            else{                        // or to a list on a lower level
                    for(lvl--; lvl >= 0 && *(curr->next + lvl) == 0; lvl--);
                    if(lvl >= 0)
                        curr = *(curr->next + lvl);
                    else
                        return 0;
            }
        }        
    }    
}

template<typename T>
void SkipList<T>::skipListInsert(const T& key){
    nodePtr curr[maxLevel], prev[maxLevel], newNode;
    int lvl, i;
    curr[maxLevel-1] = root[maxLevel-1];
    prev[maxLevel-1] = 0;
    // this loop is to find the following greater nodes(curr[]) at each level which compose the 'next' list of new node
    for(lvl = maxLevel-1; lvl >= 0; lvl--){
        while(curr[lvl] && curr[lvl]->key < key){    //go to the next if smaller 
            prev[lvl] = curr[lvl];
            curr[lvl] = *(curr[lvl]->next + lvl);
        }
        if(curr[lvl] && curr[lvl]->key == key)        //exclude the duplicate
            return;
        if(lvl > 0){                                //go to one level down
            if(prev[lvl] == 0){                        //if not the lowest level, using a link either from the root
                curr[lvl-1] = root[lvl-1];
                prev[lvl-1] = 0;
            }
            else{                                    //or from the predecessor
                curr[lvl-1] = *(prev[lvl]->next + lvl-1);
                prev[lvl-1] = prev[lvl];
            }
        }
    }
    lvl = chooseLevel();                            //generate random level for newNode
    newNode = new SkipListNode<T>;
    newNode->next = new nodePtr[sizeof(nodePtr) * (lvl+1)];
    newNode->key = key;
    //set value of next[] of new node
    for(i=0; i<=lvl; i++){                            //initialize next fields of newNode and reset to newNode
        *(newNode->next + i) = curr[i];                //either fields of the root or the next fields of newNode's predecessor
        if(prev[i] == 0)
            root[i] = newNode;
        else
            *(prev[i]->next + i) = newNode;
    }
}

int main(int argc, char* argv[]){
    return 0;
}
