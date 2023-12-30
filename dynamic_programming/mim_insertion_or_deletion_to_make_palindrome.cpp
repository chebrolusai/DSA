//
//  longest_palindromic_subsequence.cpp
//  DataStructuresAndAlgo
//
//  Created by sai chebrolu on 29/12/23.
//
//  PROBLEM: MIN INSERTIONS OR DELETIONS TO CONVERT STRING TO PALINDROME
//  DESCRIPTION: Given a string, find the minimum number of insertions or deletions to make it a palindrome
//  SOLUTION:  Both solutions will give the same results ( memo and top down approach )

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> memoArray;

int ins_del_to_make_palindrome_recursion_with_memo_solution( string s1, string s2, int s1Index, int s2Index ) {
    
    if ( s1Index == 0 || s2Index == 0 ) {
        return 0;
    }
    
    if (  memoArray[s1Index][s2Index] != -1 ) {
        return  memoArray[s1Index][s2Index];
    }
    
    if ( s1[s1Index-1] == s2[s2Index-1] ) {
        return memoArray[s1Index][s2Index] = 1 + ins_del_to_make_palindrome_recursion_with_memo_solution(s1, s2, s1Index-1, s2Index-1);
    }
    
    return  memoArray[s1Index][s2Index] = max( ins_del_to_make_palindrome_recursion_with_memo_solution(s1, s2, s1Index-1, s2Index), ins_del_to_make_palindrome_recursion_with_memo_solution(s1, s2, s1Index, s2Index-1) );
    
}

int ins_del_to_make_palindrome_top_down_solution( string s1, string s2) {
    
    int topDownArray[s1.size()+1][s2.size()+1];
    
    for ( int i=0; i<s1.size()+1; i++) {
        
        topDownArray[i][0] = 0;
        
    }
    
    for ( int j=0; j<s2.size()+1; j++) {
        
        topDownArray[0][j] = 0;
        
    }
    
    for (int i=1; i<s1.size()+1; i++) {
        
        for ( int j=1; j<s2.size()+1; j++) {
            
            if ( s1[i-1] == s2[j-1] ) {
                
                topDownArray[i][j] = 1 + topDownArray[i-1][j-1];
                
            }
            else {
                
                topDownArray[i][j] = max ( topDownArray[i-1][j] , topDownArray[i][j-1] );
                
            }
            
        }
        
    }
    
    return topDownArray[s1.size()][s2.size()];
    
}


int ins_del_to_make_palindrome( string input) {
    
    int result = 0;
    
    string str = input;
    reverse(str.begin(),str.end());
    
    memoArray = vector<vector<int>> ( input.size()+1, vector<int>(input.size()+1,-1));
    result = ins_del_to_make_palindrome_recursion_with_memo_solution(input, str, input.size(), input.size());
    
    result = ins_del_to_make_palindrome_top_down_solution(input, str);
    
    return input.size() - result;
}


int dp_14() {
    
    string input = "nitpidan";
    
    int result = ins_del_to_make_palindrome(input);
    
    cout<<endl<<"Result: "<<result<<endl;
    
    return 0;
    
}
