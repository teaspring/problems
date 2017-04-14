/*
 * implement a trie(prefix tree) with methods insert(), search(), and startWith()
 * assume all inputs are consist of lowercase letters a-z
 * */
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

/*
 * solution via node with internal node* vector, can handle words of chars besides lower case a-z
 * */
struct node{
    char val;
    bool canLeaf;
    vector<node*> children;
    node(char x) : val(x), canLeaf(false){
        vector<node*> children;
    }
};

class Trie{
public:
    Trie() {
        root = new node((char)NULL);
    }

    ~Trie() {
        stack<node*> stk;
        stk.push(root);
        while(!stk.empty()) {
            node *p = stk.top();
            stk.pop();
            for(auto child : p->children) {
                if(child->children.empty()) {
                    delete child;
                } else {
                    stk.push(child);
                }
            }
            delete p;
        }
    }

    void insert(string word) {
        node *p = root;
        const int n = word.size();
        for(int i = 0; i < n; ++i) {
            node *q = p;
            for(auto child : p->children) {
                if(child->val == word[i]) {
                    q = child;
                    break;
                }
            }

            if(q == p) {
                q = new node(word[i]);
                p->children.push_back(q);
            }
            p = q;
        }
        if(!p->canLeaf)    p->canLeaf = true;
    }

    bool search(string word) {
        node *p = root;
        const int n = word.size();
        for(int i = 0; i < n; ++i) {
            node *q = p;
            for(auto child : p->children) {
                if(child->val == word[i]) {
                    q = child;
                    break;
                }
            }
            if(q == p)    return false;
            p = q;
        }
        return p->canLeaf;
    }

    /*
     * what's meaning of startWith() of Trie?
     * */
    bool startWith(string prefix) {
        node *p = root;
        const int n = prefix.size();
        for(int i = 0; i < n; ++i) {
            node *q = p;
            for(auto child : p->children) {
                if(child->val == prefix[i]) {
                    q = child;
                    break;
                }
            }
            if(q == p)    return false;
            p = q;
        }
        return true;
    }

private:
    node* root;
};

/*
 * solution via node of int[26], with assumption that all the input words are in lower case
 * */
struct TrieNode{
    TrieNode* next[26];
    bool isWord;

    TrieNode(bool b = false) {
        memset(next, 0, sizeof(next));
        isWord = b;
    }
};

class TrieInts {
public:
    TrieInts() {
        root = new TrieNode();
    }

    void insert(string s) {
        TrieNode *p = root;
        const int n = s.size();
        for(int i = 0; i < n; ++i) {
            int idx = s[i] - 'a';
            if(p->next[idx] == NULL) {
                p->next[idx] = new TrieNode();
            }
            p = p->next[idx];
        }
        p->isWord = true;
    }

    bool search(string word) {
        TrieNode *p = find(word);
        return p && p->isWord;
    }

    bool startWith(string word) {
        return find(word) != NULL;
    }

private:
    TrieNode* find(string key) {
        TrieNode *p = root;
        const int n = key.size();
        for(int i = 0; i < n && p; ++i) {
            p = p->next[key[i] - 'a'];
        }
        return p;
    }

private:
    TrieNode *root;
};

/**
 * this class can be instantiated and invoked as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startWith(prefix)
 * */
