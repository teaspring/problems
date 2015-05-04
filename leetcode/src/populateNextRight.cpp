/*
 * assume each binary tree node has one another pointer to next right node. write a function to connect this pointer of each node in a binary tree.
 *
 * e.g. 
 *    1                 1 -> null
 *   / \              /   \
 *  2   3   ==>      2 ->  3 -> null
 * / \ / \          / \   / \
 *4  5 6  7        4 ->5->6->7 -> null
 * 
 *
 * solution: BFS, traverse every horizontal level once, using two queue to save traversed node. this solution has no dependence on the binary tree shape, either perfect BST or not does not matter.
 * */

#include <string>
#include <cstring>
#include <queue>

using namespace std;

struct TreeLinkNode{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL){}
};

typedef TreeLinkNode* pTLN;


class Solution{

public:
    /*
     *
     * */
    void connect(TreeLinkNode *root){
        if(!root)    return;

        queue<TreeLinkNode*> qArr[2];

        int idx = 0;
        qArr[idx].push(root);

        while(!qArr[idx].empty()){
            // remember queue.front() is the eldest element, equals to the one removed by pop()
            for(TreeLinkNode *curr = qArr[idx].front(), *last = NULL;
                !qArr[idx].empty();
                last = curr, curr = qArr[idx].front()){

                qArr[idx].pop();

                pushChildren(curr, qArr[1 - idx]);

                if(NULL != last)    last->next = curr;
            }

            idx = 1 - idx;
        }
    }

    /*
     * used to push left child and right child of root to queue
     * */
    static void pushChildren(TreeLinkNode* root, queue<TreeLinkNode*>& q){
        if(!root)    return;

        if(NULL != root->left){
            q.push(root->left);
        }

        if(NULL != root->right){
            q.push(root->right);
        }
    }

};

/* unit test is in ../cpp_unittest/populateNextRight_unittest */
