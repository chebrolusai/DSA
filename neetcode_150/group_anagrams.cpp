/*
 * Given an array of strings strs, group the anagrams together. You can return the answer in any order.
 * An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
 *
 * https://leetcode.com/problems/group-anagrams/description/
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> anagrams;

        for (auto it : strs) {

            string temp = it;

            sort(temp.begin(), temp.end());

            anagrams[temp].push_back(it);
        }

        vector<vector<string>> result;

        for (auto it : anagrams) {

            vector<string> temp = it.second;

            result.push_back(temp);
        }

        return result;
    }
};
