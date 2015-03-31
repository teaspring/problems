#include "convertBST2SortedDLL.cpp"
#include "gtest/gtest.h"

/*
 * node* Solution::BST2SortedDLL_01(node* root)
 * node* Solution::BST2SortedDLL_02(node* root)
 * node* Solution::BST2SortedDLL_03(node* root)
 * */

node* constructBST(){
    node* root = new node(4);

    root->left = new node(2);
    root->right = new node(6);

    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->left = new node(5);
    root->right->right = new node(7);

    return root;
}

node* constructCircularDLL(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(int);

    node *head = NULL, *p = NULL;
    for(int i = 0; i < n; i++){
        if(!p){
            head = new node(arr[i]);
            p = head;
        }else{
            p->right = new node(arr[i]);
            p->right->left = p;
            p = p->right;
        }
    }
    p->right = head; // circular
    head->left = p;

    return head;
}

bool assertDLL(node *head1, node *head2){
    node *p1 = head1, *p2 = head2;
    do{
        EXPECT_EQ(p1->val, p2->val);

        p1 = p1->right;
        p2 = p2->right;
    }while(p1 != head1 && p2 != head2);

    EXPECT_TRUE(p1 == head1 && p2 == head2); // assert size of circular

    return true;
}

void deleteCircularDLL(node* head){
    head->left->right = NULL;  // unplug head and tail
    head->left = NULL;

    node *p = head;
    while(p){
        node *next = p->right;
        p->right = NULL;  // unplug
        if(next)    next->left = NULL;

        delete p;
        p = next;
    }
    return;
}

TEST(Solution01_Test, Positive01){
    Solution s;

    node *root = constructBST();
    node *expected = constructCircularDLL();
    node *result = s.BST2SortedDLL_01(root);

    EXPECT_TRUE(assertDLL(expected, result));

    deleteCircularDLL(expected);
    deleteCircularDLL(result);
}

TEST(Solution02_Test, Positive01){
    Solution s;

    node *root = constructBST();
    node *expected = constructCircularDLL();
    node *result = s.BST2SortedDLL_02(root);

    EXPECT_TRUE(assertDLL(expected, result));

    deleteCircularDLL(expected);
    deleteCircularDLL(result);
}

TEST(Solution03_Test, Positive01){
    Solution s;

    node *root = constructBST();
    node *expected = constructCircularDLL();
    node *result = s.BST2SortedDLL_03(root);

    EXPECT_TRUE(assertDLL(expected, result));

    deleteCircularDLL(expected);
    deleteCircularDLL(result);
}
