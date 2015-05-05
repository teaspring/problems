#include "reverseNodesInK.cpp"
#include "gtest/gtest.h"

/*
 * reorderSLL.cpp:
 * ListNode* reverseKGroups(ListNode *head, int k)
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

/* ------------------ test body ---------------- */
TEST(reorderTest, Positive01){
    Solution s;

    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    int k = 2;
    ListNode *result = s.reverseKGroups(l1, k);

    int B[] = {2, 1, 4, 3, 6, 5, 8, 7, 9};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *expected = createSLL(B, n2);

    assertList(expected, result);

    delSLL(expected);
    delSLL(result);
}

TEST(reorderTest, Positive02){
    Solution s;

    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    int k = 3;
    ListNode *result = s.reverseKGroups(l1, k);

    int B[] = {3, 2, 1, 6, 5, 4, 9, 8, 7, 10, 11};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *expected = createSLL(B, n2);

    assertList(expected, result);

    delSLL(expected);
    delSLL(result);
}

TEST(reorderTest, Positive03){
    Solution s;

    int A[] = {1, 2, 3, 4, 5, 6};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    int k = 2;
    ListNode *result = s.reverseKGroups(l1, k);

    int B[] = {2, 1, 4, 3, 6, 5};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *expected = createSLL(B, n2);

    assertList(expected, result);

    delSLL(expected);
    delSLL(result);
}

TEST(reorderTest, Positive04){
    Solution s;

    int A[] = {1, 2, 3, 4, 5, 6};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    int k = 7;
    ListNode *result = s.reverseKGroups(l1, k);

    int B[] = {1, 2, 3, 4, 5, 6};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *expected = createSLL(B, n2);

    assertList(expected, result);

    delSLL(expected);
    delSLL(result);
}

