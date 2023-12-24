//
//  problem7.cpp
//  DataStructuresAndAlgo
//
//  Created by sai chebrolu on 23/12/23.
//

/*
    PROBLEM: LONGEST SUBSTRING WITH AT MOST K DISTINCT CHARACTERS
    DESCRIPTION: Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters.
 */

#include <iostream>
#include <stdio.h>
#include <unordered_map>
using namespace std;



int length_of_longest_substring_k_distinct(string s, int k) {
    
    unordered_map<char,int> chars;

    int startIndex = 0;
    int endIndex   = 0;
    int result     = 0;

    while ( endIndex < s.size() ) {

        chars[s[endIndex]]++;

        if ( chars.size() <= k ) {

            result = max(result, endIndex - startIndex + 1);
            endIndex++;

        }

        else {

            while ( chars.size() > k ) {

                chars[s[startIndex]]--;

                if ( chars[s[startIndex]] == 0 ){
                    chars.erase(s[startIndex]);
                }

                startIndex++;

            }

            endIndex++;

        }

    }

    return result;

}

int main() {
    
    string input = "eceba";
    int k        = 2;
    
    int result = length_of_longest_substring_k_distinct(input,k);
    
    cout<<endl<<"Result: "<<result<<endl;
    
    return 0;
    
}
