#include <string>
#include <cstring>
#include <cctype>
#include <map>

using namespace std;

class Solution
{
    public:
    void decrypt_by_freq(const string& src, string& decrypted)
    {
        int delta = analyze_shift(src);
        char* res = new char[src.length() + 1];
        res[src.length()] = '\0';
        for (auto it = src.cbegin(); it < src.cend(); it++)
        {
            // decryption is to shift backward, use -delta 
            res[it - src.cbegin()] = shift_char(*it, -delta, islower(*it));
        }
        decrypted = string(res);
    }

    private:
    map<char, float> engLetterFreq = {
        {'A', 8.08},
        {'B', 1.67},
        {'C', 3.18},
        {'D', 3.99},
        {'E', 12.56},
        {'F', 2.17},
        {'G', 1.80},
        {'H', 5.27},
        {'I', 7.24},
        {'J', 0.14},
        {'K', 0.63},
        {'L', 4.04}, 
        {'M', 2.60},
        {'N', 7.38},
        {'O', 7.47},
        {'P', 1.91},
        {'Q', 0.09},
        {'R', 6.42},
        {'S', 6.59},
        {'T', 9.15},
        {'U', 2.79},
        {'V', 1.00},
        {'W', 1.89},
        {'X', 0.21},
        {'Y', 1.65},
        {'Z', 0.07}
    };

    float get_letter_freq_weight(const char& ch)
    {
        if (!isalpha(ch))   return 0.0f;
        return engLetterFreq[toupper((unsigned char)ch)];
    }

    char shift_char(const char& ch, const int& n, bool is_lower)
    {
        if (!isalpha(ch))    return ch; // non-alpha is not involved
        int d = n;
        while (d < 0)
        {
            d += 26;
        }
        char res = 'A' + (toupper((unsigned char) ch) - 'A' + d) % 26; // upper by default
        return is_lower ? tolower(res) : res;
    }

    int analyze_shift(const string& src)
    {
        double max_score = 0.0f;
        int delta = -1;
        for (auto i = 0; i < 26; i++)
        {
            double score = 0.0f;
            for (auto it = src.cbegin(); it < src.cend(); it++)
            {
                // decryption is to shift backward, use -i as shift
                score += get_letter_freq_weight(shift_char(*it, -i, false));
            }
            if (score > max_score)
            {
                max_score = score;
                delta = i;
            }
        }
        return delta;
    }
};
