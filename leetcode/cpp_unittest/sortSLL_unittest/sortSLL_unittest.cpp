#include "sortSLL.cpp"
#include "gtest/gtest.h"

/*
 * sortSLL.cpp:
 * ListNode* mergesort(ListNode*)
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
TEST(sortSLLTest, Positive01){
    Solution s;

    int A[] = {1, 5, 7, 2, 4, 11, 3, 9, 8};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    ListNode* result = s.mergesort(l1);

    int B[] = {1, 2, 3, 4, 5, 7, 8, 9, 11};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *expected = createSLL(B, n2);

    assertList(expected, result);

    l1 = NULL;
    delSLL(expected);
    delSLL(result);
}

TEST(sortSLLTest, Positive02){
    Solution s;

    int A[] = {11, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    ListNode *result = s.mergesort(l1);

    int B[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *expected = createSLL(B, n2);

    assertList(expected, result);

    l1 = NULL;
    delSLL(expected);
    delSLL(result);
}
