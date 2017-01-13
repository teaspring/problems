#include "removeSLLElements.cpp"
#include "gtest/gtest.h"

/*
 * ListNode* removeSLLElements(ListNode* head, int val)
 *
 * in preliminary.cpp:
 * struct ListNode
 * ListNode* createSLL(int A[], int n)
 * delSLL(ListNode *head)
 *
 * */

void assertSLL(ListNode* head, int A[], int n){
    ListNode *h = head;
    for(int i = 0; i < n; i++){
        EXPECT_EQ(A[i], h->val);
        h = h->next;
    }
    EXPECT_EQ(NULL, h);
}

/* ------------------ test body ---------------- */
TEST(removeSLLElementsTest, Positive01){
    Solution s;

    int arr[] = {1, 2, 6, 4, 3, 5, 6};
    ListNode* head = createSLL(arr, sizeof(arr)/sizeof(int));
    int val = 6;
    head = s.removeSLLElements(head, val);

    int expected[] = {1, 2, 4, 3, 5};
    assertSLL(head, expected, sizeof(expected)/sizeof(int));

    delSLL(head);
}

TEST(removeSLLElementsTest, Positive02){
    Solution s;

    int arr[] = {3, 1, 3, 3, 3, 3, 3};
    ListNode* head = createSLL(arr, sizeof(arr)/sizeof(int));
    int val = 3;
    head = s.removeSLLElements(head, val);

    int expected[] = {1};
    assertSLL(head, expected, sizeof(expected)/sizeof(int));

    delSLL(head);
}

TEST(removeSLLElementsTest, Negative01){
    Solution s;

    int arr[] = {2, 2, 2, 2};
    ListNode* head = createSLL(arr, sizeof(arr)/sizeof(int));
    int val = 2;
    head = s.removeSLLElements(head, val);
    EXPECT_EQ(NULL, head);
}
