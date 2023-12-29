//
//  coin_change_min_coins.cpp
//  DataStructuresAndAlgo
//
//  Created by sai chebrolu on 28/12/23.
//
//  PROBLEM: MIN COINS TO GIVE CHANGE
//  DESCRIPTION: Given a coins array and a target sum, return the min number of coins required to give the change
//  SOLUTION: Both solutions will give the same results ( memo and top down approach )

#include <iostream>
#include <vector>
using namespace std;

// globals
vector<vector<int>> memoArray;

int coin_change_min_num_of_coins_recursion_with_memo_solution( vector<int>& coins, int sum, int n) {
    
    if ( sum == 0 ) {
        return memoArray[n][sum] =  0;
    }
    
    if ( n == 0 ) {
        return memoArray[n][sum] = INT_MAX - 1;
    }
    
    if ( memoArray[n][sum] != -1 ) {
        return memoArray[n][sum];
    }
    
    if ( coins[n-1] <= sum ) {
        
        return memoArray[n][sum] = min ( 1 + coin_change_min_num_of_coins_recursion_with_memo_solution( coins, sum - coins[n-1], n ) , coin_change_min_num_of_coins_recursion_with_memo_solution(coins, sum, n-1));
        
    }
    
    return memoArray[n][sum] = coin_change_min_num_of_coins_recursion_with_memo_solution(coins, sum, n-1);
    
}

int coin_change_min_num_of_coins_top_down_solution(vector<int>& coins, int sum) {
    
    int topDownArray[coins.size()+1][sum+1];
    
    for ( int i=0; i<coins.size()+1; i++ ) {
        
        topDownArray[i][0] = 0;
        
    }
    
    for ( int j=1; j<sum+1; j++ ) {
        
        topDownArray[0][j] = INT_MAX - 1;
        
    }
    
    for (int i=1; i<coins.size()+1; i++) {
        
        for ( int j=1; j<sum+1; j++) {
            
            if ( coins[i-1] <= j ) {
                
                topDownArray[i][j] = min ( 1 + topDownArray[i][j-coins[i-1]] , topDownArray[i-1][j] );
                
            }
            
            else {
                
                topDownArray[i][j] = topDownArray[i-1][j];
                
            }
            
        }
    }
    
    
    return topDownArray[coins.size()][sum];
    
}

int coin_change_min_num_of_coins( vector<int>& coins, int sum) {
    
    int result = 0;
    
    memoArray = vector<vector<int>> ( coins.size()+1, vector<int>( sum+1, -1 ));
    
    result = coin_change_min_num_of_coins_recursion_with_memo_solution(coins,sum, coins.size());
    
    result = coin_change_min_num_of_coins_top_down_solution(coins, sum);
    
    return result;
    
}


int main() {
    
    vector<int> coins = {1,2,3};
    int sum           = 5;
    
    int result = coin_change_min_num_of_coins(coins, sum);
    
    cout<<endl<<"Result: "<<result<<endl;
    
    return 0;
    
}
