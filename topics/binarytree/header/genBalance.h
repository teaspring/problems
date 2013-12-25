/*
 * practice general balance methods via rotate, including left rotate and right rotate
 * */
#include <iostream>
using namespace std;

template<class T>
class BSTNode{
    public:
        BSTNode(){
            left = right = 0;
        }
        BSTNode(const T& el, BSTNode *l =0, BSTNode *r = 0)
        :key(el), left(l), right(r){
        }
        T key;
        BSTNode *left, *right;
};

template<class T>
class genBalanceTree{
    public:
        BST(){
            root = 0;
        }
        ~BST(){
            clear();
        }
        void insert(const T&);
        void remove(const T&);
        bool isBalanced();
        bool balance();
        void clear(){
            clear(root);
        }

        T* search(const T& el){
            return search(root, el);
        }
    private:
        BSTNode* root;
        void clear(BSTNode<T>*);
        T* search(BSTNode<T>*, const T&) const;
        void leftRotate(BSTNode<T>*);
        void rightRotate(BSTNode<T>*);
        void trans2RightBackbone();
        void trans2Balance();
};

