/*
 * Given a string s of '(' , ')' and lowercase English characters.
 * Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
 * Formally, a parentheses string is valid if and only if:
 * It is the empty string, contains only lowercase characters, or
 * It can be written as AB (A concatenated with B), where A and B are valid strings, or
 * It can be written as (A), where A is a valid string.
 *
 * https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/
*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        vector<pair<char,int>> parenthesis;

        for(int i =0; i<s.size(); i++) {

            if ( s[i] == ')' || s[i] == '(') {
                if ( parenthesis.empty() || s[i] == '(' ) {
                    parenthesis.push_back({s[i],i});
                    continue;
                }

                if ( s[i] == ')' && parenthesis.back().first == '(') {
                    parenthesis.pop_back();
                    continue;
                }

                parenthesis.push_back({s[i],i});
            }
 
        }

        unordered_set<int> skip_indexes;

        for ( auto it : parenthesis ) {
            skip_indexes.insert(it.second);
        }

        string result = "";

        for(int i=0; i<s.size(); i++) {

            if ( skip_indexes.count(i) ) {
                continue;
            }

            result += s[i];

        }

        return result;

    }
};
