//
//  problem8.cpp
//  DataStructuresAndAlgo
//
//  Created by sai chebrolu on 23/12/23.
//
/*
    PROBLEM: FIRST NEGATIVE NUMBER IN EVERY SUBARRAY OF SIZE K
    DESCRIPTION: Given an input array and k, return the first negative number in each subarray of size k
 */

#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

vector<int> first_negative_number_k_size_subarray( vector<int>& input, int k) {
    
    vector<int> result;
    queue<int> negativeNumbers;
    
    int startIndex = 0;
    int endIndex   = 0;
    
    while ( endIndex < input.size() ) {
        
        if ( input[endIndex] < 0 ) {
            negativeNumbers.push(input[endIndex]);
        }
        
        if ( (endIndex-startIndex+1) < k ) {
            endIndex++;
        }
        else {
            
            if ( !negativeNumbers.empty() ) {
                result.push_back(negativeNumbers.front());
            }
            
            if ( !negativeNumbers.empty() && negativeNumbers.front() == input[startIndex] ) {
                negativeNumbers.pop();
            }
            
            startIndex++;
            endIndex++;
            
        }
        
    }
    
    return result;
    
}



int main() {
    
    vector<int> input = {-1,2,-3,-1,8,-9,-2,0,2,-4};
    int k             = 3;
    
    vector<int> result = first_negative_number_k_size_subarray(input, k);
    
    for ( auto it: result ) {
        cout<<it<<" ";
    }
    cout<<endl;
    
    return 0;
    
}
