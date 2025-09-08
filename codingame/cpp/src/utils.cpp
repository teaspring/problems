#include "utils.h"

using namespace std;

string trim_str(const string& s)
{
    const string space_chars(" \t\n\r");
    auto start = s.find_first_not_of(space_chars);
    if (start == string::npos) return "";
    auto end = s.find_last_not_of(space_chars);
    return s.substr(start, end - start + 1);
}