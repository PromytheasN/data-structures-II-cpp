#include <iostream>
#include <vector>
#include "FindSum.h"

using namespace std;

int main() {
    PairFinder pairFinder;

    //Test case 1
    vector<int> nums1 = {8, 7, 2, 5, 3, 1};
    int targetSum1 = 10;
    cout << "Test case 1: nums = {8, 7, 2, 5, 3, 1}, targetSum = 10" << endl;
    pairFinder.findPair(nums1, targetSum1);
    cout << endl;

    //Test case 2
    vector<int> nums2 = {5, 2, 6, 8, 1, 9};
    int targetSum2 = 12;
    cout << "Test case 2: nums = {5, 2, 6, 8, 1, 9}, targetSum = 12" << endl;
    pairFinder.findPair(nums2, targetSum2);
    cout << endl;

    //Test case 3: "No pairs found"
    vector<int> nums3 = {1, 2, 3, 4, 5};
    int targetSum3 = 10;
    cout << "Test case 3: nums = {1, 2, 3, 4, 5}, targetSum = 10" << endl;
    pairFinder.findPair(nums3, targetSum3);
    cout << endl;

    //Test case 4: Pairs with a zero
    vector<int> nums4 = {0, 1, 3, 8, 5, 7};
    int targetSum4 = 7;
    cout << "Test case 4: nums = {0, 1, 3, 8, 5, 7}, targetSum = 7" << endl;
    pairFinder.findPair(nums4, targetSum4);
    cout << endl;

    //Test case 5: All zeros
    vector<int> nums5 = {0, 0, 0, 0, 0};
    int targetSum5 = 5;
    cout << "Test case 5: nums = {0, 0, 0, 0, 0}, targetSum = 5" << endl;
    pairFinder.findPair(nums5, targetSum5);
    cout << endl;

    return 0;
}
