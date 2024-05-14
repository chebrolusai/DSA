/*
 * Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is
 * the smallest in lexicographical order among all possible results.
 *
 * https://leetcode.com/problems/remove-duplicate-letters/description/
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        unordered_map<char,int> freq;
        unordered_set<char> present_in_stack;

        stack<char> st;

        for(int i=0; i<s.size(); i++) {
            freq[s[i]]++;
        }

        for(int i=0; i<s.size(); i++) {

            if ( st.empty() ) {

                st.push(s[i]);
                present_in_stack.insert(s[i]);
                freq[s[i]]--;
            }

            else {

                if ( present_in_stack.count(s[i]) ) {
                    freq[s[i]]--;
                    continue;
                }

                while(!st.empty() && s[i] < st.top() && freq[st.top()] > 0 ) {
                    present_in_stack.erase(st.top());
                    st.pop();
                }

                st.push(s[i]);
                present_in_stack.insert(s[i]);
                freq[s[i]]--;

            }

        }

        string result = "";

        while(!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(),result.end());

        return result;

    }
};
