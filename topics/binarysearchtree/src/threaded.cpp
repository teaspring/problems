/*
 * <DataStructure&AlgorithmInC++> chapter6 binary tree
 * Threaded tree: get rid of the disadvantage that leaf node of binary tree have null left and right child pointer which is memory waste.
 * It sets child pointers of node to next in depth-first traverse(inorder/pre/post) temporarily. 
 * It moves some search effort to insertion method, ease the traverse method
 * */

#ifndef THREADED_TREE
#define THREADED_TREE

template<class T>
class ThreadedNode{
    public:
        ThreadedNode(){
            left = right;
        }
        ThreadedNode(const T& el, ThreadedNode *l=0, ThreadedNode *r=0)
            : key(el), left(l), right(r), successor(0){}

        T key;
        ThreadedNode *left, *right;
        //0 means descendant, 1 mean successor which left child and right child(if not null),are tranformed to next in traverse
        unsigned int successor;    
};

template<class T>
class ThreadedTree{
    public:
        ThreadedTree(){
            root = 0;
        }
        void insert(const T&);
        void inorder();
    protected:
        ThreadedNode<T> *root;
};
#endif 

template<class T>
void ThreadedTree<T>::inorder(){
    ThreadedNode<T> *prev, *p = root;
    if(p != 0){                    //only nonempty trees
        while(p->left != 0)        //go to the leftmost node
          p = p->left;
        while( p!= 0){
            visit(p);
            prev = p;            //for restore
            p = p->right;        //goto the right node and only
            if(p!=0 && prev->successor == 0){ //if it is a
              while(p->left != 0)             //descendant go to the
                p = p->left;                 //leftmost node, otherwise
            }
        }                                     //visit the successor
    }
}

//secret is insert()
template<class T>
void ThreadedTree<T>::insert(const T& el){
    ThreadedNode<T> *p, *prev=0, *newNode;
    newNode = new ThreadedNode<T>(el);
    if(root == 0){
        root = newNode;
        return;
    }
    p = root;                        //find a place to insert newNode
    while(p != 0){
        prev = p;
        if(p->key > el)
          p = p->left;
        else if(p->successor == 0)    //go to the right node only if it
          p = p->right;                //is a descendant, not a successor;
        else 
          break;                    //don't follow successor link
    }

    if(prev->key > el){                //if newNode is left child of its parent,
        prev->left = newNode;    
        newNode->successor = 1;        //the parent becomes its successor
        newNode->right = prev;
    }else if(prev->successor == 1){    //if the parent of newNode is not the
        newNode->successor = 1;        //rightmost node
        prev->successor = 0;
        newNode->right = prev->right; //newNode's successor
        prev->right = newNode;        //parent's successor
    }else{
        prev->right = newNode;        //otherwise it has no successor
    }
}

int main(int argc, char* argv[]){
    return 0;
}
