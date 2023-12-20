//
//  problem2.cpp
//  DataStructuresAndAlgo
//
//  Created by sai chebrolu on 20/12/23.
//

/*
    PROBLEM: COUNT OCCURANCES OF ANAGRAMS
    DESCRIPTION: Given a pattern and an input string, search for anagrams of the pattern in the input string and return the count.
*/

#include <iostream>
#include <stdio.h>
#include <unordered_map>
using namespace std;


int count_anagram_occurances(string input, string pattern) {
    
    unordered_map<char, int> characterOccurances;
    
    int mapCharacterCount = 0;
    int result            = 0;
    int windowSize        = pattern.size();
    
    for (int i=0; i<pattern.size(); i++) {
        
        characterOccurances[pattern[i]]++;
        
    }
    
    mapCharacterCount = characterOccurances.size();
    int startIndex    = 0;
    int endIndex      = 0;
    
    while (endIndex < input.size()) {
        
        if ( characterOccurances.find(input[endIndex]) != characterOccurances.end() ) {
            
            characterOccurances[input[endIndex]]--;
            
            if ( characterOccurances[input[endIndex]] == 0 ) {
                    
                mapCharacterCount--;
                
            }
        }
        
        if ( endIndex - startIndex + 1 < windowSize ) {
            
            endIndex++;
            
        }
        
        else {
            
            if ( mapCharacterCount == 0 ) {
                
                result++;
                
            }
            
            if ( characterOccurances.find(input[startIndex]) != characterOccurances.end() ) {
                
                characterOccurances[input[startIndex]]++;
                
                if ( characterOccurances[input[startIndex]] == 1 ) {
                        
                    mapCharacterCount++;
                    
                }
            }
            
            endIndex++;
            startIndex++;
            
        }
        
    }
    
    
    
    return result;
}


int main() {
    
    string input   = "aaaabbbaaab";
    string pattern = "aab";
    
    int result = count_anagram_occurances(input,pattern);
    
    cout<<endl<<"Total Anagrams: "<<result<<endl;
    
    return 0;
    
}
