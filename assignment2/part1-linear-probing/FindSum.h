#ifndef PAIRFINDER_H
#define PAIRFINDER_H

#include <vector>
#include <iostream>
#include "HashingLinearProbingDemo.h"

using namespace std;


class PairFinder {

public:

    //Finds a pair of numbers in an given array "nums" that equal to targetSum
    void findPair(const vector<int>& nums, int targetSum) {

        int initialSize = nums.size(); //Initialize hash table size

        HashingLinearProbingDemo hashTable(initialSize, 0.75); //Create hashtable with given initialSize and threshold 0.75

        for (int num : nums) {//Loop through vector

            int difference = targetSum - num; //Difference to reach targetSum

            if (difference != 0 && hashTable.Search(difference)) { //If difference is not zero and is found
                cout << "Pair found (" << difference << ", " << num << ")" << endl; //Print the pair
                return;
            }

            //Zero numbers rejected
            if (num != 0) { 
                hashTable.Insert(num);
            }
        }

        cout << "No pairs found" << endl;
    }
};

#endif
