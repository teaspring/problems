#include "mergeSortedList.cpp"
#include "gtest/gtest.h"

/*
 * mergeSortedList.cpp:
 * ListNode* mergeList(vector<ListNode*>&)
 *
 * perliminary.cpp:
 * ListNode* createSLL(int*, int n)
 * void delSLL(ListNode*)
 *
 * <algorithm>
 * sort()
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
TEST(mergeSortedListTest, Positive01){
    Solution s;

    int A[] = {1, 4, 5, 6, 8, 12, 15, 16};
    int B[] = {2, 3, 7, 9, 10, 11, 13, 14, 17, 20};
    const int n1 = sizeof(A)/sizeof(int);
    const int n2 = sizeof(B)/sizeof(int);

    ListNode *l1 = createSLL(A, n1);
    ListNode *l2 = createSLL(B, n2);

    ListNode* result = s.mergeList(l1, l2);

    vector<int> expectedVector;  // values of expected list

    for(int i = 0; i < n1; i++){
        expectedVector.push_back(A[i]);
    }

    for(int i = 0; i < n2; i++){
        expectedVector.push_back(B[i]);
    }

    sort(expectedVector.begin(), expectedVector.end()); // <algorithm>, std::sort()

    ListNode *expected = new ListNode(expectedVector[0]);
    ListNode *h = expected;
    for(int i = 1; i < n1 + n2; i++){
        h->next = new ListNode(expectedVector[i]);
        h = h->next;
    }

    assertList(expected, result);

    expectedVector.clear();
    delSLL(expected);
    delSLL(result);
}
