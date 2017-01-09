/*
 * in order: LVR. Morris Inorder traverse is a solution without internal container
 *
 * transform whole binary tree to one tree of single right line
 * via append root to rightmost of left subtree
 * */
class Solution{

public:
    void MorrisInorder(TreeNode* root){
        TreeNode *p = root;
        while(p) {
            if(p->left == NULL) {  // no left child
                visit(p); // p is left most node which has no left child
                p = p->right;
            } else {
                TreeNode *tmp = p->left;  // right most leaf in left subtree of p
                while(tmp->right && tmp->right != p) {
                    tmp = tmp->right;
                }

                if(tmp->right == NULL) {  // tmp is right most leaf in left subtree
                    tmp->right = p; // plug p to be right of tmp
                    p = p->left;
                } else {  // tmp->right == p
                    visit(p);  // visit p as 'V' of 'LVR'
                    tmp->right = NULL; // unplug tmp and current root p
                    p = p->right;
                }
            }
        }
    }
};

