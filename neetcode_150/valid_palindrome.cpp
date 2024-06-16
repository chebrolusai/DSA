/*
 * A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
 * Given a string s, return true if it is a palindrome, or false otherwise.
 *
 * https://leetcode.com/problems/valid-palindrome/description/
*/

class Solution {
public:
    bool isPalindrome(string s) {

        int start = 0;
        int end = s.size() - 1;

        while (start <= end) {

            while (start <= end && !isalnum(s[start])) {
                start++;
            }

            while (start <= end && !isalnum(s[end])) {
                end--;
            }

            if (start <= end && tolower(s[start]) != tolower(s[end])) {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }
};
