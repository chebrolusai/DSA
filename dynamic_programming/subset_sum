//
//  subset_sum.cpp
//  DataStructuresAndAlgo
//
//  Created by sai chebrolu on 28/12/23.
//
//  PROBLEM: SUBSET SUM
//  DESCRIPTION: Given an input array with positive numbers and a target sum, return if the sum exists or not.
//  SOLUTION: Both solutions will give the same results ( memo and top down approach )

#include <iostream>
#include <vector>
using namespace std;



// globals
vector<vector<int>> memoArray;

bool subset_sum_recursive_with_memo_solution( vector<int>& input, int sum, int n) {
    
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
        return memoArray[n][sum] = subset_sum_recursive_with_memo_solution(input, sum - input[n-1], n-1) || subset_sum_recursive_with_memo_solution(input, sum, n-1);
    }
    
    return memoArray[n][sum] = subset_sum_recursive_with_memo_solution(input, sum, n-1);
    
}

int subset_sum_top_down_solution( vector<int>& input, int sum) {
    
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


bool subset_sum( vector<int> input, int sum) {
    
    bool result;
    
    memoArray = vector<vector<int>>(input.size() + 1, vector<int>(sum + 1, -1));
    result = subset_sum_recursive_with_memo_solution(input, sum, input.size());
    
    result = subset_sum_top_down_solution(input, sum);
    
    return result;
}


int main() {
    
    vector<int> input = {1,4,2,5,4,3,6};
    int sum           = 12;
    
    bool result = subset_sum(input,sum);
    
    cout<<endl<<"Present? "<<result<<endl;
    
    return 0;
    
}
