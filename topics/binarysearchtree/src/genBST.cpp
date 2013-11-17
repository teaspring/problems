/*
 * general binary search tree
 *
 * test data:
 * pre:  a,b,d,c,e,f
 * in:   d,b,a,e,c,f
 * post: d,b,e,f,c,a
 * */

#include "../header/genBST.h"

template<class T>
T* BST<T>::search(BSTNode<T>* p, const T& el) const{
    while(p != 0)
      if(el == p->key)
        return &p->key;
      else if(el < p->key)
        p = p->left;
      else
        p=p->right;
    return 0;
}

template<class T>
void BST<T>::breadthFirst(){
    Queue<BSTNode<T>*> queue;
    BSTNode<T> *p = root;
    if(p != 0){
        queue.enqueue(p);
        while(!queue.empty()){
            p = queue.dequeue();
            visit(p);
            if(p->left != 0)
              queue.enqueue(p->left);
            if(p->right != 0)
              queue.enqueue(p->right);
        }
    }
}

/*
 * breadth-first traverse is native with a queue structure
 * depth-first traverse needs stack, either a runtime stack by compiler, or a explicit stack in use, or stackless traverse-threaded tree and Morris inorder. It includes inorder, preorder, postorder. 
 * */

//recursive version
template<class T>
void BST<T>::inorder(BSTNode<T> *p){
    if(p!=0){
        inorder(p->left);
        visit(p);
        inorder(p->right);
    }      
}

template<class T>
void BST<T>::preorder(BSTNode<T> *p){
    if(p!=0){
        visit(p);
        preorder(p->left);
        preorder(p->right);
    }
}

template<class T>
void BST<T>::postorder(BSTNode<T> *p){
    if(p!=0){
        postorder(p->left);
        postorder(p->right);
        visit(p);
    }
}

/*
 * VLR
 * */
template<class T>
void BST<T>::iterativePreorder(){
    if(root == 0)
      return;
    stack<BSTNode<T>*> stk;
    BSTNode<T> *p = root;
    stk.push(p);
    while(!stk.empty()){
        p = stk.top();
        stk.pop();
        visit(p);
        if(p->right != 0)
          stk.push(p->right);        //push left child after right on top of stack
        if(p->left != 0)
          stk.push(p->left);                
    }
    p = 0;
    return;
}

/*
 * LRV
 * */
template<class T>
void BST<T>::iterativePostorder(){
    stack<BSTNode<T>*> stk;
    BSTNode<T> *p = root, *q = root;        //q is last visited node
    while(p != 0){
        for(;p->left != 0; p=p->left)        //go down to left most leaf
          stk.push(p);                
        while(p->right == 0 || p->right == q){    //without right child,or right child is visited already
            visit(p);                
            q = p;
            if(stk.empty())
              return;
            p = stk.top();            //non-leaf node as parent will be pop() and pushed once again
            stk.pop();
        }
        stk.push(p);            //mid node with right child is push again, now access right child
        p = p->right;            //access right child as a new subtree
    }      
}

/* 
 * LVR
 * */
template<class T>
void BST<T>::iterativeInorder(){
    stack<BSTNode<T>*> stk;
    BSTNode<T> *p = root;
    while(p != 0){                 
        while(p->left != 0){        //go to left most leaf
            stk.push(p);
            p = p->left;
        }
        visit(p);                    //visited as V
        while(p->right==0){
            if(stk.empty())
              return;
            p = stk.top();
            stk.pop();
            visit(p);
        }
        p = p->right;
    }
    p = 0;
    return;
}

/*
 * stackless traverse with tree tranformation
 * Morris traverse make use of leaf node which child node are both null
 * for inorder, it set normal node to be child of leaf node temporarily before traverse; meanwhile, child pointer of normal node is kept. After visited, temporary child of initial leaf is removed
 *
 * fantastic!
 * */
template<class T>
void BST<T>::MorrisInorder(){
    BSTNode<T> *p = root, *tmp;
    while(p != 0){
        if(p->left == 0){       //node without  hidden left child, "true" leaf
            visit(p);
            p = p->right;        //LV->R
        }else{
            tmp = p->left;
            while(tmp->right != 0 && tmp->right != p){   //tmp stops as right most leaf of left subtree or parent of p
                tmp = tmp->right;
            }
            if(tmp->right == 0){        //rightmost leaf
                tmp->right = p;         //tmp becomes temporary parent of p means it is visited prior to p
                p = p->left;            
            }else{                      //othwise tmp is temporary parent of p and tmp is output already 
                visit(p);               //visit p and fallback tmp
                tmp->right = 0;         
                p = p->right;           //downgrade to right subtree LV->R  
            }
        }
    }
}

