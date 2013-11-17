/*
 * <DataStructure&AlgorithmInC++> chapter6 binary tree
 * generic splaying tree class
 * implementation of word frequency computation
 * */
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

#ifndef SPLAYING
#define SPLAYING

template<class T> class SplayTree;

template<class T>
class SplayingNode{
public:
    SplayingNode(){
        left = right = parent=0;
    }
    SplayingNode(const T& el, SplayingNode *l=0, SplayingNode *r=0, SplayingNode *p=0){
        info = el;
        left = l;
        right=r;
        parent = p;
    }

    T info;
    SplayingNode *left, *right, *parent;
};

template<class T>
class SplayTree{
public:
    SplayTree(){
        root=0;
    }
    void inorder(){
        inorder(root);
    }
    T* search(const T&);
    void insert(const T&);

protected:
    SplayingNode<T> *root;
    void rotateR(SplayingNode<T>*);
    void rotateL(SplayingNode<T>*);
    void continueRotation(SplayingNode<T>* gr, SplayingNode<T>* par,
                        SplayingNode<T>* ch, SplayingNode<T>* desc);
    void semisplay(SplayingNode<T>*);
    void inorder(SplayingNode<T>*);
    void virtual visit(SplayingNode<T>*){
    }
};

/*
 * to rotate ch and its parent
 * */
template<class T>
void SplayTree<T>::continueRotation(SplayingNode<T>* gr,
    SplayingNode<T>* par, SplayingNode<T>* ch, SplayingNode<T>* desc){
    if(gr != 0){                //ch has non-null grand parent
        if(gr->right == ch->parent) //ch's parent is right
          gr->right = ch;        
        else
          gr->left = ch;        
    }
    else
      root = ch;                //par is root, now ch is root
    if(desc != 0)                //ch has valid child, no matter left or right
      desc->parent = par;        //rotate ch and par, now par is parent of desc
    par->parent = ch;
    ch->parent = gr;
}

template<class T>
void SplayTree<T>::rotateR(SplayingNode<T>* p){        //p is left
    p->parent->left = p->right;                        //p->parent->left is where p is
    p->right = p->parent;
    continueRotation(p->parent->parent,
                p->right, p, p->right->left);
}

template<class T>
void SplayTree<T>::rotateL(SplayingNode<T>* p){        //p is right of parent
    p->parent->right = p->left;                        //p->parent->right is where p is
    p->left = p->parent;
    continueRotation(p->parent->parent, 
                p->left, p, p->left->right);
}

template<class T>
void SplayTree<T>::semisplay(SplayingNode<T>* p){
    while(p != root){
        if(p->parent->parent == 0)                //p's parent is root
          if(p->parent->left == p)                //p is left
            rotateR(p);
          else
            rotateL(p);
        else if(p->parent->left == p)    //p has grand parent;p is left
                if(p->parent->parent->left == p->parent){    //p's parent is left                  
                    rotateR(p->parent);
                    p = p->parent;
                }
                else{                    //p's parent is right
                    rotateR(p);            //rotate p and its parent
                    rotateL(p);            //rotate p and its new parent
                }
        else                            //p has grand parent;p is right
          if(p->parent->parent->right == p->parent){//p's parent is right
            rotateL(p->parent);
            p = p->parent;
          }
          else{                        //p's parent is left
            rotateL(p);                //rotate p and its parent
            rotateR(p);                //rotate p and its new parent
          }
        if(root == 0)
          root = p;                
    }
}

template<class T>
T* SplayTree<T>::search(const T& el){
    SplayingNode<T> *p = root;
    while(p != 0)
      if(p->info == el){        //if el is in
        semisplay(p);            //move it upward
        return &p->info;
      }
      else if(el < p->info)
            p = p->left;
      else
        p = p->right;
    return 0;
}

template<typename T>
void SplayTree<T>::insert(const T& el){
    SplayingNode<T> *p=root, *prev=0, *newNode;
    while(p != 0){
        prev = p;
        if(el < p->info)
          p=p->left;
        else
          p=p->right;
    }
    if((newNode = new SplayingNode<T>(el,0,0,prev)) == 0){
        cerr << "No room for new nodes\n";
        return;
    }
    if(root == 0)
      root = newNode;
    else if(el < prev->info)
      prev->left = newNode;
    else
      prev->right = newNode;
}

template<class T>
void SplayTree<T>::inorder(SplayingNode<T>* p){            //recursive inorder
    if(p!=0){
        inorder(p->left);
        visit(p);
        inorder(p->right);
    }      
}
#endif

int main(int argc, char* argv[]){
    return 0;
}
