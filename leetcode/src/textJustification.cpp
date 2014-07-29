/*
 * textJustification.h
 * principles:
 * 1. pack as many words in a line as you can, pad extra spaces ' ' between words if necessary
 * 2. extra spaces between words should be evenly. if the number of spaces do not divide evenly, put more spaces on left slots tha right
 * 3. the last line should be left justified and no extra spaces between words
 * 4. if a line other than the last line contains only one word, left justified
 */

#include "stdio.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * NOTE: distribute benefit in left slots evenly!!
 * * */
string fillLine(vector<string>& words, int L, int start, int count, int benefit, int interval){
    char arr[L+1];
    int t=0;
    for(int i=start; i < start + count; ++i){
        if(i==start){
            for(size_t j=0; j<words[i].size(); ++j){
                arr[t++] = words[i][j];
            }
        }else{
            if(benefit > 0){
                arr[t++] = ' ';
                --benefit;
            }
            for(int j=0; j<interval; ++j){
                arr[t++] = ' ';
            }
            for(size_t j=0; j<words[i].size(); ++j){
                arr[t++] = words[i][j];
            }
        }
    }
    while(t<L){    // for last line
        arr[t++] = ' ';
    }
    arr[L] = '\0';
    return string(arr, arr+L);
}

vector<string> fullJustify(vector<string>& words, int L){
    vector<string> res;
    int i=0, j=0, n=words.size();
    while(i < n){
        int solidL = words[i].size();
        if(solidL > L)    break;
        int interval = 1, cw = 1;
        j = i+1;
        for(; solidL < L && j < n; ++j){
            solidL += (interval + words[j].size());
            ++cw;
        }
        if(solidL > L){
            solidL -= (interval + words[j-1].size());
            --cw;
            --j;
        }
        int extras = 0;
        if(cw == 1){    // with only 1 word, left justified
            interval = 0;
            extras   = L - solidL;
        }else if(j < n){    // not the last line
            interval += (L - solidL) / (cw - 1);  // solidL contains one space for (n-1) slots already
            extras    = (L - solidL) % (cw - 1);
        }
        //printf("i = %d, cw = %d, benefit = %d, interval = %d\n", i, cw, benefit, interval);
        string line = fillLine(words, L, i, cw, extras, interval);
        res.push_back(line);
        i += cw;
    }
    return res;
}

void display(vector<string>& lines){
    for(size_t i = 0; i<lines.size(); ++i){
        cout << lines[i] << endl;
    }
}

void test_01(){
    string arr[] = {"this","would","be","justification"};
    vector<string> words(arr, arr + sizeof(arr)/sizeof(string));
    int L = 14;
    vector<string> lines = fullJustify(words, L);
    display(lines);
}

void test_02(){
    string arr[] = {"to","a","few."};
    vector<string> words(arr, arr + sizeof(arr)/sizeof(string));
    int L = 6;
    vector<string> lines = fullJustify(words, L);
    display(lines);
}

void test_03(){
    string arr[] = {"what", "must", "be", "shall", "be."};
    vector<string> words(arr, arr + sizeof(arr)/sizeof(string));
    int L = 12;
    vector<string> lines = fullJustify(words, L);
    display(lines);
}

void test_04(){
    string arr[] = {"Don't","go","around","saying","the","world","owes","you","a","living;",
                "the","world","owes","you","nothing;","it","was","here","first."};
    vector<string> words(arr, arr + sizeof(arr)/sizeof(string));
    int L = 30;
    vector<string> lines = fullJustify(words, L);
    display(lines);
}

int main(int, char**){
    test_01();
    test_02();
    test_03();
    test_04();
    return 0;
}
