/*
 * NQueens(int n)
 * vector<vector<char> > NQueens::solve()
 * int totalNQueens()
 * */

#include "NQueens.cpp"
#include "gtest/gtest.h"
#include <cstring>

/* customized methods to falicitate construct and assert */

bool equalsList(vector<string>& list1, vector<string>& list2){
    if(list1.size() != list2.size())    return false;

    const int n = list1.size();
    for(int i = 0; i < n; i++){
        if(strcmp(list1[i].c_str(), list2[i].c_str()) != 0)
          return false;
    }
    return true;
}

bool containsVector(vector<vector<string> >& duoList,
            vector<string>& list){
    const int n = duoList.size();
    for(int i = 0; i < n; i++){
        if(equalsList(duoList[i], list))    return true;
    }
    return false;
}

bool equalsDuoVector(vector<vector<string> >& duoList1,
            vector<vector<string> >& duoList2){
    if(duoList1.size() != duoList2.size())    return false;

    const int n = duoList1.size();
    for(int i = 0; i < n; i++){
        if(!containsVector(duoList1, duoList2[i]))    return false;
        if(!containsVector(duoList2, duoList1[i]))    return false;
    }
    return true;
}

/*---------------------- test case ----------------------*/
TEST(NQueensTest, Negative01){
    NQueens game(3);

    int expected = 0; // N = 3, impossible to place N queens
    EXPECT_EQ(expected, game.totalNQueens());
}

TEST(NQueensTest, Positive02){
    NQueens game(4);

    string arr[][4] = {
        {"..Q.",
         "Q...",
         "...Q",
         ".Q.."},

        {".Q..",
         "...Q",
         "Q...",
         "..Q."}
    };

    vector<vector<string> > expected;
    for(int i = 0; i < 2; i++){
        expected.push_back(vector<string>(arr[i], arr[i] + 4));
    }

    vector<vector<string> > result = game.solve();
    EXPECT_TRUE(equalsDuoVector(expected, result));
}
