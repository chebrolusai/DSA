/*
 * You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
 * Return the length of the longest substring containing the same letter you can get after performing the above operations.
 *
 * https://leetcode.com/problems/longest-repeating-character-replacement/description/
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<int,int> chars;

        int start    = 0;
        int end      = 0;
        int max_freq = 0;
        int result   = 0;

        while(end<s.size()) {

            chars[s[end]]++;

            if(chars[s[end]] > max_freq) {

                max_freq = chars[s[end]];

            }

            if( (end-start+1) - max_freq <= k ) {

                result = max(end-start+1,result);

            }

            else {

                while( (end-start+1) - max_freq > k ) {

                    chars[s[start]]--;
                    start++;

                }

            }

            end++;

        }

        return result;

    }
};
