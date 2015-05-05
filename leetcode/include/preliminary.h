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
#include <cmath>
#include <stack>
#include <algorithm>

using namespace std;

/*
 * 1. support any unknown delimiter(\s,\n,','...) except digit
 * 2. support minus integer, multiple digits but float
 * */
int splitStr2IntArray(const string& str, int *array);

int splitStr2IntArrayExt(const string& str, int *array);

vector<string> splitStr2Vector(const string& str);

/*
* time O(lgm) to get index m == lgn
*/
int getindex(int num, int& t, int e);

void showarray(int *A, int n);

void copyarray(int* dst, int* src, int n);

void displayVector(vector<int>& vec);

/*************ListNode for single linked list*****************/
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

void displaySLL(ListNode *head);

ListNode* createSLL(int A[], int n);

void delSLL(ListNode *head);

/*************TreeNode for binary (search) tree***********/
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(0), right(0){}
};

void preorder(TreeNode *root);

void showPre(TreeNode *root);

void inorder(TreeNode *root);

void showIn(TreeNode *root);

void delTree(TreeNode *root);    //natural for post order

