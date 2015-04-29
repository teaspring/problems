/*
 * vector<vector<string> > Solution::partition(const string&)
 * */

#include "partitionpalindrome.cpp"
#include "gtest/gtest.h"
#include <algorithm>

/* customized methods to falicitate construct and assert */

bool equalsList(vector<string>& list1, vector<string>& list2){
    if(list1.size() != list2.size())    return false;

    const int n = list1.size();
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    for(int i = 0; i < n; i++){
        if(strcmp(list1[i].c_str(), list2[i].c_str()) != 0)
          return false;
    }
    return true;
}

bool containsVector(vector<vector<string> >& duoList, vector<string>& list){
    const int n = duoList.size();
    for(int i = 0; i < n; i++){
        if(equalsList(duoList[i], list))    return true;
    }
    return false;
}

void assertDuoVector(vector<vector<string> >& duoList1, vector<vector<string> >& duoList2){
    EXPECT_EQ(duoList1.size(), duoList2.size());

    const int n = duoList1.size();
    for(int i = 0; i < n; i++){
        EXPECT_TRUE(containsVector(duoList1, duoList2[i]));
        EXPECT_TRUE(containsVector(duoList2, duoList1[i]));
    }
}

/*---------------------- test case ----------------------*/

TEST(partitionpalindromeTest, Positive01){
    Solution s;

    string str("abba");

    string arr1[4] = {"a", "b", "b", "a"};
    string arr2[1] = {"abba"};
    string arr3[3] = {"a", "bb", "a"};

    vector<vector<string> > expected;
    expected.push_back(vector<string>(arr1, arr1 + 4));
    expected.push_back(vector<string>(arr2, arr2 + 1));
    expected.push_back(vector<string>(arr3, arr3 + 3));

    vector<vector<string> > result = s.partition(str);

    assertDuoVector(expected, result);

    expected.clear();
    result.clear();
}

TEST(partitionpalindromeTest, Positive02){
    Solution s;

    string str("abbaa");

    string arr1[] = {"a", "b", "b", "a", "a"};
    string arr2[] = {"abba", "a"};
    string arr3[] = {"a", "bb", "a", "a"};
    string arr4[] = {"a", "bb", "aa"};
    string arr5[] = {"a", "b", "b", "aa"};

    vector<vector<string> > expected;
    expected.push_back(vector<string>(arr1, arr1 + 5));
    expected.push_back(vector<string>(arr2, arr2 + 2));
    expected.push_back(vector<string>(arr3, arr3 + 4));
    expected.push_back(vector<string>(arr4, arr4 + 3));
    expected.push_back(vector<string>(arr5, arr5 + 4));

    vector<vector<string> > result = s.partition(str);

    assertDuoVector(expected, result);

    expected.clear();
    result.clear();
}

TEST(partitionpalindromeTest, Positive03){
    Solution s;

    string str("abbaab");

    string arr1[] = {"a", "b", "b", "a", "a", "b"};
    string arr2[] = {"abba", "a", "b"};
    string arr3[] = {"a", "b", "baab"};
    string arr4[] = {"a", "bb", "a", "a", "b"};
    string arr5[] = {"a", "bb", "aa", "b"};
    string arr6[] = {"a", "b", "b", "aa", "b"};

    vector<vector<string> > expected;
    expected.push_back(vector<string>(arr1, arr1 + 6));
    expected.push_back(vector<string>(arr2, arr2 + 3));
    expected.push_back(vector<string>(arr3, arr3 + 3));
    expected.push_back(vector<string>(arr4, arr4 + 5));
    expected.push_back(vector<string>(arr5, arr5 + 4));
    expected.push_back(vector<string>(arr6, arr6 + 5));

    vector<vector<string> > result = s.partition(str);

    assertDuoVector(expected, result);

    expected.clear();
    result.clear();
}
