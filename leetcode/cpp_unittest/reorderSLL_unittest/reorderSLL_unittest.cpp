#include "reorderSLL.cpp"
#include "gtest/gtest.h"

/*
 * reorderSLL.cpp:
 * void reorderSLL(ListNode*)
 * ListNode* reverseSLL(ListNode*)
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

    int A[] = {1, 5, 7, 2, 4, 11, 3, 9, 8};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *result = createSLL(A, n1);

    s.reorderSLL(result);

    int B[] = {1, 8, 5, 9, 7, 3, 2, 11, 4};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *expected = createSLL(B, n2);

    assertList(expected, result);

    delSLL(expected);
    delSLL(result);
}

TEST(reorderTest, Positive02){
    Solution s;

    int A[] = {1, 5, 7, 2, 4, 11, 3, 9};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *result = createSLL(A, n1);

    s.reorderSLL(result);

    int B[] = {1, 9, 5, 3, 7, 11, 2, 4};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *expected = createSLL(B, n2);

    assertList(expected, result);

    delSLL(expected);
    delSLL(result);
}

TEST(reorderTest, Positive03){
    Solution s;

    int A[] = {1, 5};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *result = createSLL(A, n1);

    s.reorderSLL(result);

    int B[] = {1, 5};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *expected = createSLL(B, n2);

    assertList(expected, result);

    delSLL(expected);
    delSLL(result);
}

TEST(reorderTest, Positive04){
    Solution s;

    int A[] = {1};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *result = createSLL(A, n1);

    s.reorderSLL(result);

    int B[] = {1};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *expected = createSLL(B, n2);

    assertList(expected, result);

    delSLL(expected);
    delSLL(result);
}

TEST(reverseTest, Positive01){
    Solution s;

    int A[] = {1, 5, 7, 2, 4, 11, 3, 9};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    ListNode *result = s.reverseSLL(l1);

    int B[] = {9, 3, 11, 4, 2, 7, 5, 1};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *expected = createSLL(B, n2);

    assertList(expected, result);

    delSLL(expected);
    delSLL(result);
}
