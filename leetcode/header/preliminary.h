/******************preliminary.h**************************/
#include "stdio.h"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <set>
#include "math.h"
#include <stack>
#include <algorithm>

using namespace std;

/*
 * 1. support any unknown delimiter(\s,\n,','...) except digit
 * 2. support minus integer, multiple digits but float 
 * */
int splitStr2IntArray(const string& str, int *array){
    int leng = 0;
    string::size_type  pos = 0;        //string::size_type and std::size_t are alternative
    int minus = 1;
    while(pos<str.size()){    
        if(str[pos] == '-' && pos<(str.size()-1) && isdigit(str[pos+1])){        //support minus
            minus = -1;
        }else if(isdigit(str[pos])){
            string::size_type begin = pos;
            while(pos<str.size() && isdigit(str[pos]))    //at exit, pos is the one following last digit
                pos++;
            char* tmp = new char[pos-begin+1];
            for(size_t i=0;i < pos-begin;i++){
                tmp[i] = str[i+begin];
            }
            tmp[pos-begin] = '\0';
            array[leng++] = minus*atoi(tmp);
            minus = 1;
            delete[] tmp;
            tmp = 0;
        }
        pos++;
    }
    return leng;
}

int splitStr2IntArrayExt(const string& str, int *array){
    int leng = 0;
    string::size_type  pos = 0;        //string::size_type and std::size_t are alternative
    int minus = 1;
    while(pos<str.size()){
        if(str[pos] == '-' && pos<(str.size()-1) && isdigit(str[pos+1])){
            minus = -1;
        }else if(isdigit(str[pos])){
            int val = 0;
            while(pos<str.size() && isdigit(str[pos])){
                char ch = str[pos];          
                val = (val==0) ? atoi(&ch) : 10*val + atoi(&ch);    //it works
                pos++;
            }
            array[leng++] = minus*val;
            minus = 1;
        }
        pos++;
    }
    return leng;
}

vector<string> splitStr2Vector(const string& str){
    vector<string> res;
    int n = str.size();
    if(n<1)    return res;
    int b=-1;
    for(int i=0;i<n;i++){
        if(isalpha(str[i]) || isdigit(str[i])){ //valid str segment
            if(b < 0)    b = i;
        }else if(b >= 0){
            res.push_back(str.substr(b, i-b));
            b = -1;
        }
    }
    if(b>=0){
        res.push_back(str.substr(b, n-b));
    }
    return res;
}

/*
* time O(lgm) to get index m == lgn
*/
int getindex(int num, int& t, int e =10){
    int m=1, pre_m=0, pre_t=1;
    t=e;
    while(num/t < 1 || num/t > 9){
        if(num/t > 9){
            pre_t = t;
            t *= t;
            pre_m = m;
            m *= 2;
        }else{
            t = pre_t * (int)sqrt(t/pre_t);
            m = pre_m + (m-pre_m)/2;
        }
    }
    return m;
}
    
void showarray(int *A, int n){
    for(int i=0;i<n;i++)
        printf("%d ", A[i]);
    printf("\n");
}

void copyarray(int* dst, int* src, int n){
    memset(dst, 0, sizeof(int)*n);
    for(int i=0;i<n;i++)
      dst[i] = src[i];
    return;
}

void displayVector(vector<int>& vec){
    if(vec.size() == 0){
        cout << "empty" << endl;
        return;
    }
    cout << vec[0];
    for(int i=1; i < (int)vec.size(); i++){
        cout << ", " << vec[i];
    }
    cout << endl;
    return;
}

/*************ListNode for single linked list*****************/
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

void displaySLL(ListNode *head){
    printf("SLL is: ");
    if(!head){
        printf("\n");
        return;
    }
    printf("%d", head->val);
    for(ListNode *curr = head->next;curr != NULL; curr=curr->next){
        printf(" -> %d", curr->val);
    }
    printf("\n");
    return;
}

ListNode* createSLL(int A[], int n){
    if(n == 0)    return NULL;
    ListNode *head = new ListNode(A[0]);
    ListNode *h = head;
    for(int i=1; i<n; i++, h = h->next){
        h->next = new ListNode(A[i]);
    }
    return head;
}

void delSLL(ListNode *head){
    if(!head){
        printf("NULL\n");
        return;
    }
    for(ListNode *nx = head; nx != NULL;){
        head  = nx->next;
        delete nx;
        nx = head;
    }
    return;
}

/*************TreeNode for binary (search) tree***********/
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(0), right(0){}
};

void preorder(TreeNode *root){
    if(!root)    return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
    return;
}

void showPre(TreeNode *root){
    printf("preorder: ");
    preorder(root);
    printf("\n");
    return;
}

void inorder(TreeNode *root){
    if(!root)    return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
    return;
}

void showIn(TreeNode *root){
    printf("inorder: ");
    inorder(root);
    printf("\n");
    return;
}

void delTreeNode(TreeNode *root){    //natural for post order
    if(!root)    return;
    delTreeNode(root->left);
    delTreeNode(root->right);
    delete root;
    root = 0;
    return;
}

