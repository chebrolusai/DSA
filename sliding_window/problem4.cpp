//
//  problem3.cpp
//  DataStructuresAndAlgo
//
//  Created by sai chebrolu on 20/12/23.
//

/*
    PROBLEM: MAXIMUM AVERAGE SUBARRAY
    DESCRIPTION: Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value.
 */

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;


double find_max_average(vector<int>& nums, int k) {
    
    int startIndex    = 0;
    int endIndex      = 0;
    double runningSum = 0;
    double average    = INT_MIN;
    double result     = INT_MIN;

    while( endIndex < nums.size() ) {

        runningSum = runningSum + nums[endIndex];

        if ( endIndex - startIndex + 1 < k ) {

            endIndex++;

        }

        else {

           average = runningSum/k;

           if ( average > result ) {
               result = average;
           }

           runningSum = runningSum - nums[startIndex];
           startIndex++;
           endIndex++;

        }

    }

    return result;

}

int main() {
    
    vector<int> v = {1,12,-5,-6,50,3};
    int k         = 4;
    
    double result = find_max_average(v,k);
    
    cout<<endl<<"Result: "<<result<<endl;

    return 0;
    
}
