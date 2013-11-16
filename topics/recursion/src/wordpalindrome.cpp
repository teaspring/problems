/***********************<DataStructureInC++> chapter5 recursion********************
 * exercise13: check recursively if the following objects are palindromes:
 * 1. a word
 * 2. a sentence(ignoring blanks, lower/uppercase, and punctuation marks)
 *
 * test data:
 * "Madam,I'm Adam", yes
 *
 * note: ASCII: A-Z(65 -- 90), a-z(97-122)
 * */

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

bool wordpalindrome(const char* word, int length){
    if(length < 2)
      return true;
    if(*word == *(word + length-1))
      return wordpalindrome(word+1, length-2);
    else
      return false;
}

/*
 * for palindrome identificaiton, recursion is too inefficient
 * */
bool sentencepalindrome(const char* sentence, int length){
    if(length < 2)
      return true;
    int i = 0;
    while(!isalpha(*(sentence+i)))
      i++;
    int j=1;
    while(!isalpha(*(sentence + length - j)))
      j++;
    if(toupper(*(sentence+i)) == toupper(*(sentence+length-j)))
      return sentencepalindrome(sentence+i+1, length-j-i-1);
    else
      return false;
}

int main(int argc, char* argv[]){
    string str("Madam, I'm Adam");
    bool result = sentencepalindrome(str.c_str(), str.size());
    cout << (result ? "true" : "false") <<endl;
    return 0;
}
