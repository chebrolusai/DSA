//
//  coin_change_max_ways.cpp
//  DataStructuresAndAlgo
//
//  Created by sai chebrolu on 28/12/23.
//
//  PROBLEM: MAX NUMBER OF WAYS TO GIVE CHANGE
//  DESCRIPTION: Given a coins array and a target sum, return the total number of ways to give change - you can use each coin any number of times.
//  SOLUTION: Both solutions will give the same results ( memo and top down approach )

#include <iostream>
#include <vector>
using namespace std;


// globals
vector<vector<int>> memoArray;

int coin_change_max_num_of_ways_recursion_with_memo_solution( vector<int>& coins, int sum, int n) {
    
    if ( sum == 0 ) {
        return memoArray[n][sum] =  1;
    }
    
    if ( n == 0 ) {
        return memoArray[n][sum] = 0;
    }
    
    if ( memoArray[n][sum] != -1 ) {
        return memoArray[n][sum];
    }
    
    if ( coins[n-1] <= sum ) {
        
        return memoArray[n][sum] = coin_change_max_num_of_ways_recursion_with_memo_solution( coins, sum - coins[n-1], n ) + coin_change_max_num_of_ways_recursion_with_memo_solution(coins, sum, n-1);
        
    }
    
    return memoArray[n][sum] = coin_change_max_num_of_ways_recursion_with_memo_solution(coins, sum, n-1);
    
}

int coin_change_max_num_of_ways_top_down_solution(vector<int>& coins, int sum) {
    
    int topDownArray[coins.size()+1][sum+1];
    
    for ( int i=0; i<coins.size()+1; i++ ) {
        
        topDownArray[i][0] = 1;
        
    }
    
    for ( int j=1; j<sum+1; j++ ) {
        
        topDownArray[0][j] = 0;
        
    }
    
    for (int i=1; i<coins.size()+1; i++) {
        
        for ( int j=1; j<sum+1; j++) {
            
            if ( coins[i-1] <= j ) {
                
                topDownArray[i][j] = topDownArray[i][j-coins[i-1]] + topDownArray[i-1][j];
                
            }
            
            else {
                
                topDownArray[i][j] = topDownArray[i-1][j];
                
            }
            
        }
    }
    
    
    return topDownArray[coins.size()][sum];
    
}

int coin_change_max_num_of_ways( vector<int>& coins, int sum) {
    
    int result = 0;
    
    memoArray = vector<vector<int>> ( coins.size()+1, vector<int>( sum+1, -1 ));
    
    result = coin_change_max_num_of_ways_recursion_with_memo_solution(coins,sum, coins.size());
    
    result = coin_change_max_num_of_ways_top_down_solution(coins, sum);
    
    return result;
    
}


int main() {
    
    vector<int> coins = {1,2,3};
    int sum           = 5;
    
    int result = coin_change_max_num_of_ways(coins, sum);
    
    cout<<endl<<"Result: "<<result<<endl;
    
    return 0;
    
}
