/*
 * Given a string s, find the length of the longest substring without repeating characters.
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> chars;

        int start = 0;
        int end = 0;
        int result = 0;

        while (end < s.size()) {

            chars[s[end]]++;

            if (chars.size() == end - start + 1) {
                result = max(result, end - start + 1);
            }

            else {

                while (chars.size() != end - start + 1) {

                    chars[s[start]]--;

                    if (chars[s[start]] == 0) {
                        chars.erase(s[start]);
                    }

                    start++;
                }
            }

            end++;
        }

        return result;
    }
};
