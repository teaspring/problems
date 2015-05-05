/*
 * reverse a string word by word. besides normal question of reverse, some clarification are necessary to mention:
 * 1. a word is constituted of non-space characters.
 * 2. reversed result should not contain leading/tailing spaces
 * */
#include <string>
#include <cstring>
#include <cctype>  // isspace(char)

using namespace std;

class Solution{

public:
	/*
	 * 1. remove excessive spaces
	 * 2. reverse each word
	 * 3. reverse whole string
	 * */
	void reverseWords(string& src){
		src = reduceSpaces(src);

		if(src.empty())    return;

		const int n = src.size();

		// b is inclusive and e is exclusive
		for(int b = 0, e = 0; b < n && e <= n; ++e){
			if(e < n && !isspace(src[e]))    continue;

			if(b < e-1)    reverseItem(src, b, e);

			b = e + 1;    // after reduceSpaces(), space between words is 1 absolutely
		}

		reverseItem(src, 0, n);
	}

private:
	/*
	 * reduce spaces in input string
	 * 1. eliminate the leading and tailing spaces 
	 * 2. reduce the multiple spaces between two words to one single space
	 * */
	string reduceSpaces(const string& src){
		const int n = src.size();

		char cstr[n + 1];
		memset(cstr, 0, sizeof(cstr));

		int j = 0;
		for(int i = 0; i < n; ++i){
			if(isspace(src[i]))    continue;

			if(i > 0 && isspace(src[i-1]) && j > 0 && !isspace(cstr[j-1])){    // add single space before following word
				cstr[j++] = ' ';
			}

			cstr[j++] = src[i];
		}
		cstr[j] = '\0';

		return string(cstr);
	}

	void reverseItem(string& src, int begin, int end){
		int mid = (end + begin) >> 1;
		for(int i = begin; i < mid; ++i){
			swapCharInStr(src, i, --end);
		}
	}

	void swapCharInStr(string& str, int l, int r){
		char tmp = str[l];
		str[l] = str[r];
		str[r] = tmp;
	}
};

/* unit test is in ../cpp_unittest/reverseWords_unittest */
