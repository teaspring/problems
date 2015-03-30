/* vector<vector<int> > Solution::combinationSum(vector<int> candidates, int target) */

#include "combinationsum.cpp"
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
TEST(combinationsumTest, Positive01){
    Solution s;

    int target = 7;
    int arr[] = {2, 3, 7};
    vector<int> candidates(arr, arr + sizeof(arr) / sizeof(int));

    int option1[] = {2, 2, 3};
    int option2[] = {7};
    vector<vector<int> > expected;
    expected.push_back(vector<int>(option1, option1 + sizeof(option1) / sizeof(int)));
    expected.push_back(vector<int>(option2, option2 + sizeof(option2) / sizeof(int)));

    vector<vector<int> > result = s.combinationSum(candidates, target);

    EXPECT_TRUE(equalsDuoVector(expected, result));
}
