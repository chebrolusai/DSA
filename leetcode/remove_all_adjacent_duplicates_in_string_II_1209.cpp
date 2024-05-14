/*
 * You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.
 * We repeatedly make k duplicate removals on s until we no longer can.
 * Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.
 *
 * https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/
*/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char,int>> st;

        for( int i=0; i<s.size(); i++ ) {

            if ( st.empty() ) {
                st.push({s[i],1});
            }

            else {

                if ( s[i] == st.top().first && st.top().second + 1 == k ) {
                    int temp = k - 1;

                    while ( temp > 0 ) {
                        st.pop();
                        temp--;
                    }
                } 

                else if ( s[i] == st.top().first ) {
                    st.push({s[i],st.top().second+1});
                }

                else {
                    st.push({s[i],1});
                }

            }

        }

        string result = "";

        while ( !st.empty() ) {
            result += st.top().first;
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;

    }
};
