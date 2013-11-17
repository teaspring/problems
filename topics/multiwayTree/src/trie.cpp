/*
* general implementation of trie
*
* */

#include "../header/trie.h"

TrieLeafNode::TrieLeafNode(char *suffix){        //suffix of the word
    leaf = true;
    word = new char[strlen(suffix)+1];
    if(word == 0){
        cerr<< "out of memory2.\n";
        exit(-1);
    }
    strcpy(word, suffix);
}

TrieNonLeafNode::TrieNonLeafNode(char ch){
    ptrs = new TrieNonLeafNode*;
    letters = new char[2];        //constructor, at least ch + '\0'. if more needs to insert,it will be replaced
    if(ptrs==0 || letters == 0 ){
        cerr << "Out of memory3.\n";
        exit(1);
    }
    leaf = false;
    endOfWord = false;
    *ptrs = 0;
    *letters = ch;
    *(letters+1) = '\0';
}

Trie::Trie(char *word):notFound(-1){
    root = new TrieNonLeafNode(*word);
    createLeaf(*word,word+1, root);
}

void Trie::sideView(int depth, TrieNonLeafNode *p, char *prefix){        //print contents of a trie sideways
    register int i;        //assumption: the root is not a leaf
    if(p->leaf){        //p is leaf
        TrieLeafNode *lf = (TrieLeafNode*)p;
        for(i=1;i<=depth;i++){
            cout<<" ";
        }
        cout<<" >> "<<prefix<<"|" << lf->word << endl;    //'|' as seperator between prefix and leaf string
    }else{
        for(i=strlen(p->letters)-1; i>=0; i--){
            if(p->ptrs[i] != 0){                //add the letter
                prefix[depth] = p->letters[i];    //corresponding to
                prefix[depth+1] = '\0';            //position i to prefix
                sideView(depth+1, p->ptrs[i], prefix);
            }
        }
        if(p->endOfWord){
            prefix[depth] = '\0';
            for(i=1; i<=depth+1; i++){
                cout << "    ";
            }
            cout << ">>>" << prefix << "|\n";        //endOfWord flag is set
        }
    }
}

int Trie::position(TrieNonLeafNode *p, char ch){        //find the position to insert a char;return -1 if absent
    size_t i=0;
    for(;i<strlen(p->letters) && p->letters[i]!=ch;i++);
    if(i<strlen(p->letters))
      return i;
    else
      return notFound;
}

bool Trie::wordFound(char *word){
    TrieNonLeafNode *p = root;
    TrieLeafNode *lf;
    int pos;
    while(true){
      if(p->leaf){            // p is leaf
        lf = (TrieLeafNode*)p;
        if(strcmp(word,lf->word) == 0)    //matching suffix of the word should be found
          return true;
        else
          return false;
      }else if(*word == '\0'){    //the end of word has to correspond with the endOfWord marker
        if(p->endOfWord)
          return true;
        else
          return false;
      }else if((pos = position(p, *word)) != notFound 
                && p->ptrs[pos] != 0){    //continue the path
          p = p->ptrs[pos];
          word++;
      }else
        return false;
    }
}

void Trie::addCell(char ch, TrieNonLeafNode *p, int stop){
    int i, len = strlen(p->letters);    //strlen() exclude '\0'
    char *s = p->letters;
    TrieNonLeafNode **tmp = p->ptrs;
    p->letters = new char[len+2];        //move array to add one more char
    p->ptrs = new TrieNonLeafNode*[len+1];//move array to add one more pointer
    if(p->letters == 0 || p->ptrs == 0){
        cerr << "out of memory1.'\n'";
        exit(1);
    }
    for(i=0;i<len+1;i++){
        p->ptrs[i] = 0;
    }
    if(stop < len){
        for(i=len;i>=stop+1;i--){        //if ch not follow all letters in p
            p->ptrs[i] = tmp[i-1];    //copy from tmp letters > ch
            p->letters[i] = s[i-1];
        }
    }
    p->letters[stop] = ch;            //or stop is [length]
    for(i=stop-1; i>=0; i++){
        p->ptrs[i] = tmp[i];
        p->letters[i] = s[i];
    }
    p->letters[len+1] = '\0';
    delete[] s;
    s = 0;
}

void Trie::createLeaf(char ch, char *suffix, TrieNonLeafNode *p){
    int pos = position(p,ch);
    if(pos == notFound){
        for(pos=0;pos < strlen(p->letters) && p->letters[pos] < ch; pos++);
        addCell(ch,p,pos);    //pos is either less than length-1 or length
    }
    p->ptrs[pos] = (TrieNonLeafNode*) new TrieLeafNode(suffix);
}

void Trie::insert(char *word){
    
}

int main(int argc, char* argv[]){
    return 0;
}
