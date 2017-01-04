/*
 * check if a tree is balanced(binary search tree).A balanced tree is defined to be a tree that no two leaf nodes differ in distance from the root by more than 1.
 * */

// ideal recursion

#include <cmath>

using namespace std;

class Solution{
public:
    bool isBalancedTree(Node* root){
        return maxPath(root) - minPath(root) <= 1;
    }

private:
    int maxPath(Node* root){
        if(!root)    return 0;
        return 1 + max(maxPath(root->left), maxPath(root->right));
    }

    int minPath(Node* root){
        if(!root)    return 0;
        return 1 + max(minPath(root->left), minPath(root->right));
    }
};

