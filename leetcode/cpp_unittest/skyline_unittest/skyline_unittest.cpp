#include "skyline.cpp"
#include "gtest/gtest.h"

/* vector<pair<int, int>> Solution::getSkyline(vector<vector<int> >& buildings) */

/* facility methods for assert */
bool equalsPair(pair<int, int>& pa1, pair<int, int>& pa2){
    return (pa1.first == pa2.first) && (pa1.second == pa2.second);
}

bool equalsVectorPairs(vector<pair<int, int> >& list1, vector<pair<int, int> >& list2){
    if(list1.size() != list2.size())    return false;

    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    const int N = list1.size();
    for(int i = 0; i < N; i++){
        if(!equalsPair(list1[i], list2[i]))    return false;
    }
    return true;
}

/*-----------test case-------------*/
TEST(skylineOneBuilding_Test, Edge01){
    Solution s;

    vector<vector<int>> buildings;

    int arr1[] = {1, 4, 1};
    buildings.push_back(vector<int>(arr1, arr1 + sizeof(arr1)/sizeof(int)));

    vector<pair<int, int>> expected;
    expected.push_back(pair<int, int>(1, 1));
    expected.push_back(pair<int, int>(4, 0));

    vector<pair<int, int>> result = s.getSkyline(buildings);
    EXPECT_TRUE(equalsVectorPairs(expected, result));
}

TEST(skylineTwoBuildings_Test, Positive01){
    Solution s;

    vector<vector<int>> buildings;

    int arr1[] = {1, 4, 1};
    buildings.push_back(vector<int>(arr1, arr1 + sizeof(arr1)/sizeof(int)));

    int arr2[] = {2, 3, 2};
    buildings.push_back(vector<int>(arr2, arr2 + sizeof(arr2)/sizeof(int)));

    vector<pair<int, int>> expected;
    expected.push_back(pair<int, int>(1, 1));
    expected.push_back(pair<int, int>(2, 2));
    expected.push_back(pair<int, int>(3, 1));
    expected.push_back(pair<int, int>(4, 0));

    vector<pair<int, int>> result = s.getSkyline(buildings);
    EXPECT_TRUE(equalsVectorPairs(expected, result));
}

TEST(skylineTwoBuildings_Test, Positive02){
    Solution s;

    vector<vector<int>> buildings;

    int arr1[] = {1, 3, 1};
    buildings.push_back(vector<int>(arr1, arr1 + sizeof(arr1)/sizeof(int)));

    int arr2[] = {2, 4, 2};
    buildings.push_back(vector<int>(arr2, arr2 + sizeof(arr2)/sizeof(int)));

    vector<pair<int, int>> expected;
    expected.push_back(pair<int, int>(1, 1));
    expected.push_back(pair<int, int>(2, 2));
    expected.push_back(pair<int, int>(4, 0));

    vector<pair<int, int>> result = s.getSkyline(buildings);
    EXPECT_TRUE(equalsVectorPairs(expected, result));
}

TEST(skylineTwoBuildings_Test, Positive03){
    Solution s;

    vector<vector<int>> buildings;

    int arr1[] = {1, 4, 2};
    buildings.push_back(vector<int>(arr1, arr1 + sizeof(arr1)/sizeof(int)));

    int arr2[] = {2, 3, 1};
    buildings.push_back(vector<int>(arr2, arr2 + sizeof(arr2)/sizeof(int)));

    vector<pair<int, int>> expected;
    expected.push_back(pair<int, int>(1, 2));
    expected.push_back(pair<int, int>(4, 0));

    vector<pair<int, int>> result = s.getSkyline(buildings);
    EXPECT_TRUE(equalsVectorPairs(expected, result));
}

TEST(skylineTwoBuildings_Test, Positive04){
    Solution s;

    vector<vector<int>> buildings;

    int arr1[] = {1, 3, 2};
    buildings.push_back(vector<int>(arr1, arr1 + sizeof(arr1)/sizeof(int)));

    int arr2[] = {2, 4, 1};
    buildings.push_back(vector<int>(arr2, arr2 + sizeof(arr2)/sizeof(int)));

    vector<pair<int, int>> expected;
    expected.push_back(pair<int, int>(1, 2));
    expected.push_back(pair<int, int>(3, 1));
    expected.push_back(pair<int, int>(4, 0));

    vector<pair<int, int>> result = s.getSkyline(buildings);
    EXPECT_TRUE(equalsVectorPairs(expected, result));
}

