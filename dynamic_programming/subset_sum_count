//
//  subset_sum_count.cpp
//  DataStructuresAndAlgo
//
//  Created by sai chebrolu on 28/12/23.
//
//  PROBLEM: SUBSET SUM COUNT
//  DESCRIPTION: Given an input array with positive numbers and a target sum, return the count of such subsets which match the target sum
//  SOLUTION: Both solutions will give the same results ( memo and top down approach )

#include <iostream>
#include <vector>
using namespace std;


// globals
vector<vector<int>> memoArray;

int recursive_with_memo_solution( vector<int>& input, int sum, int n) {
    
    if ( sum == 0 ) {
        return memoArray[n][sum] = 1;
    }
    
    if ( n == 0 ) {
        return memoArray[n][sum] = 0;
    }
    
    if ( memoArray[n][sum] != -1 ) {
        return memoArray[n][sum];
    }
    
    if ( input[n-1] <= sum ) {
        return memoArray[n][sum] = recursive_with_memo_solution(input, sum - input[n-1], n-1) + recursive_with_memo_solution(input, sum, n-1);
    }
    
    return memoArray[n][sum] = recursive_with_memo_solution(input, sum, n-1);
    
}

int subset_sum_count_top_down_solution( vector<int>& input, int sum) {
    
    int topDownArray[input.size()+1][sum+1];
    
    for(int i=0; i<input.size()+1; i++) {
        topDownArray[i][0] = 1;
    }
    
    for(int j=1; j<sum+1; j++) {
        topDownArray[0][j] = 0;
    }
    
    for (int i=1; i<input.size()+1; i++) {
        
        for(int j=1; j<sum+1; j++) {
            
            if ( input[i-1] <= j ) {
                topDownArray[i][j] = topDownArray[i-1][j-input[i-1]] + topDownArray[i-1][j];
            }
            
            else {
                topDownArray[i][j] = topDownArray[i-1][j];
            }
            
        }
        
    }
    
    return topDownArray[input.size()][sum];
    
}


int subset_sum_count( vector<int> input, int sum) {
    
    int result = 0;
    
    memoArray = vector<vector<int>>(input.size() + 1, vector<int>(sum + 1, -1));
    result = recursive_with_memo_solution(input, sum, input.size());
    
    
    result = subset_sum_count_top_down_solution(input, sum);
    
    return result;
}


int main() {
    
    vector<int> input = {1,4,2,5,1};
    int sum           = 6;
    
    int result = subset_sum_count(input,sum);
    
    cout<<endl<<"Result: "<<result<<endl;
    
    return 0;
}
