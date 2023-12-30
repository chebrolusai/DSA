//
//  longest_common_substr.cpp
//  DataStructuresAndAlgo
//
//  Created by sai chebrolu on 29/12/23.
//
//  PROBLEM: LONGEST COMMON SUBSTRING
//  DESCRIPTION: Given two strings, find the longest common substring between them.
//  SOLUTION:  Both solutions will give the same results ( memo and top down approach )

#include <iostream>
#include <vector>
using namespace std;

vector<vector<vector<int>>> memoArray;

string memoPrint = "";
int memoMax   = INT_MIN;

int longest_common_substr_recursion_with_memo_solution( string s1, string s2, int s1Index, int s2Index, int count ) {
    
    if ( count > 0 && count > memoMax ) {
        memoPrint = s1.substr(s1Index,count);
        memoMax = count;
    }

    if ( s1Index == 0 || s2Index == 0) {
        return count;
    }

    if ( memoArray[s1Index][s2Index][count] != -1 ) {
        return memoArray[s1Index][s2Index][count];
    }
    
    int subArrayMax = count;
    
    if ( s1[s1Index-1] == s2[s2Index-1] ) {
        subArrayMax = longest_common_substr_recursion_with_memo_solution( s1, s2, s1Index-1, s2Index-1, count+1);
    }
    
    subArrayMax = max(subArrayMax,max(longest_common_substr_recursion_with_memo_solution(s1, s2, s1Index-1, s2Index, 0 ), longest_common_substr_recursion_with_memo_solution(s1, s2, s1Index, s2Index-1, 0) ));
    
    return memoArray[s1Index][s2Index][count] = subArrayMax;
    
}

int longest_common_substr_top_down_solution( string s1, string s2) {
    
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
                
                topDownArray[i][j] = 0;
                
            }
            
        }
        
    }
    
    int result = INT_MIN;
    
    int answerIthIndex = -1;
    
    for ( int i=0; i<s1.size()+1; i++) {
        
        for (int j=0; j<s2.size()+1; j++) {
            
            if ( topDownArray[i][j] > result ) {
                result = topDownArray[i][j];
                answerIthIndex = i;
            }
            
        }
        
    }
    
    string answer = s1.substr(answerIthIndex-result, result);
    
    cout<<endl<<"Longest Common Substring(top down): "<<answer<<endl;
    
    return result;
    
}


int longest_common_substr( string s1, string s2) {
    
    int result = 0;
    
    memoArray = vector<vector<vector<int>>> ( s1.size()+1, vector<vector<int>>(s2.size()+1, vector<int>( min(s1.size(),s2.size()) + 1,-1)));
    result = longest_common_substr_recursion_with_memo_solution( s1, s2, s1.size(), s2.size(), 0 );
    cout<<endl<<"Longest Common Substring(memo): "<<memoPrint<<endl;
    result = longest_common_substr_top_down_solution(s1, s2);
    
    return result;
    
}


int dp_10() {
    
    string string1 = "adherc";
    string string2 = "adadhec";
    
    int result = longest_common_substr(string1, string2);
    
    cout<<endl<<"Result: "<<result<<endl;
    
    return 0;
    
}


