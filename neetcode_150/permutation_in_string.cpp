/*
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
 * In other words, return true if one of s1's permutations is the substring of s2.
 *
 * https://leetcode.com/problems/permutation-in-string/
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char,int> characterCount;
        int count = 0;

        for( int i=0; i<s1.size(); i++ ) {

            characterCount[s1[i]]++;

            if ( characterCount[s1[i]] == 1 ) {
                count++;
            }

        }

        int end   = 0;
        int start = 0;

        while( end < s2.size() ) {

            if ( characterCount.count(s2[end]) ) {

                characterCount[s2[end]]--;

                if ( characterCount[s2[end]] == 0 ) {
                    count--;
                }

            }

            if ( end-start+1 <= s1.size() ) {

                end++;

            }
            else {

                if ( characterCount.count(s2[start]) ) {

                    characterCount[s2[start]]++;

                    if ( characterCount[s2[start]] == 1 ) {
                        count++;
                    }

                }

                start++;
                end++;

            }

            if ( count == 0 ) {
                return true;
            }

        }


        return false;

    }
};