TEST(skylineTwoBuildings_Test, Positive05){
    Solution s;

    vector<vector<int>> buildings;

    int arr1[] = {1, 3, 1};
    buildings.push_back(vector<int>(arr1, arr1 + sizeof(arr1)/sizeof(int)));

    int arr2[] = {2, 4, 1};
    buildings.push_back(vector<int>(arr2, arr2 + sizeof(arr2)/sizeof(int)));

    vector<pair<int, int>> expected;
    expected.push_back(pair<int, int>(1, 1));
    expected.push_back(pair<int, int>(4, 0));

    vector<pair<int, int>> result = s.getSkyline(buildings);
    EXPECT_TRUE(equalsVectorPairs(expected, result));
}

TEST(skylineTwoBuildings_Test, Positive06){
    Solution s;

    vector<vector<int>> buildings;

    int arr1[] = {1, 2, 1};
    buildings.push_back(vector<int>(arr1, arr1 + sizeof(arr1)/sizeof(int)));

    int arr2[] = {1, 3, 2};
    buildings.push_back(vector<int>(arr2, arr2 + sizeof(arr2)/sizeof(int)));

    vector<pair<int, int>> expected;
    expected.push_back(pair<int, int>(1, 2));
    expected.push_back(pair<int, int>(3, 0));

    vector<pair<int, int>> result = s.getSkyline(buildings);
    EXPECT_TRUE(equalsVectorPairs(expected, result));
}

/*---------- multiple buildings case -------------*/
TEST(skylineMultiBuildings_Test, Positive01){
    Solution s;

    vector<vector<int>> buildings;

    int arr1[] = {1, 3, 2};
    buildings.push_back(vector<int>(arr1, arr1 + sizeof(arr1)/sizeof(int)));

    int arr2[] = {2, 6, 1};
    buildings.push_back(vector<int>(arr2, arr2 + sizeof(arr2)/sizeof(int)));

    int arr3[] = {2, 5, 3};
    buildings.push_back(vector<int>(arr3, arr3 + sizeof(arr3)/sizeof(int)));

    vector<pair<int, int>> expected;
    expected.push_back(pair<int, int>(1, 2));
    expected.push_back(pair<int, int>(2, 3));
    expected.push_back(pair<int, int>(5, 1));
    expected.push_back(pair<int, int>(6, 0));

    vector<pair<int, int>> result = s.getSkyline(buildings);
    EXPECT_TRUE(equalsVectorPairs(expected, result));
}

TEST(skylineMultiBuildings_Test, Positive02){
    Solution s;

    vector<vector<int>> buildings;

    int arr1[] = {1, 4, 2};
    buildings.push_back(vector<int>(arr1, arr1 + sizeof(arr1)/sizeof(int)));

    int arr2[] = {2, 4, 3};
    buildings.push_back(vector<int>(arr2, arr2 + sizeof(arr2)/sizeof(int)));

    int arr3[] = {3, 5, 4};
    buildings.push_back(vector<int>(arr3, arr3 + sizeof(arr3)/sizeof(int)));

    int arr4[] = {3, 6, 1};
    buildings.push_back(vector<int>(arr4, arr4 + sizeof(arr4)/sizeof(int)));

    vector<pair<int, int>> expected;
    expected.push_back(pair<int, int>(1, 2));
    expected.push_back(pair<int, int>(2, 3));
    expected.push_back(pair<int, int>(3, 4));
    expected.push_back(pair<int, int>(5, 1));
    expected.push_back(pair<int, int>(6, 0));

    vector<pair<int, int>> result = s.getSkyline(buildings);
    EXPECT_TRUE(equalsVectorPairs(expected, result));
}

TEST(skylineMultiBuildings_Test, Positive03){
    Solution s;

    vector<vector<int>> buildings;

    int arr1[] = {1, 3, 3};
    buildings.push_back(vector<int>(arr1, arr1 + sizeof(arr1)/sizeof(int)));

    int arr2[] = {2, 4, 2};
    buildings.push_back(vector<int>(arr2, arr2 + sizeof(arr2)/sizeof(int)));

    int arr3[] = {2, 5, 1};
    buildings.push_back(vector<int>(arr3, arr3 + sizeof(arr3)/sizeof(int)));

    vector<pair<int, int>> expected;
    expected.push_back(pair<int, int>(1, 3));
    expected.push_back(pair<int, int>(3, 2));
    expected.push_back(pair<int, int>(4, 1));
    expected.push_back(pair<int, int>(5, 0));

    vector<pair<int, int>> result = s.getSkyline(buildings);
    EXPECT_TRUE(equalsVectorPairs(expected, result));
}

