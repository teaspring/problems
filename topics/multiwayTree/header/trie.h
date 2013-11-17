/*
 * <DataStructure&AlgorithmInC++> chapter7 Multiway Tree,a spell checker in use of trie
 * its core data structure allows efficient access of thousands of words in a dictionary. Trie is the choose. 
 * When a written word is loaded, it will go down the Trie to find the word. if not, this word is thought invalid
 **/

#include <iostream>
#include <cstring>
#include <string>
#include "stdlib.h"
using namespace std;

class TrieNonLeafNode{
public:
    TrieNonLeafNode(){}
    TrieNonLeafNode(char);
private:
    bool leaf, endOfWord;
    char *letters;            //a string attached to the node in alphabetical order
    TrieNonLeafNode **ptrs; //pointer of array of TrieNonLeafNode*
    friend class Trie;
};

class TrieLeafNode{
public:
    TrieLeafNode(){}
    TrieLeafNode(char*);
private:
    bool leaf;
    char *word;
    friend class Trie;
};

class Trie{
public:
    Trie():notFound(-1){
    }
    Trie(char*);
    void sideView(){
        *prefix = '\0';
        sideView(0,root,prefix);
    }
    void insert(char*);
    bool wordFound(char*);
private:
    TrieNonLeafNode *root;
    const int notFound;
    char prefix[80];
    int position(TrieNonLeafNode*, char);
    void addCell(char, TrieNonLeafNode*,int);    //when a char is inserted to the string attached to the node
    void createLeaf(char,char*,TrieNonLeafNode*);
    void sideView(int,TrieNonLeafNode*,char*);
};

