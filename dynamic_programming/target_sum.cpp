//
//  target_sum.cpp
//  DataStructuresAndAlgo
//
//  Created by sai chebrolu on 28/12/23.
//
//  PROBLEM: TARGET SUM
//  DESCRIPTION: Given an input array with postive numbers and a target sum, you will be able to assign +ve or -ve sign to each number. Return how many ways the target sum can be reached.
//  SOLUTION: Both solutions will give the same results ( memo and top down approach )

#include <iostream>
#include <vector>
using namespace std;


// global
vector<vector<int>> memoArray;

int target_sum_recursion_with_memo_solution(vector<int>& input, int sum,  int n) {
    
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
        return memoArray[n][sum] = target_sum_recursion_with_memo_solution(input, sum - input[n-1], n-1) + target_sum_recursion_with_memo_solution(input, sum, n-1);
    }
    
    return memoArray[n][sum] = target_sum_recursion_with_memo_solution(input, sum, n-1);
    
}

int target_sum_top_down_solution( vector<int>& input, int sum) {
    
    int topDownArray[input.size()+1][sum+1];
    
    for (int i=0; i<input.size()+1; i++) {
        topDownArray[i][0] = 1;
    }
    
    for (int j=1; j<sum+1; j++) {
        topDownArray[0][j] = 0;
    }
    
    for (int i=1; i<input.size()+1; i++) {
        
        for (int j=1; j<sum+1; j++) {
            
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


int target_sum( vector<int> input, int targetSum ) {
    
    int result = 0;
    
    int totalSum = 0;
    
    for (int i=0; i<input.size(); i++) {
        totalSum += input[i];
    }
    
    // s1 - s2 = target
    // s1 + s2 = totalSum
    // s1 = (target+totalsum)/2
    
    if ( (targetSum + totalSum) & 1 ) {
        return 0;
    }
    
    int sum = (targetSum + totalSum)/2;
    
    memoArray = vector<vector<int>>(input.size()+1, vector<int>(sum+1,-1));
    
    result = target_sum_recursion_with_memo_solution(input, sum, input.size());
    
    result = target_sum_top_down_solution(input, sum);
    
    return result;
    
}


int main() {
    
    vector<int> input = {1,1,2,3};
    int targetSum     = 5;
    
    int result = target_sum(input,targetSum);
    
    cout<<endl<<"Result: "<<result<<endl;
    
    return 0;
    
}