TEST(skylineMultiBuildings_Test, Positive04){
    Solution s;

    vector<vector<int>> buildings;

    int arr1[] = {1, 5, 2};
    buildings.push_back(vector<int>(arr1, arr1 + sizeof(arr1)/sizeof(int)));

    int arr2[] = {2, 4, 4};
    buildings.push_back(vector<int>(arr2, arr2 + sizeof(arr2)/sizeof(int)));

    int arr3[] = {3, 6, 3};
    buildings.push_back(vector<int>(arr3, arr3 + sizeof(arr3)/sizeof(int)));

    int arr4[] = {8, 10, 2};
    buildings.push_back(vector<int>(arr4, arr4 + sizeof(arr4)/sizeof(int)));

    int arr5[] = {9, 11, 1};
    buildings.push_back(vector<int>(arr5, arr5 + sizeof(arr5)/sizeof(int)));

    vector<pair<int, int>> expected;
    expected.push_back(pair<int, int>(1, 2));
    expected.push_back(pair<int, int>(2, 4));
    expected.push_back(pair<int, int>(4, 3));
    expected.push_back(pair<int, int>(6, 0));
    expected.push_back(pair<int, int>(8, 2));
    expected.push_back(pair<int, int>(10, 1));
    expected.push_back(pair<int, int>(11, 0));

    vector<pair<int, int>> result = s.getSkyline(buildings);

    EXPECT_TRUE(equalsVectorPairs(expected, result));
}

TEST(skylineMultiBuildings_Test, Positive05){
    Solution s;

    vector<vector<int>> buildings;

    int arr1[] = {3, 7, 8};
    buildings.push_back(vector<int>(arr1, arr1 + sizeof(arr1)/sizeof(int)));

    int arr2[] = {3, 8, 7};
    buildings.push_back(vector<int>(arr2, arr2 + sizeof(arr2)/sizeof(int)));

    int arr3[] = {3, 9, 6};
    buildings.push_back(vector<int>(arr3, arr3 + sizeof(arr3)/sizeof(int)));

    int arr4[] = {3, 10, 5};
    buildings.push_back(vector<int>(arr4, arr4 + sizeof(arr4)/sizeof(int)));

    int arr5[] = {3, 11, 4};
    buildings.push_back(vector<int>(arr5, arr5 + sizeof(arr5)/sizeof(int)));

    int arr6[] = {3, 12, 3};
    buildings.push_back(vector<int>(arr6, arr6 + sizeof(arr6)/sizeof(int)));

    int arr7[] = {3, 13, 2};
    buildings.push_back(vector<int>(arr7, arr7 + sizeof(arr7)/sizeof(int)));

    int arr8[] = {3, 14, 1};
    buildings.push_back(vector<int>(arr8, arr8 + sizeof(arr8)/sizeof(int)));

    vector<pair<int, int>> expected;
    expected.push_back(pair<int, int>(3, 8));
    expected.push_back(pair<int, int>(7, 7));
    expected.push_back(pair<int, int>(8, 6));
    expected.push_back(pair<int, int>(9, 5));
    expected.push_back(pair<int, int>(10, 4));
    expected.push_back(pair<int, int>(11, 3));
    expected.push_back(pair<int, int>(12, 2));
    expected.push_back(pair<int, int>(13, 1));
    expected.push_back(pair<int, int>(14, 0));

    /*
    cout << "expected: ";
    for(int i = 0; i < (int)expected.size(); ++i) {
        cout << '[' << expected[i].first << ',' << expected[i].second << "], ";
    }
    cout << endl;
    */

    vector<pair<int, int>> result = s.getSkyline(buildings);

    /*
    cout << "result: ";
    for(int i = 0; i < (int)result.size(); ++i) {
        cout << '[' << result[i].first << ',' << result[i].second << "], ";
    }
    cout << endl;
    */

    EXPECT_TRUE(equalsVectorPairs(expected, result));
}

TEST(skylineMultiBuildings_Test, Edge01){
    Solution s;

    vector<vector<int>> buildings;

    int arr1[] = {2, 4, 7};
    buildings.push_back(vector<int>(arr1, arr1 + sizeof(arr1)/sizeof(int)));

    int arr2[] = {2, 4, 5};
    buildings.push_back(vector<int>(arr2, arr2 + sizeof(arr2)/sizeof(int)));

    int arr3[] = {2, 4, 6};
    buildings.push_back(vector<int>(arr3, arr3 + sizeof(arr3)/sizeof(int)));

    vector<pair<int, int>> expected;
    expected.push_back(pair<int, int>(2, 7));
    expected.push_back(pair<int, int>(4, 0));

    vector<pair<int, int>> result = s.getSkyline(buildings);

    EXPECT_TRUE(equalsVectorPairs(expected, result));
}
