/*
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * An input string is valid if:
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Every close bracket has a corresponding open bracket of the same type.
 *
 * https://leetcode.com/problems/valid-parentheses/description/
*/

class Solution {
public:
    bool isValid(string s) {
        
        unordered_set<char> openingBrackets = {'(','{','['};

        unordered_map<char,char> closingBackets;

        closingBackets[')'] = '(';
        closingBackets[']'] = '[';
        closingBackets['}'] = '{';

        stack<char> balanceStack;

        for ( int i=0; i<s.size(); i++ ) {

            if ( openingBrackets.count(s[i]) ) {
                balanceStack.push(s[i]);
            }
            else {

                if ( !balanceStack.empty() && balanceStack.top() == closingBackets[s[i]] ) {

                    balanceStack.pop();

                }

                else {
                    return false;
                }

            }

        }
        
        return balanceStack.empty() ? true:false;

    }
};
