#include <iostream>

/*
* transform whole binary tree to one tree of single right line via append root to rightmost of left subtree 
*/
template<typename TreeNode>
void MorrisInorder(TreeNode* root){
    TreeNode *p = root, *tmp;
    while(p != 0){
        if(p->left == 0){           //root of transformation completed tree, or just with no left child
            visit(p);
            p = p->right;
        }
        else{
            tmp = p->left;          //right most node of left half
            while(tmp->right != 0 &&        
                    tmp->right != p){
                tmp = tmp->right;
            }
            
            if(tmp->right == 0){    //go to rightmost leaf (of left subtree), append p to it
                tmp->right = p;                
                p = p->left;
            }
            else{
                visit(p);           //tmp->right == p, this link is appended
                tmp->right = 0;
                p = p->right;
            }            
        }
    }    
}

void test_01(){
}

int main(int, char**){
    test_01();
}
