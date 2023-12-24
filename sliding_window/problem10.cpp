//
//  problem10.cpp
//  DataStructuresAndAlgo
//
//  Created by sai chebrolu on 24/12/23.
//

/*
    PROBLEM: SLIDING WINDOW MAXIMUM
    DESCRIPTION: You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the maximum sliding window
 */

#include<iostream>
#include <stdio.h>
#include <list>
#include <vector>

using namespace std;


vector<int> max_sliding_window( vector<int> &nums, int k) {
    
    list<int> maxNumbers;
    vector<int> result;

    int startIndex = 0;
    int endIndex   = 0;

    while ( endIndex < nums.size() ) {

        while ( !maxNumbers.empty() && maxNumbers.back() < nums[endIndex]) {
            maxNumbers.pop_back();
        }

        maxNumbers.push_back(nums[endIndex]);

        if ( endIndex - startIndex + 1 < k ) {
            endIndex++;
        }
        else {

            result.push_back(maxNumbers.front());

            if ( nums[startIndex] == maxNumbers.front() ) {
                maxNumbers.pop_front();
            }

            startIndex++;
            endIndex++;
        }

    }

    return result;
    
}

int main() {
    
    vector<int> input = {1,3,-1,-3,5,3,6,7};
    int k             = 3;
    
    vector<int> result = max_sliding_window(input,k);
    
    for (auto it: result) {
        cout<<it<< " ";
    }
    
    cout<<endl;
    
    return 0;
    
}
