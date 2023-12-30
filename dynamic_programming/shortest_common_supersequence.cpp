//
//  shortest_common_superseq.cpp
//  DataStructuresAndAlgo
//
//  Created by sai chebrolu on 29/12/23.
//
//  PROBLEM: SHORTEST COMMON SUPERSEQUENCE
//  DESCRIPTION: Given two strings, find the shortest common supersequence between them.
//  SOLUTION:  Both solutions will give the same results ( memo and top down approach )

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> memoArray;

int shortest_common_superseq_recursion_with_memo_solution( string s1, string s2, int s1Index, int s2Index ) {
    
    if ( s1Index == 0 || s2Index == 0 ) {
        return 0;
    }
    
    if (  memoArray[s1Index][s2Index] != -1 ) {
        return  memoArray[s1Index][s2Index];
    }
    
    if ( s1[s1Index-1] == s2[s2Index-1] ) {
        return memoArray[s1Index][s2Index] = 1 + shortest_common_superseq_recursion_with_memo_solution(s1, s2, s1Index-1, s2Index-1);
    }
    
    return  memoArray[s1Index][s2Index] = max( shortest_common_superseq_recursion_with_memo_solution(s1, s2, s1Index-1, s2Index), shortest_common_superseq_recursion_with_memo_solution(s1, s2, s1Index, s2Index-1) );
    
}

int shortest_common_superseq_top_down_solution( string s1, string s2) {
    
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


int shortest_common_superseq( string s1, string s2) {
    
    int result = 0;
    
    memoArray = vector<vector<int>> ( s1.size()+1, vector<int>(s2.size()+1,-1));
    result = shortest_common_superseq_recursion_with_memo_solution( s1, s2, s1.size(), s2.size() );
    
    result = shortest_common_superseq_top_down_solution(s1, s2);
    
    return ( s1.size()+s2.size() ) - result;
    
}


int dp_11() {
    
    string string1 = "geek";
    string string2 = "eke";
    
    int result = shortest_common_superseq(string1, string2);
    
    cout<<endl<<"Result: "<<result<<endl;
    
    return 0;
    
}