//delete operation
template<class T>
void BST<T>::deleteByMerging(BSTNode<T>*& node){
    BSTNode<T> *tmp = node;
    if(node != 0){
        if(!node->right){        //has no right, promote left no matter null 
            node = node->left;
        }else if(!node->left){    //has no left, promote right
            node = node->right;
        }else{                    //replace with rightmost of left subtree
            tmp = node->left;
            while(tmp->right != 0){
                tmp = tmp->right;
            }
            tmp->right = node->right;
            tmp = node;
            node = node->left;
        }
    }
    delete tmp;
}

template<class T>
void BST<T>::findAndDeleteByMerging(const T& el){
    BSTNode<T> *node = root, *prev =0;
    while(node != 0){
        if(node->key == el)
          break;
        prev = node;
        if(node->key < el){
            node = node->right;
        }else{
            node = node->left;
        }
    }
    if(node != 0 && node->key == el){   //prev is parent of node
        if(node == root){
            deleteByMerging(node);
        }else if(prev->left == node){
            deleteByMerging(prev->left);    //why not delete node?
        }else{
            deleteByMerging(prev->right);
        }
    }else if(root != 0){
        cout << "key " << el << " is not in the tree\n";
    }else{
        cout << "the tree is empty\n";
    }
}

/*
 * 1.find rightmost node(tmp) in left subtree, copy its value to "node".
 * tmp has no right child. 
 * 2. move tmp->left to the hole in node's left subtree. two cases: tmp is left of node, or sub child beneath it
 * */
template<class T>
void BST<T>::deleteByCopying(BSTNode<T>*& node){
    BSTNode<T> *prev, *tmp = node;
    if(node->right == 0){
        node = node->left;
    }else if(node->left == 0){
        node = node->right;
    }else{                        //node has both children
        tmp = node->left;
        prev = node;
        while(tmp->right != 0){
            prev = tmp;
            tmp = tmp->right;
        }
        node->key = tmp->key;
        if(prev == node){
            prev->left = tmp->left;
        }else{
            prev->right = tmp->right;
        }
    }
    delete tmp;
    tmp=0;
}

template<typename T>
void BST<T>::rebuildPreIn(BSTNode<T>* preorder, BSTNode<T>* inorder, int treeLen, BSTNode<T>** pRoot){
    if(treeLen < 1)
      return;
    T curr = preorder->key;
    (*pRoot) = new BSTNode<T>();
    (*pRoot)->key = curr; 
    (*pRoot)->left = 0;
    (*pRoot)->right = 0;

    int i=0;
    for(;i<treeLen && (inorder+i)->key != curr;i++);
    if(i == treeLen)
      return;
    rebuildPreIn(preorder+1, inorder, i, &((*pRoot)->left));
    rebuildPreIn(preorder+1+i, inorder+i+1, treeLen-i-1, &((*pRoot)->right));      
}

/*
 * rebuild binary tree based on postorder and inorder
 * it has a bug, for left most d-b, it is wrong!!!
 * */
template<typename T>
void BST<T>::rebuildPostIn(BSTNode<T>* postend, BSTNode<T>* inorder, int treeLen, BSTNode<T>** pRoot){
    if(treeLen < 1)
      return;
    T curr = postend->key;
    (*pRoot) = new BSTNode<T>();
    (*pRoot)->key = curr;
    (*pRoot)->left = 0;
    (*pRoot)->right = 0;

    int i=0;
    for(;i<treeLen && (inorder+i)->key != curr;i++);        //i is left subtree length
    if(i == treeLen)
      return;
    rebuildPostIn(postend-(treeLen-1)+i-1, inorder+1, i, &((*pRoot)->left));    //note the postend for left  
    rebuildPostIn(postend-1, inorder+i+1, treeLen-i-1, &((*pRoot)->right));
}

int main(int argc, char* argv[]){
    return 0;
}
