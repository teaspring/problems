/*
 * compare two version numbers, ver1 and ver2
 * return 1 if ver1 > ver2, return -1 if ver1 < ver2, otherwise, return 0
 * each version number is non-empty strings which contains digits and '.'
 * e.g. 0.1 < 1.1 < 1.2 < 1.2.2 < 13.1
 * note: 1.0 == 1
 * */

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>  // atoi()

using namespace std;

class Solution{
public:
    int compareVersion(string ver1, string ver2) {
        const int n1 = ver1.size();
        const int n2 = ver2.size();

        int pos1 = 0, pos2 = 0;
        while(pos1 < n1 || pos2 < n2) {
            int val1 = (pos1 < n1) ? getNextInt(ver1, '.', pos1) : 0;
            int val2 = (pos2 < n2) ? getNextInt(ver2, '.', pos2) : 0;
            if(val1 > val2) {
                return 1;
            } else if(val1 < val2) {
                return -1;
            }
        }

        if (pos1 >= n1 && pos2 >= n2) { // both versions have same length, and all of chars are identical
            return 0;
        } else if (pos1 >= n1) {
            return -1;
        } else {
            return 1;
        }
    }

private:
    int getNextInt(string& str, char ch, int& pos) {
        int found = (int)str.find(ch, pos);
        if(found == (int)string::npos) {
            found = str.size();
        }

        char tmp[found - pos + 1];
        memset(tmp, 0, sizeof(tmp));
        for (int i = 0; i < found - pos; i++) {
            tmp[i] = str.at(i + pos);
        }
        tmp[found - pos] = '\0';

        pos = found + 1;
        return atoi(tmp);
    }
};
