//
//  dp1.cpp
//  DataStructuresAndAlgo
//
//  Created by sai chebrolu on 27/12/23.
//
//  PROBLEM: 0/1 KNAPSACK
//  DESCRIPTION: Given N items where each item has some weight and value associated with it and also given a bag with capacity bagWeight, [i.e., the bag can hold at most bagWeight weight in it]. The task is to put the items into the bag such that the sum of profits associated with them is the maximum possible.
//  3 solutions below.

#include <iostream>
#include <vector>
using namespace std;


//globals
vector<vector<int>> memoArray;

int recursive_solution(vector<int> weight, vector<int> value, int bagWeight, int n) {
    
    if ( bagWeight == 0 || n == 0 ) {
        return 0;
    }
    
    if ( weight[n-1] <= bagWeight ) {
        
        return max( value[n-1] + recursive_solution(weight, value, bagWeight - weight[n-1], n-1), recursive_solution(weight, value, bagWeight, n-1) );
        
    }
        
    return recursive_solution(weight, value, bagWeight, n-1);
    
}

int recursive_with_memo_solution(vector<int> weight, vector<int> value, int bagWeight, int n) {
    
    if ( bagWeight == 0 || n == 0 ) {
        return 0;
    }
    
    if ( memoArray[bagWeight][n] != -1 ) {
        return memoArray[bagWeight][n];
    }
    
    if ( weight[n-1] <= bagWeight ) {
        
        return memoArray[bagWeight][n] = max( value[n-1] + recursive_with_memo_solution(weight, value, bagWeight - weight[n-1], n-1), recursive_with_memo_solution(weight, value, bagWeight, n-1) );
        
    }
        
    return memoArray[bagWeight][n] = recursive_with_memo_solution(weight, value, bagWeight, n-1);
    
}

int top_down_solution( vector<int> weight, vector<int> value, int bagWeight ) {
    
    int topDownArray[weight.size()+1][bagWeight+1];
    
    for (int i=0; i<weight.size()+1; i++) {
        
        topDownArray[i][0] = 0;
    
    }
    for (int j=0; j<bagWeight+1; j++) {
        
        topDownArray[0][j] = 0;
    
    }
    
    for (int i=1; i<weight.size()+1; i++) {
        
        for (int j=1; j<bagWeight+1; j++) {
            
            if ( weight[i-1] <= j ) {
                topDownArray[i][j] = max( value[i-1] + topDownArray[i-1][j-weight[i-1]] , topDownArray[i-1][j]);
            }
            else {
                topDownArray[i][j] = topDownArray[i-1][j];
            }
            
        }
        
    }
    
    
    return topDownArray[weight.size()][bagWeight];
    
}

int max_profit_knapsack( vector<int> weight, vector<int> value, int bagWeight ) {
    
    int result = 0;
    int n      = weight.size();
    
    result = recursive_solution(weight, value, bagWeight, n);
    
    memoArray = vector<vector<int>>(bagWeight+1,vector<int>(n+1,-1));
    result    = recursive_with_memo_solution(weight, value, bagWeight, n);
    
    result = top_down_solution(weight, value, bagWeight);
    
    return result;
}


int main() {
    
    vector<int> weight = {1,2,4,5};
    vector<int> value  = {1,4,5,7};
    int bagWeight      = 7;
    
    int result = max_profit_knapsack(weight,value,bagWeight);
    
    cout<<endl<<"Result: "<<result<<endl;
    
    return 0;
    
}

