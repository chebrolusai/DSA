/*
 * Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
 *
 * https://leetcode.com/problems/contains-duplicate/description/
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int> visited;

        for (int i=0; i<nums.size(); i++) {

            if ( visited.count(nums[i]) ) {
                return true;
            }

            visited.insert(nums[i]);

        }

        return false;

    }
};
