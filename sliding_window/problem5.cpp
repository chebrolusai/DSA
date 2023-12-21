//
//  problem5.cpp
//  DataStructuresAndAlgo
//
//  Created by sai chebrolu on 20/12/23.
//

/*
    PROBLEM: SUBSTRING OF SIZE 3 WITH DISTINCT CHARS
    DESCRIPTION: A string is good if there are no repeated characters.Given a string, return the number of good substrings of length three in s
 */

#include <iostream>
#include <stdio.h>
#include <unordered_map>
using namespace std;


int count_good_substrings(string s) {
    
    int k          = 3;
    int result     = 0;
    int startIndex = 0;
    int endIndex   = 0;

    unordered_map<char,int> characterCounts;

    while ( endIndex < s.size() ) {

        characterCounts[s[endIndex]]++;

        if ( endIndex - startIndex + 1 < k ) {
            endIndex++;
        }

        else {

            if ( characterCounts.size() == (endIndex-startIndex+1) ) {
                result++;
            }

            characterCounts[s[startIndex]]--;

            if ( characterCounts[s[startIndex]] == 0 ) {
                characterCounts.erase(s[startIndex]);
            }

            startIndex++;
            endIndex++;

        }

    }

    return result;

}

int main() {
    
    string input = "aababcabc";
    
    int result = count_good_substrings(input);
    
    cout<<endl<<"Result: "<<result<<endl;
    
    return 0;
  
}
