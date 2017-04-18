#include "skyline.cpp"
#include "gtest/gtest.h"

/* vector<pair<int, int>> Solution::getSkyline(vector<vector<int> >& buildings) */

/* facility methods for assert */
bool equalsPair(pair<int, int>& pa1, pair<int, int>& pa2){
    return (pa1.first == pa2.first) && (pa1.second == pa2.second);
}

bool containsPair(vector<pair<int, int> >& vec, pair<int, int>& pa){
    const int N = vec.size();
    for(int i = 0; i < N; i++){
        if(equalsPair(vec[i], pa))    return true;
    }
    return false;
}

bool equalsVectorPairs(vector<pair<int, int> >& list1, vector<pair<int, int> >& list2){
    if(list1.size() != list2.size())    return false;
    const int N = list1.size();
    for(int i = 0; i < N; i++){
        if(!containsPair(list1, list2[i]))    return false;
        if(!containsPair(list2, list1[i]))    return false;
    }
    return true;
}

/*-----------test case-------------*/
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
    equalsVectorPairs(expected, result);
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
    equalsVectorPairs(expected, result);
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
    equalsVectorPairs(expected, result);
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
    equalsVectorPairs(expected, result);
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
    equalsVectorPairs(expected, result);
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
    equalsVectorPairs(expected, result);
}
