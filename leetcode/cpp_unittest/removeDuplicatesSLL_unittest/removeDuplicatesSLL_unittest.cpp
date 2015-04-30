#include "removeDuplicatesSLL.cpp"
#include "gtest/gtest.h"

/*
 * removeDuplicatesSLL.cpp:
 * ListNode* remove(ListNode*)
 * ListNode* removeII(ListNode*)
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
TEST(removeTest, Positive01){
    Solution s;

    int A[] = {1, 1, 2, 2, 2, 3, 4, 4};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    ListNode* result = s.remove(l1);

    int B[] = {1, 2, 3, 4};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *expected = createSLL(B, n2);

    assertList(expected, result);

    delSLL(expected);
    delSLL(result);
}

TEST(removeII_1_Test, Positive01){
    Solution s;

    int A[] = {1, 1, 1, 2, 3, 3, 4};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    ListNode* result = s.removeII_1(l1);

    int B[] = {2, 4};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *expected = createSLL(B, n2);

    assertList(expected, result);

    delSLL(expected);
    delSLL(result);
}

TEST(removeII_1_Test, Positive02){
    Solution s;

    int A[] = {2, 1, 1};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    ListNode* result = s.removeII_1(l1);

    int B[] = {2};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *expected = createSLL(B, n2);

    assertList(expected, result);

    delSLL(expected);
    delSLL(result);
}

TEST(removeII_1_Test, Positive03){
    Solution s;

    int A[] = {1, 1, 2, 2};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    ListNode* result = s.removeII_1(l1);
    EXPECT_EQ(NULL, result);
}

TEST(removeII_2_Test, Positive01){
    Solution s;

    int A[] = {1, 1, 1, 2, 3, 3, 4};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    ListNode* result = s.removeII_2(l1);

    int B[] = {2, 4};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *expected = createSLL(B, n2);

    assertList(expected, result);

    delSLL(expected);
    delSLL(result);
}

TEST(removeII_2_Test, Positive02){
    Solution s;

    int A[] = {2, 1, 1};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    ListNode* result = s.removeII_2(l1);

    int B[] = {2};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *expected = createSLL(B, n2);

    assertList(expected, result);

    delSLL(expected);
    delSLL(result);
}

TEST(removeII_2_Test, Positive03){
    Solution s;

    int A[] = {1, 1, 2, 2};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *l1 = createSLL(A, n1);

    ListNode* result = s.removeII_2(l1);
    EXPECT_EQ(NULL, result);
}
