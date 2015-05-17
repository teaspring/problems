#include "graphSearch.cpp"
#include "gtest/gtest.h"

/*
 * vector<int> BFS01(Point *begin)
 *
 * vector<int> DFS01(Point *begin)
 * */

void assertVector(vector<int> &expected, vector<int> &result){
    EXPECT_EQ(expected.size(), result.size());
    const int n = expected.size();
    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], result[i]);
    }
}

/* ------------ test cases -------------- */
TEST(BFS01_Function, Positive01){
    Solution s;

    Point *pp = new Point(1);

    pp->Left = new Point(2);
    pp->Mid   = new Point(3);
    pp->Right = new Point(4);

    pp->Left->Left   = new Point(5);
    pp->Left->Right  = new Point(6);
    pp->Mid->Left    = new Point(7);
    pp->Mid->Right   = new Point(8);
    pp->Right->Left  = new Point(9);
    pp->Right->Mid   = new Point(10);
    pp->Right->Right = new Point(11);

    pp->Left->Left->Left    = new Point(12);
    pp->Left->Left->Right   = new Point(13);
    pp->Left->Right->Left   = new Point(14);
    pp->Mid->Left->Left     = new Point(15);
    pp->Mid->Left->Right    = new Point(16);
    pp->Mid->Right->Left    = new Point(17);
    pp->Mid->Right->Right   = new Point(18);
    pp->Right->Left->Left   = new Point(19);
    pp->Right->Left->Right  = new Point(20);
    pp->Right->Mid->Left    = new Point(21);
    pp->Right->Mid->Right   = new Point(22);
    pp->Right->Right->Left  = new Point(23);
    pp->Right->Right->Right = new Point(24);

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
    vector<int> expected(arr, arr + sizeof(arr) / sizeof(int));

    vector<int> result = s.BFS01(pp);

    assertVector(expected, result);

    expected.clear();
    result.clear();
}

TEST(DFS01_Function, Positive01){
    Solution s;

    Point *pp = new Point(1);

    pp->Left = new Point(2);
    pp->Mid   = new Point(3);
    pp->Right = new Point(4);

    pp->Left->Left   = new Point(5);
    pp->Left->Right  = new Point(6);
    pp->Mid->Left    = new Point(7);
    pp->Mid->Right   = new Point(8);
    pp->Right->Left  = new Point(9);
    pp->Right->Mid   = new Point(10);
    pp->Right->Right = new Point(11);

    int arr[] = {5, 6, 2, 7, 8, 3, 9, 10, 11, 4, 1};
    vector<int> expected(arr, arr + sizeof(arr) / sizeof(int));

    vector<int> result = s.DFS01(pp);

    assertVector(expected, result);

    expected.clear();
    result.clear();
}
