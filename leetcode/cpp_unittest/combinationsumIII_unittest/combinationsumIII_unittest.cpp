/* vector<vector<int> > Solution::combinationSumIII(vector<int> candidates, int target) */

#include "combinationsumIII.cpp"
#include "gtest/gtest.h"

/* customized methods to falicitate construct and assert */

bool contains(vector<int>& list, int x){
    int n = list.size();
    for(int i = 0; i < n; i++){
        if(list[i] == x)    return true;
    }
    return false;
}

bool equalsList(vector<int>& list1, vector<int>& list2){
    if(list1.size() != list2.size())    return false;
    int n = list1.size();
    for(int i = 0; i < n; i++){
        if(list1[i] != list2[i])     return false;
    }
    return true;
}

bool containsVector(vector<vector<int> >& duoList, vector<int>& list){
    int n = duoList.size();
    for(int i = 0; i < n; i++){
        if(equalsList(duoList[i], list))    return true;
    }
    return false;
}

bool equalsDuoVector(vector<vector<int> >& duoList1, vector<vector<int> >& duoList2){
    if(duoList1.size() != duoList2.size())    return false;
    int n = duoList1.size();
    for(int i = 0; i < n; i++){
        if(!containsVector(duoList1, duoList2[i]))    return false;
        if(!containsVector(duoList2, duoList1[i]))    return false;
    }
    return true;
}

/*---------------------- test case ----------------------*/
TEST(combinationsumIII_Test, Positive01){
    Solution s;

    int k = 3, n = 7;

    int option1[] = {1, 2, 4};
    vector<vector<int> > expected;
    expected.push_back(vector<int>(option1, option1 + sizeof(option1) / sizeof(int)));

    vector<vector<int> > result = s.combinationSumIII(k, n);

    EXPECT_TRUE(equalsDuoVector(expected, result));

    expected.clear();
    result.clear();
}

TEST(combinationsumIII_Test, Positive02){
    Solution s;

    int k = 3, n = 9;

    int option1[] = {1, 2, 6};
    int option2[] = {1, 3, 5};
    int option3[] = {2, 3, 4};
    vector<vector<int> > expected;
    expected.push_back(vector<int>(option1, option1 + sizeof(option1) / sizeof(int)));
    expected.push_back(vector<int>(option2, option2 + sizeof(option2) / sizeof(int)));
    expected.push_back(vector<int>(option3, option3 + sizeof(option3) / sizeof(int)));

    vector<vector<int> > result = s.combinationSumIII(k, n);

    EXPECT_TRUE(equalsDuoVector(expected, result));

    expected.clear();
    result.clear();
}

TEST(combinationsumIII_Test, Positive03){
    Solution s;

    int k = 4, n = 12;

    int option1[] = {1, 2, 3, 6};
    int option2[] = {1, 2, 4, 5};
    vector<vector<int> > expected;
    expected.push_back(vector<int>(option1, option1 + sizeof(option1) / sizeof(int)));
    expected.push_back(vector<int>(option2, option2 + sizeof(option2) / sizeof(int)));

    vector<vector<int> > result = s.combinationSumIII(k, n);

    EXPECT_TRUE(equalsDuoVector(expected, result));

    expected.clear();
    result.clear();
}
