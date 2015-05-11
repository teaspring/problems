#include "swapNodesInPairs.cpp"
#include "gtest/gtest.h"

/*
 * swapNodesInPairs.cpp:
 * ListNode* swapPairs(ListNode *head)
 *
 * perliminary.cpp:
 * ListNode* createSLL(int*, int n)
 * void delSLL(ListNode*)
 *
 * */

void assertList(ListNode *expected, ListNode *result){
    ListNode *h1 = expected, *h2 = result;

    while(h1 && h2){
        EXPECT_EQ(h1->val, h2->val);
        h1 = h1->next;
        h2 = h2->next;
    }

    EXPECT_EQ(NULL, h1);
    EXPECT_EQ(NULL, h2);
}

/* ------------test cases ---------------- */
TEST(swapPairs_Test, Positive01){
    Solution s;

    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    ListNode *result = s.swapPairs(l1);

    int B[] = {2, 1, 4, 3, 6, 5, 8, 7};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *expected = createSLL(B, n2);

    assertList(expected, result);

    l1 = NULL;
    delSLL(expected);
    delSLL(result);
}

TEST(swapPairs_Test, Positive02){
    Solution s;

    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    ListNode *result = s.swapPairs(l1);

    int B[] = {2, 1, 4, 3, 6, 5, 8, 7, 9};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *expected = createSLL(B, n2);

    assertList(expected, result);

    l1 = NULL;
    delSLL(expected);
    delSLL(result);
}
