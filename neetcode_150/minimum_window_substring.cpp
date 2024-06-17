/*
 * Given two strings s and t of lengths m and n respectively, return the minimum window substring
 * of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
 * The testcases will be generated such that the answer is unique.
 *
 * https://leetcode.com/problems/minimum-window-substring/
*/

class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> charOccurances;
        int count = 0;

        for (int i = 0; i < t.size(); i++) {

            charOccurances[t[i]]++;

            if (charOccurances[t[i]] == 1) {
                count++;
            }
        }

        int start = 0;
        int end = 0;
        int minLen = INT_MAX;
        int startIndex = -1;
        string result = "";

        while (end < s.size()) {

            if (charOccurances.count(s[end])) {

                charOccurances[s[end]]--;

                if (charOccurances[s[end]] == 0) {
                    count--;
                }
            }

            if (count > 0) {
                end++;
            } else {

                while (count == 0) {

                    if (end - start + 1 < minLen) {
                        minLen = end - start + 1;
                        startIndex = start;
                    }

                    if (charOccurances.count(s[start])) {

                        charOccurances[s[start]]++;

                        if (charOccurances[s[start]] == 1) {
                            count++;
                        }
                    }
                    start++;
                }

                end++;
            }
        }

        if (startIndex == -1) {
            return "";
        }

        return s.substr(startIndex, minLen);
    }
};
