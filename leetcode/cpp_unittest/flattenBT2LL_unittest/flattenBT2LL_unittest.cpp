#include "flattenBT2LL.cpp"
#include "gtest/gtest.h"

/*
 * TreeNode* Solution::flatten(TreeNode* root)
 * */

TreeNode* constructBT(){
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    return root;
}

TreeNode* constructFlattenLL(){
    int arr[] = {1, 2, 4, 5, 3, 6};
    int n = sizeof(arr) / sizeof(int);

    TreeNode *head = NULL, *p = NULL;
    for(int i = 0; i < n; i++){
        if(!p){
            head = new TreeNode(arr[i]);
            p = head;
        }else{
            p->right = new TreeNode(arr[i]);
            p = p->right;
        }
    }

    return head;
}

bool assertLL(TreeNode *head1, TreeNode *head2){
    if(!head1){
        EXPECT_TRUE(!head1 && !head2);
        return true;
    }

    TreeNode *p1 = head1, *p2 = head2;
    do{
        EXPECT_EQ(p1->val, p2->val);
        EXPECT_EQ(NULL, p1->left);
        EXPECT_EQ(NULL, p2->left);

        p1 = p1->right;
        p2 = p2->right;
    }while(p1 && p2);

    EXPECT_TRUE(!p1 && !p2);
    return true;
}

void deleteLL(TreeNode* head){
    TreeNode *p = head;
    while(p){
        TreeNode *next = p->right;
        p->right = NULL;  // unplug

        delete p;
        p = next;
    }
    return;
}

/* -------------- test body -------------- */
TEST(flattenBT2LL_Test, Positive01){
    Solution s;

    TreeNode *root = constructBT();
    TreeNode *expected = constructFlattenLL();
    s.flatten(root);

    EXPECT_TRUE(assertLL(expected, root));

    deleteLL(expected);
    deleteLL(root);
}

