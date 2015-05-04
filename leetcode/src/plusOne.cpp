/*
 * given a non-negative number represented as an array of digits, plus one to the number
 * the digits are stored such that the most significant digit is at the head of the list
 * test data:
 * 9
 * 899
 * 8791238989123
 * */

#include <cstring>
#include <vector>

using namespace std;

class Solution{

public:
    /*
     * as argument integer is represented in vector, the transmission to int is risky of overflow
     * */
    vector<int> plusOne(const vector<int>& digits){
        if(digits.empty())    return vector<int>();

        const int m = digits.size();

        int n = m + 1;

        int arr[n];
        memset(arr, 0, sizeof(arr));

        int i = m-1, j = n-1, over = 1;

        for(; i >= 0; --i, --j){
            int curr = digits[i] + over;
            arr[j] = curr % 10;
            over = curr / 10;
        }

        if(over)    arr[j--] = 1;  // [j] the most significant digit

        return vector<int>(arr + j + 1, arr + n);
    }
};

/* unit test is in ../cpp_unittest/plusOne_unittest */
