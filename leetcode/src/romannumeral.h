/*
 * header of romannumeral.cpp
 * */

#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

class Solution{
	public:
		string int2Roman(int num);

		int roman2Int(const string& str);

		static const int MaxSize = 50;

		static const int tags = 13;

		static const int digits[13];

		static const char alphas[13][3];
};
