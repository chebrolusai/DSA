//
//  problem9.cpp
//  DataStructuresAndAlgo
//
//  Created by sai chebrolu on 23/12/23.
//

/*
    PROBLEM: FIND ALL ANAGRAMS IN A STRING
    DESCRIPTION:Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order. An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
 */

#include<iostream>
#include <stdio.h>
#include <unordered_map>
#include <vector>

using namespace std;



vector<int> find_all_anagrams ( string s, string p) {
    
    unordered_map<char,int> characterCount;

    int startIndex = 0;
    int endIndex   = 0;
    int count      = 0;
    int k          = 0;

    vector<int> result;

    for (int i=0; i<p.size(); i++) {
        characterCount[p[i]]++;
    }

    count = characterCount.size();
    k     = p.size();

    while ( endIndex < s.size() ) {

        if(characterCount.count(s[endIndex])) {

            characterCount[s[endIndex]]--;

            if ( characterCount[s[endIndex]] == 0 ) {
                count--;
            }
        }

        if ( endIndex-startIndex+1 < k ) {
            endIndex++;
        }
        else {

            if (count == 0) {
                result.push_back(startIndex);
            }

            if(characterCount.count(s[startIndex])) {

                characterCount[s[startIndex]]++;

                if ( characterCount[s[startIndex]] == 1 ) {
                    count++;
                }

            }

            startIndex++;
            endIndex++;

        }

    }

    return result;
    
}

int main() {
    
    string input = "cbaebabacd";
    string pattern = "abc";
    
    vector<int> result = find_all_anagrams(input, pattern);
    
    for(auto it: result){
        cout<<it<<" ";
    }
    
    cout<<endl;
    
    return 0;
    
}
