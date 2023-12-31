//
//  palindrome_partitioning.cpp
//  DataStructuresAndAlgo
//
//  Created by sai chebrolu on 30/12/23.
//
//  PROBLEM: PALINDROME PARTITIONING
//  DESCRIPTION: Given a string, find the min number of partitions to make to the string such that each part is a palindrome

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> memoArray;

bool isPalindrome( string& input, int i, int j) {
    
    while( i <= j ) {
        
        if ( input[i] != input[j]) {
            return false;
        }
        
        i++;
        j--;
        
    }
    
    return true;
    
}

int palindrome_partition_recursive_solution( string &input, int i, int j) {
    
    if ( i > j ) {
        return 0;
    }
    
    if ( memoArray[i][j] != -1 ) {
        return memoArray[i][j];
    }
    
    if ( isPalindrome(input, i, j) ) {
        return 0;
    }
    
    int ans = INT_MAX;
    
    for ( int k=i; k<j; k++ ) {
        
        int temp = 1 + palindrome_partition_recursive_solution(input,i,k) + palindrome_partition_recursive_solution(input, k+1, j);
        
        ans = min(ans, temp);
        
    }
    
    return memoArray[i][j] = ans;
    
}

int palindrome_partition( string input ) {
    
    
    int result;
    
    memoArray = vector<vector<int>>( input.size()+1, vector<int>(input.size()+1,-1));
    result = palindrome_partition_recursive_solution(input, 0, input.size()-1);
    
    return result;
    
}


int dp_15() {
    
    string input = "abanitinabc";
    
    int result = palindrome_partition(input);
    
    cout<<endl<<"Result: "<<result<<endl;
    
    return 0;
    
}

