/*
 * Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.
 * strs2 in Machine 2 should be the same as strs in Machine 1.
 * Implement the encode and decode methods.
 * You are not allowed to solve the problem using any serialize methods (such as eval).
 *
 * https://leetcode.com/problems/encode-and-decode-strings/description/
*/

class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {

        string encoded = "";

        for (int i = 0; i < strs.size(); i++) {

            string str_len = to_string(strs[i].size());

            while (str_len.size() < 3) {
                str_len = "0" + str_len;
            }

            encoded += str_len + strs[i];
        }

        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {

        int i = 0;

        vector<string> result;

        while (i < s.size()) {

            string length_sub_string = s.substr(i, 3);

            int length = stoi(length_sub_string);

            if (length == 0) {
                result.push_back("");
            } else {
                result.push_back(s.substr(i + 3, length));
            }

            i += 3 + length;
        }

        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
