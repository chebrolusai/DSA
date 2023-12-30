//
//  equal_sum_partition.cpp
//  DataStructuresAndAlgo
//
//  Created by sai chebrolu on 28/12/23.
//
//  PROBLEM: EQUAL SUM PARTITION
//  DESCRIPTION: Given an input array with positive, return if the array can be split into 2 equal sums
//  SOLUTION: Both solutions will give the same results ( memo and top down approach )


#include <iostream>
#include <vector>
using namespace std;



// globals
vector<vector<int>> memoArray;

bool equal_sum_partition_recursive_with_memo_solution( vector<int>& input, int sum, int n) {
    
    if ( sum == 0 ) {
        return memoArray[n][sum] = true;
    }
    
    if ( n == 0 ) {
        return memoArray[n][sum] = false;
    }
    
    if ( memoArray[n][sum] != -1 ) {
        return memoArray[n][sum];
    }
    
    if ( input[n-1] <= sum ) {
        return memoArray[n][sum] = equal_sum_partition_recursive_with_memo_solution(input, sum - input[n-1], n-1) || equal_sum_partition_recursive_with_memo_solution(input, sum, n-1);
    }
    
    return memoArray[n][sum] = equal_sum_partition_recursive_with_memo_solution(input, sum, n-1);
    
}

int equal_sum_partition_top_down_solution( vector<int>& input, int sum) {
    
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
    
    return topDownArray[input.size()][sum];
    
}

bool equal_sum_partition(vector<int>& input) {
    
    int n          = input.size();
    int runningSum = 0;
    
    for(int i=0; i<n; i++) {
        runningSum += input[i];
    }
    
    if ( runningSum & 1 ) {
        return false;
    }
    
    bool result;
    
    memoArray = vector<vector<int>>(input.size() + 1, vector<int>(runningSum/2 + 1, -1));
    result    = equal_sum_partition_recursive_with_memo_solution(input, runningSum/2, n);
    
    result = equal_sum_partition_top_down_solution(input, runningSum/2);
    
    return result;
    
}


int main() {
    
    vector<int> input = {3,4,2,2,5,2};
    
    bool result = equal_sum_partition(input);
    
    cout<<endl<<"Possible? "<<result<<endl;
    
    return 0;
    
}
