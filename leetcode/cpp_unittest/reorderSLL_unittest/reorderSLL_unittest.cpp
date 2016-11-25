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

/* --------- test case of reorderSLL() ---------- */
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

/* --------- test case of reverseSLL() ---------- */
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

/* --------- test case of halveSLL() ---------- */
TEST(halveTest, Positive01){
    Solution s;

    int A[] = {3, 5};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    ListNode *res = s.halveSLL(l1);

    int B[] = {3};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *l2 = createSLL(B, n2);
    assertList(l2, l1);

    int C[] = {5};
    const int n3 = sizeof(C) / sizeof(int);
    ListNode *l3 = createSLL(C, n3);
    assertList(l3, res);

    delSLL(l1);
    delSLL(l2);
    delSLL(l3);
    delSLL(res);
}

TEST(halveTest, Positive02){
    Solution s;

    int A[] = {3, 5, 4};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    ListNode *res = s.halveSLL(l1);

    int B[] = {3, 5};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *l2 = createSLL(B, n2);
    assertList(l2, l1);

    int C[] = {4};
    const int n3 = sizeof(C) / sizeof(int);
    ListNode *l3 = createSLL(C, n3);
    assertList(l3, res);

    delSLL(l1);
    delSLL(l2);
    delSLL(l3);
    delSLL(res);
}

/*----------- test splitOddEvenSLL() ------------ */
TEST(splitOddEvenTest, Positive01){
    Solution s;
    int A[] = {1};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    ListNode *res = s.splitOddEvenSLL(l1);

    int B[] = {1};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *l2 = createSLL(B, n2);

    assertList(l2, l1);
    EXPECT_EQ(NULL, res);

    delSLL(l1);
    delSLL(l2);
    delSLL(res);
}

TEST(splitOddEvenTest, Positive02){
    Solution s;
    int A[] = {1, 2};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    ListNode *res = s.splitOddEvenSLL(l1);

    int B[] = {1};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *l2 = createSLL(B, n2);

    int C[] = {2};
    const int n3 = sizeof(C) / sizeof(int);
    ListNode *l3 = createSLL(C, n3);

    assertList(l2, l1);
    assertList(l3, res);

    delSLL(l1);
    delSLL(l2);
    delSLL(l3);
    delSLL(res);
}

TEST(splitOddEvenTest, Positive03){
    Solution s;
    int A[] = {1, 2, 3};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    ListNode *res = s.splitOddEvenSLL(l1);

    int B[] = {1, 3};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *l2 = createSLL(B, n2);

    int C[] = {2};
    const int n3 = sizeof(C) / sizeof(int);
    ListNode *l3 = createSLL(C, n3);

    assertList(l2, l1);
    assertList(l3, res);

    delSLL(l1);
    delSLL(l2);
    delSLL(l3);
    delSLL(res);
}

TEST(splitOddEvenTest, Positive04){
    Solution s;
    int A[] = {1, 2, 3, 4};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    ListNode *res = s.splitOddEvenSLL(l1);

    int B[] = {1, 3};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *l2 = createSLL(B, n2);

    int C[] = {2, 4};
    const int n3 = sizeof(C) / sizeof(int);
    ListNode *l3 = createSLL(C, n3);

    assertList(l2, l1);
    assertList(l3, res);

    delSLL(l1);
    delSLL(l2);
    delSLL(l3);
    delSLL(res);
}

/*---------- test of recoverReorderSLL --------------*/
TEST(recoverReorderTest, Positive01){
    Solution s;

    int A[] = {1, 5, 7, 2, 4, 11, 3, 9, 8};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    s.reorderSLL(l1);

    int B[] = {1, 8, 5, 9, 7, 3, 2, 11, 4};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *l2 = createSLL(B, n2);
    assertList(l2, l1);

    s.recoverReorderSLL(l1);

    ListNode *l3 = createSLL(A, n1);
    assertList(l3, l1);

    delSLL(l1);
    delSLL(l2);
    delSLL(l3);
}

