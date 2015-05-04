#include "partitionList.cpp"
#include "gtest/gtest.h"

/*
 * partitionList.cpp:
 * ListNode* partition(ListNode* head, int x)
 *
 * perliminary.cpp:
 * ListNode* createSLL(int*, int n)
 * void delSLL(ListNode*)
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
TEST(removeTest, Positive01){
    Solution s;

    int A[] = {1, 4, 3, 2, 5, 2};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    int x = 3;

    ListNode* result = s.partition(l1, x);

    int B[] = {1, 2, 2, 4, 3, 5};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *expected = createSLL(B, n2);

    assertList(expected, result);

    delSLL(expected);
    delSLL(result);
}

TEST(removeTest, Positive02){
    Solution s;

    int A[] = {4, 3, 2, 5, 2};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    int x = 3;

    ListNode* result = s.partition(l1, x);

    int B[] = {2, 2, 4, 3, 5};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *expected = createSLL(B, n2);

    assertList(expected, result);

    delSLL(expected);
    delSLL(result);
}

TEST(removeTest, Positive03){
    Solution s;

    int A[] = {1, 4, 3, 2, 0, 2, -1};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    int x = 3;

    ListNode* result = s.partition(l1, x);

    int B[] = {1, 2, 0, 2, -1, 4, 3};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *expected = createSLL(B, n2);

    assertList(expected, result);

    delSLL(expected);
    delSLL(result);
}
