//
//  min_subset_sum_diff.cpp
//  DataStructuresAndAlgo
//
//  Created by sai chebrolu on 28/12/23.
//
//  PROBLEM: MIN SUBSET DIFFERENCE
//  DESCRIPTION: Given an input array with positive numbers, return the min difference possible between 2 subsets in the array
//  SOLUTION: Both solutions will give the same results ( memo and top down approach )

#include <iostream>
#include <vector>
using namespace std;


// global
vector<vector<int>> memoArray;

int min_subset_sum_diff_recursion_with_memo_solution( vector<int>& input, int sum, int runningSum, int n) {
    
    if ( n == 0 ) {
        
        return abs( ( sum-runningSum ) - runningSum );
        
    }
    
    if ( memoArray[n][runningSum] != -1 ) {
        return memoArray[n][runningSum];
    }
    
    return memoArray[n][runningSum] = min ( min_subset_sum_diff_recursion_with_memo_solution(input,sum,runningSum+input[n-1],n-1), min_subset_sum_diff_recursion_with_memo_solution(input, sum, runningSum, n-1) );
    
}


int min_subset_sum_diff_top_down_solution( vector<int>& input, int sum) {
    
    bool topDownArray[input.size()+1][sum+1];
    
    for(int i=0; i<input.size()+1; i++) {
        topDownArray[i][0] = true;
    }
    
    for(int j=1; j<sum+1; j++) {
        topDownArray[0][j] = false;
    }
    
    for (int i=1; i<input.size()+1; i++) {
        
        for(int j=1; j<sum+1; j++) {
            
            if ( input[i-1] <= j ) {
                topDownArray[i][j] = topDownArray[i-1][j-input[i-1]] || topDownArray[i-1][j];
            }
            
            else {
                topDownArray[i][j] = topDownArray[i-1][j];
            }
            
        }
        
    }
    
    int subsetOneSum = 0;
    
    for (int j=(sum+1)/2; j>=0; j++) {
        if ( topDownArray[input.size()][j] == true ) {
            subsetOneSum = j;
            break;
        }
    }
    
    return abs( (sum-subsetOneSum) - subsetOneSum);
    
}

int min_subset_sum_diff(vector<int>& input) {
    
    int n          = input.size();
    int runningSum = 0;
    
    for(int i=0; i<n; i++) {
        runningSum += input[i];
    }
    
    
    int result = min_subset_sum_diff_top_down_solution(input, runningSum);
    
    memoArray = vector<vector<int>>(input.size()+1,vector<int>(runningSum+1,-1));
    
    result = min_subset_sum_diff_recursion_with_memo_solution(input, runningSum, 0, n);
    
    return result;
    
}


int main() {
    
    vector<int> input = {1,2,7,3};
    
    int result = min_subset_sum_diff(input);
    
    cout<<endl<<"Min Diff: "<<result<<endl;
    
    return 0;
    
}
