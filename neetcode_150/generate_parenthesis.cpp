/*
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * https://leetcode.com/problems/generate-parentheses/description/
*/

class Solution {
public:
    void solve(int open, int close, int n, string& s, vector<string>& res) {
        if (close > open) {
            return;
        }
        if (open == n and close == n) {
            res.push_back(s);
            return;
        }

        if (open != n) {
            s.push_back('(');
            solve(open + 1, close, n, s, res);
            s.pop_back();
        }

        if (close != n and close < open) {
            s.push_back(')');
            solve(open, close + 1, n, s, res);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        solve(0, 0, n, s, res);
        return res;
    }
};
