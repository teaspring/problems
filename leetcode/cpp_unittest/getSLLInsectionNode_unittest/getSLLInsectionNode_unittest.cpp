#include "getSLLInsectionNode.cpp"
#include "gtest/gtest.h"

/*
 * getSLLInsectionNode.cpp:
 * ListNode* getInsectionNode01(ListNode*, ListNode*)
 *
 * perliminary.cpp:
 * ListNode* createSLL(int*, int n)
 * void delSLL(ListNode*)
 *
 * */

ListNode* tailSLL(ListNode *head) {
    ListNode *p = head;
    while(p->next) {
        p = p->next;
    }
    return p;
}

/* --------- test case of getInsectionNode01() ---------- */
TEST(getInsectionNode01Test, Positive01){
    Solution s;

    int A[] = {1};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *headA = createSLL(A, n1);

    int B[] = {6, 8, 5, 9, 7, 3, 2, 11, 4};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *headB = createSLL(B, n2);

    int C[] = {5, 8};
    const int n3 = sizeof(C) / sizeof(int);
    ListNode *headC = createSLL(C, n3);

    ListNode *tailA = tailSLL(headA);
    ListNode *tailB = tailSLL(headB);
    tailA->next = headC;
    tailB->next = headC;

    ListNode *res = s.getInsectionNode01(headA, headB);
    EXPECT_EQ(headC, res);

    tailA->next = NULL;
    tailB->next = NULL;
    delSLL(headA);
    delSLL(headB);
    delSLL(headC);
}

TEST(getInsectionNode01Test, Positive02){
    Solution s;

    int A[] = {6, 8, 5, 9, 7, 3, 2, 11, 4};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *headA = createSLL(A, n1);

    int B[] = {5, 8, 2};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *headB = createSLL(B, n2);

    ListNode *tailA = tailSLL(headA);
    tailA->next = headB;

    ListNode *res = s.getInsectionNode01(headA, headB);
    EXPECT_EQ(headB, res);

    tailA->next = NULL;
    delSLL(headA);
    delSLL(headB);
}

TEST(getInsectionNode01Test, Negative01){
    Solution s;

    int A[] = {1, 3};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *headA = createSLL(A, n1);

    int B[] = {6, 8, 5, 9, 7, 3, 2, 11, 4};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *headB = createSLL(B, n2);

    ListNode *res = s.getInsectionNode01(headA, headB);
    EXPECT_EQ(NULL, res);

    delSLL(headA);
    delSLL(headB);
}

TEST(getInsectionNode01Test, Negative02){
    Solution s;

    int A[] = {6, 8, 5, 9, 7, 3, 2, 11, 4};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *headA = createSLL(A, n1);

    int B[] = {3};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *headB = createSLL(B, n2);

    ListNode *res = s.getInsectionNode01(headA, headB);
    EXPECT_EQ(NULL, res);

    delSLL(headA);
    delSLL(headB);
}

/* --------- test case of getInsectionNode02() ---------- */
TEST(getInsectionNode02Test, Positive01){
    Solution s;

    int A[] = {1};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *headA = createSLL(A, n1);

    int B[] = {6, 8, 5, 9, 7, 3, 2, 11, 4};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *headB = createSLL(B, n2);

    int C[] = {5, 8};
    const int n3 = sizeof(C) / sizeof(int);
    ListNode *headC = createSLL(C, n3);

    ListNode *tailA = tailSLL(headA);
    ListNode *tailB = tailSLL(headB);
    tailA->next = headC;
    tailB->next = headC;

    ListNode *res = s.getInsectionNode02(headA, headB);
    EXPECT_EQ(headC, res);

    tailA->next = NULL;
    tailB->next = NULL;
    delSLL(headA);
    delSLL(headB);
    delSLL(headC);
}

TEST(getInsectionNode02Test, Positive02){
    Solution s;

    int A[] = {6, 8, 5, 9, 7, 3, 2, 11, 4};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *headA = createSLL(A, n1);

    int B[] = {5, 8, 2};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *headB = createSLL(B, n2);

    ListNode *tailA = tailSLL(headA);
    tailA->next = headB;

    ListNode *res = s.getInsectionNode02(headA, headB);
    EXPECT_EQ(headB, res);

    tailA->next = NULL;
    delSLL(headA);
    delSLL(headB);
}

TEST(getInsectionNode02Test, Negative01){
    Solution s;

    int A[] = {1, 3};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *headA = createSLL(A, n1);

    int B[] = {6, 8, 5, 9, 7, 3, 2, 11, 4};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *headB = createSLL(B, n2);

    ListNode *res = s.getInsectionNode02(headA, headB);
    EXPECT_EQ(NULL, res);

    delSLL(headA);
    delSLL(headB);
}

TEST(getInsectionNode02Test, Negative02){
    Solution s;

    int A[] = {6, 8, 5, 9, 7, 3, 2, 11, 4};
    const int n1 = sizeof(A) / sizeof(int);
    ListNode *headA = createSLL(A, n1);

    int B[] = {3};
    const int n2 = sizeof(B) / sizeof(int);
    ListNode *headB = createSLL(B, n2);

    ListNode *res = s.getInsectionNode02(headA, headB);
    EXPECT_EQ(NULL, res);

    delSLL(headA);
    delSLL(headB);
}
