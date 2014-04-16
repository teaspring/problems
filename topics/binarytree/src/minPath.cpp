/*
 * check if a tree is balanced(binary search tree).A balanced tree is defined to be a tree that no two leaf nodes differ in distance from the root by more than one.
 * */

// ideal recursion

inline int Min(int x, int y){
    return x>y ? y : x;
}

inline int Max(int x, int y){
    return x>y ? x: y;
}

public int maxPath(Node* root){
    if(root == 0)    return 0;
    return 1 + Max(maxPath(root->left), maxPath(root->right));
}

public int minPath(Node* root){
    if(root == 0)    return 0;
    return 1 + Min(minPath(root->left), minPath(root->right));
}

public bool isBalancedTree(Node* root){
    return maxPath(root) - minPath(root) <= 1;
}

int main(int, char**){
    return 0;
}
