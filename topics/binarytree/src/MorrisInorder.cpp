/*
 * in order output is LVR
 *
 * transform whole binary tree to one tree of single right line
 * via append root to rightmost of left subtree
 * */
void MorrisInorder(TreeNode* root){
    TreeNode *p = root, *tmp = NULL;
    while(p != NULL){
        if(p->left == NULL){  // without left child
            visit(p); // p is left most node which has no left child
            p = p->right;
        }else{
            tmp = p->left;  // right most leaf in left subtree of p
            while(tmp->right != NULL
                && tmp->right != p){
                tmp = tmp->right;
            }

            if(tmp->right == NULL){  // tmp is right most leaf in left subtree, append p to it
                tmp->right = p; // plug p to be right of tmp
                p = p->left;
            }else{  // tmp->right == p
                visit(p);  // visit p as 'V' of 'LVR'
                tmp->right = NULL; // unplug tmp and its right
                p = p->right;
            }
        }
    }
}

