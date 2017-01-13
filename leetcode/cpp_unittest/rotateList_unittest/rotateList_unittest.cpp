#include "rotateList.cpp"
#include "gtest/gtest.h"

/*
 * rotateList.cpp:
 * ListNode* rotateRight(ListNode* head, int k)
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

/* ------------rotateRight() test cases ---------------- */
TEST(rotateRight_Test, Positive01){
    Solution s;

    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    int k = 3;
    ListNode *result = s.rotateRight(l1, k);

    int B[] = {6, 7, 8, 1, 2, 3, 4, 5};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *expected = createSLL(B, n2);

    assertList(expected, result);

    delSLL(expected);
    delSLL(result);
}

TEST(rotateRight_Test, Positive02){
    Solution s;

    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    int k = 7;
    ListNode *result = s.rotateRight(l1, k);

    int B[] = {2, 3, 4, 5, 6, 7, 8, 1};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *expected = createSLL(B, n2);

    assertList(expected, result);

    delSLL(expected);
    delSLL(result);
}

TEST(rotateRight_Test, Negative01){
    Solution s;

    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    int k = 8;
    ListNode *result = s.rotateRight(l1, k);

    int B[] = {1, 2, 3, 4, 5, 6, 7, 8};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *expected = createSLL(B, n2);

    assertList(expected, result);

    delSLL(expected);
    delSLL(result);
}

TEST(rotateRight_Test, Negative02){
    Solution s;

    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    int k = 9;
    ListNode *result = s.rotateRight(l1, k);

    int B[] = {8, 1, 2, 3, 4, 5, 6, 7};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *expected = createSLL(B, n2);

    assertList(expected, result);

    delSLL(expected);
    delSLL(result);
}

