/*
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 * An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
 *
 * https://leetcode.com/problems/valid-anagram/description/
*/

class Solution {
public:
    bool isAnagram(string s, string t) {

        if ( s.size() != t.size() ) {
            return false;
        }
        
        vector<int> charCount(26,0);

        for( int i=0; i<s.size(); i++ ) {

            charCount[s[i]-'a']++;
            charCount[t[i]-'a']--;

        }

        for( int i=0; i<26; i++ ) {

            if ( charCount[i] != 0 ) {
                return false;
            }

        }

        return true;

    }
};
