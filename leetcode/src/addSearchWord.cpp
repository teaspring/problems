/**
 * Design a data structure that supports following two methods:
 * +void addWord(word)
 * +bool search(word)
 * search() can search a literal word or a regular expression string containing only letters a-z or '.' which can represent any one letter.
 *
 * For example:
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b.")  -> false
 * search("b..") -> true
 */

#include <string>
#include <cstring>
#include <vector>

using namespace std;

struct TrieNode{
    TrieNode* next[26];
    bool isWord;

    TrieNode(bool b = false) {
        memset(next, 0, sizeof(next));
        isWord = b;
    }
};

/*
 * apparently it should be based on Trie structure, but it needs some update to support wild char '.'
 * */
class WordDictionary {
public:
    // initialize
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode *p = root;
        const int n = word.size();
        for(int i = 0; i < n; ++i) {
            int idx = word[i] - 'a';
            if(!(p->next[idx])) {
                p->next[idx] = new TrieNode();
            }
            p = p->next[idx];
        }
        p->isWord = true;
    }

    bool searchWord(string word) {
        vector<TrieNode*> vec;
        findSubStr(root, vec, word);
        for(auto p : vec) {
            if (p && p->isWord)    return true;
        }
        return false;
    }

private:
    void findSubStr(TrieNode *root, vector<TrieNode*>& options, string key) {
        if(!root)    return;

        TrieNode *p = root;
        if(key.empty()) {
            options.push_back(p);
            return;
        }

        const int n = key.size();
        char ch = key[0];
        if(ch != '.') { // primary letter a-z
            TrieNode *q = p->next[ch - 'a'];
            if(q)    findSubStr(q, options, key.substr(1, n-1));
        } else {
            for(int j = 0; j < 26; ++j) { // key[i] is '.'
                TrieNode *q = p->next[j];
                if(q)    findSubStr(q, options, key.substr(1, n-1));
            }
        }
    }

private:
    TrieNode *root;
};

/*
 * your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool para = obj.search(word);
 * */
