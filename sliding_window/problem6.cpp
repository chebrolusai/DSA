//
//  problem6.cpp
//  DataStructuresAndAlgo
//
//  Created by sai chebrolu on 23/12/23.
//

/*
    PROBLEM: LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS
    DESCRIPTION: Given a string s, find the length of the longest substring without repeating characters.
 */

#include <iostream>
#include <stdio.h>
#include <unordered_map>
using namespace std;


int length_of_longest_substring(string s) {
    
    unordered_map<char,int> characterCount;

    int startIndex = 0;
    int endIndex   = 0;
    int result     = 0;

    while ( endIndex < s.size() ) {

        characterCount[s[endIndex]]++;

        if ( characterCount.size() == (endIndex-startIndex+1) ) {
            result = max(result, endIndex-startIndex+1);
            endIndex++;
        }
        else {

            while ( characterCount.size() < (endIndex-startIndex+1) ) {
            
                characterCount[s[startIndex]]--;
                if( characterCount[s[startIndex]] == 0 ) {
                    characterCount.erase(s[startIndex]);
                }
                startIndex++;

            }

            endIndex++;

        }

    }

    return result;

}

int main() {
    
    string input = "aababcabc";
    
    int result = length_of_longest_substring(input);
    
    cout<<endl<<"Result: "<<result<<endl;
    
    return 0;

}

