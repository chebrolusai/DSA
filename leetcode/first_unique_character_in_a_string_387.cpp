/*
 * Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
*/

class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char,int> present;

        for(int i=0; i<s.size(); i++) {

            if ( present.count(s[i]) ) {
                present[s[i]] = -1;
                continue;
            }

            present[s[i]] = i;

        }


        for(int i=0; i<s.size(); i++) {

            if ( present[s[i]] != -1 ) {
                return present[s[i]];
            }

        }

        return -1;

    }
};
