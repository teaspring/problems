#include "mergeKSortedList.cpp"
#include "gtest/gtest.h"

/*
 * ListNode* mergeKList(vector<ListNode*>&)
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

/* --------------- test body -------------- */
TEST(mergeKSortedListTest, Positive01){
    Solution s;

    const int rows = 5, cols = 4;
    int arr[][cols] = {
        {1, 5, 10, 12},
        {2, 3, 11, 21},
        {0, 4, 6, 20},
        {-1, 7, 8, 19},
        {6, 9, 14, 17}};

    vector<ListNode*> lists;
    vector<int> expectedVector;  // values of expected list

    for(int i = 0; i < rows; i++){
        ListNode *head = NULL, *h = NULL;
        for(int j = 0; j < cols; j++){

            int x = arr[i][j];

            if(!head){
                head = new ListNode(x);
                h = head;
            }else{
                h->next = new ListNode(x);
                h = h->next;
            }

            expectedVector.push_back(x);
        }
        lists.push_back(head);
    }

    ListNode* result = s.mergeKLists(lists);

    sort(expectedVector.begin(), expectedVector.end()); // <algorithm>, std::sort()

    ListNode *expected = new ListNode(expectedVector[0]);
    ListNode *h = expected;
    for(int i = 1; i < rows * cols; i++){
        h->next = new ListNode(expectedVector[i]);
        h = h->next;
    }

    assertList(expected, result);

    lists.clear();  // every ListNode object is in SLL with head of result
    expectedVector.clear();
    delSLL(expected);
    delSLL(result);
}
