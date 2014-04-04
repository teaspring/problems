/*
 * given a list, rotate the list to right by k places, where K >= 0
 * 
 * test case:
 * 1->2->3->4->5, k = 2, return 4->5->1->2->3
 * */
#include "../header/preliminary.h"  //struct ListNode, displayList()

ListNode* rotateRight(ListNode *head, int k){    //twice traverse   
    if(head == NULL || k==0)    return head;
    ListNode *curr = head;
    int n = 1;
    while(curr->next != NULL){    //1st traverse to get length of SLL
        curr = curr->next;
        ++n;
    }
    curr->next = head;   //enable it loop
    int l = n - (k%n);
    
    while(l > 0){   //2nd traverse, curr starts at tail
        curr = curr->next;
        --l;
    }
    ListNode *h = curr->next;
    curr->next = NULL;
    return h;
}

ListNode* generateList(int *arr, int n){
    if(n<1)        return NULL;
    ListNode *head = new ListNode(arr[0]);
    ListNode *h = head;
    for(int i=1; i<n; ++i){
        h->next = new ListNode(arr[i]);
        h = h->next;
    }
    return head;
}

void test_01(){
    string str;
    while(1){
        printf("please input integer array of List:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        ListNode *head = generateList(arr, n);
        delete[] arr;
        arr = 0;

        printf("input k offset to rotate right:\n");
        if(getline(cin, str)==0 || str.empty())        continue;
        int k = atoi(str.c_str());
        ListNode *h = rotateRight(head, k);
        displaySLL(h);

        delSLL(h);
    }
    return;
}

int main(int, char**){
    test_01();
    return 0;
}

