/* vector<vector<int> > Solution::combinations(int n, int k) */

#include "combinations.cpp"
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
TEST(combinationsTest, Positive01){
    Solution s;

    int n = 3, k = 2;
    int arr[][2] = {{1, 2},
                    {1, 3},
                    {2, 3}};

    vector<vector<int> > expected;
    for(int i = 0; i < 3; i++){
        expected.push_back(vector<int>(arr[i], arr[i] + sizeof(arr[i])/sizeof(int)));
    }

    vector<vector<int> > result = s.combinations(n, k);
    EXPECT_TRUE(equalsDuoVector(expected, result));
}

TEST(combinationsTest, Positive02){
    Solution s;

    int n = 5, k = 3;
    int arr[][3] = {{1, 2, 3},
                    {1, 2, 4},
                    {1, 2, 5},
                    {1, 3, 4},
                    {1, 3, 5},
                    {1, 4, 5},
                    {2, 3, 4},
                    {2, 3, 5},
                    {2, 4, 5},
                    {3, 4, 5}};

    vector<vector<int> > expected;
    for(int i = 0; i < 10; i++){
        expected.push_back(vector<int>(arr[i], arr[i] + sizeof(arr[i])/sizeof(int)));
    }

    vector<vector<int> > result = s.combinations(n, k);
    EXPECT_TRUE(equalsDuoVector(expected, result));
}
