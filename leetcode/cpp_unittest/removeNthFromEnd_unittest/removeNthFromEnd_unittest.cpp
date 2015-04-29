#include "removeNthFromEnd.cpp"
#include "gtest/gtest.h"

/*
 * ListNode* removeNthFromEnd(ListNode* head, int n)
 *
 * in preliminary.cpp:
 * struct ListNode
 * ListNode* createSLL(int A[], int n)
 * delSLL(ListNode *head)
 *
 * */

void assertSLL(ListNode* head, int A[], int n){
    ListNode *h = head;
    for(int i = 0; i < n; i++){
        EXPECT_EQ(A[i], h->val);
        h = h->next;
    }
    EXPECT_EQ(NULL, h);
}

/* ------------------ test body ---------------- */
TEST(removeNthFromEndTest, Positive01){
    Solution s;

    int arr[] = {1, 2, 4, 3, 5};
    ListNode* head = createSLL(arr, sizeof(arr)/sizeof(int));

    const int k = 4;
    int expected[] = {1, 4, 3, 5};

    head = s.removeNthFromEnd(head, k);
    assertSLL(head, expected, sizeof(expected)/sizeof(int));

    delSLL(head);
}

TEST(removeNthFromEndTest, Positive02){
    Solution s;

    int arr[] = {0, 1, 2};
    ListNode* head = createSLL(arr, sizeof(arr)/sizeof(int));

    const int k = 2;
    int expected[] = {0, 2};

    head = s.removeNthFromEnd(head, k);
    assertSLL(head, expected, sizeof(expected)/sizeof(int));

    delSLL(head);
}

TEST(removeNthFromEndTest, Positive03){
    Solution s;

    int arr[] = {0, 1};
    ListNode* head = createSLL(arr, sizeof(arr)/sizeof(int));

    const int k = 1;
    int expected[] = {0};

    head = s.removeNthFromEnd(head, k);
    assertSLL(head, expected, sizeof(expected)/sizeof(int));

    delSLL(head);
}

TEST(removeNthFromEndTest, Positive04){
    Solution s;

    int arr[] = {0, 1};
    ListNode* head = createSLL(arr, sizeof(arr)/sizeof(int));

    const int k = 2;
    int expected[] = {1};

    head = s.removeNthFromEnd(head, k);
    assertSLL(head, expected, sizeof(expected)/sizeof(int));

    delSLL(head);
}

TEST(removeNthFromEndTest, Positive05){
    Solution s;

    int arr[] = {1};
    ListNode* head = createSLL(arr, sizeof(arr)/sizeof(int));

    const int k = 1;
    head = s.removeNthFromEnd(head, k);
    EXPECT_EQ(NULL, head);

    delSLL(head);
}
