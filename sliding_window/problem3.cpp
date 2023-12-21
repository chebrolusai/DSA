//
//  problem3.cpp
//  DataStructuresAndAlgo
//
//  Created by sai chebrolu on 20/12/23.
//

/*
    PROBLEM: CHECK DUPLICATES
    DESCRIPTION: Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
 */

#include <iostream>
#include <stdio.h>
#include <unordered_set>
#include <vector>
using namespace std;


bool contains_nearby_duplicate(vector<int>& nums, int k) {
    
    int startIndex = 0;
    int endIndex   = 0;

    unordered_set<int> windowNumbers;

    while ( endIndex < nums.size()) {

        windowNumbers.insert(nums[endIndex]);

        if ( endIndex - startIndex < k ) {

            if (windowNumbers.size() < (endIndex-startIndex+1) ) {
                return true;
            }
            
            endIndex++;
        }

        else {

            if (windowNumbers.size() < (endIndex-startIndex+1) ) {
                return true;
            }

            windowNumbers.erase(nums[startIndex]);
            startIndex++;
            endIndex++;

        }

    }

    return false;

}

int main() {
    
    vector<int> v = {1,2,3,1,2,3};
    int k         = 2;
    
    bool result = contains_nearby_duplicate(v,k);
    
    cout<<endl<<"Result: "<<result<<endl;
    
    return 0;   

}
