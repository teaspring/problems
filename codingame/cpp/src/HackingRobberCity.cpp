#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution
{
    public:
    string process1(const string& msg_1, const string& msg_2, const string& msg_3)
    {
        size_t arraySize = 0;
        unsigned char* byteArray1 = hexStringToByteArray(msg_1, arraySize);
        unsigned char* byteArray2 = hexStringToByteArray(msg_2, arraySize);
        unsigned char* byteArray3 = hexStringToByteArray(msg_3, arraySize);

        // (C xor A) xor (C xor A xor B) = B 
        unsigned char* tmpByteArray = xorTwoByteArrays(byteArray1, byteArray2, arraySize);
        // (C xor B) xor B = C
        unsigned char* resByteArray = xorTwoByteArrays(tmpByteArray, byteArray3, arraySize);
        
        return byteArrayToString(resByteArray, arraySize);
    }

    private:
    unsigned char* hexStringToByteArray(const string& hexStr, size_t& byteArrSize) {
        byteArrSize = hexStr.length() / 2;
        unsigned char* byteArr = new unsigned char[byteArrSize];

        for (size_t i = 0; i < byteArrSize; i++) {
            string byteString = hexStr.substr(i * 2, 2);
            // "FF" -> 255 -> 0xff
            byteArr[i] = static_cast<unsigned char>(std::stoul(byteString, nullptr, 16));
        }
        return byteArr;
    }

    unsigned char* xorTwoByteArrays(const unsigned char* byteArray1, const unsigned char* byteArray2, const size_t& arrSize)
    {
        unsigned char* resByteArr = new unsigned char[arrSize];
        for (size_t i = 0; i < arrSize; i++)
        {
            resByteArr[i] = *(byteArray1 + i) ^ *(byteArray2 + i);
        }
        return resByteArr;
    }

    string byteArrayToString(const unsigned char* byteArray, const size_t& arrSize)
    {
        char* charArray = new char[arrSize+1];
        charArray[arrSize] = '\0';
        for (auto i = 0; i < arrSize; i++)
        {
            // 0x41 -> 'A' == ASCII int(65)
            charArray[i] = static_cast<char>(byteArray[i]);
        }
        return string(charArray);
    }

    public:
    string process2(const string& m1, const string& m2, const string& m3)
    {
        stringstream ss;
        for (int i = 0; i < m1.size() - 1; i +=2 ) {
            int v1 = hexToDec(m1[i], m1[i+1]); // "FF" -> 255
            int v2 = hexToDec(m2[i], m2[i+1]);
            int v3 = hexToDec(m3[i], m3[i+1]);
            ss << char(v1 ^ v2 ^ v3); // 65(=0x41) -> 'A'
        }
        return ss.str();
    }

    private:
    int hexToDec(char c1, char c2)
    {
        return h2d(c1) * 16 + h2d(c2);
    }

    int h2d(char c)
    {
        // std::isdigit from <cctype>, std::isxdigit from <locale>
        return isdigit(c) ? c - '0' : c - 'a' + 10;
    }
};