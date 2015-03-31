/*
 * TreeNode* Solution::sortedSLL2BBST(ListNode *head)
 *
 * TreeNode* Solution::sortedArray2BBST(vector<int> &num)
 * */
#include "convertSortedSLL2BBST.cpp"
#include "gtest/gtest.h"

/*
 * construct the test data structure
 * */
TreeNode* constructBST(){
    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    return root;
}

ListNode* constructSLL(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(int);

    ListNode *head = NULL, *p = NULL;
    for(int i = 0; i < n; i++){
        if(!p){
            head = new ListNode(arr[i]);
            p = head;
        }else{
            p->next = new ListNode(arr[i]);
            p = p->next;
        }
    }

    return head;
}

/*
 * assert two SLL equals
 * */
bool assertBST(TreeNode *root1, TreeNode *root2){
    if(!root1){
        EXPECT_EQ(NULL, root2);
        return true;
    }

    EXPECT_EQ(root1->val, root2->val);

    EXPECT_TRUE(assertBST(root1->left, root2->left));
    EXPECT_TRUE(assertBST(root1->right, root2->right));

    return true;
}

/*
 * release the data structure
 * */
void deleteSLL(ListNode* head){
    ListNode *p = head;
    while(p){
        ListNode *tmp = p->next;
        p->next = NULL;
        delete p;
        p = tmp;
    }
    return;
}

void deleteBST(TreeNode *root){
    if(!root)    return;

    deleteBST(root->left);
    root->left = NULL;

    deleteBST(root->right);
    root->right = NULL;

    delete root;
    return;
}

/*
 * test case
 * */
TEST(sortedSLL2BBST_Test, Positive01){
    Solution s;

    ListNode *head = constructSLL();

    TreeNode *result = s.sortedSLL2BBST(head);
    TreeNode *expected = constructBST();

    EXPECT_TRUE(assertBST(expected, result));

    deleteBST(expected);
    deleteBST(result);
    deleteSLL(head);
}

TEST(sortedArray2BBST_Test, Positive01){
    Solution s;

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    vector<int> num(arr, arr + sizeof(arr) / sizeof(int));

    TreeNode *result = s.sortedArray2BBST(num);
    TreeNode *expected = constructBST();

    EXPECT_TRUE(assertBST(expected, result));

    deleteBST(expected);
    deleteBST(result);
    num.clear();
}
