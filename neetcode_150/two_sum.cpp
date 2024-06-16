/*
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 *
 * https://leetcode.com/problems/two-sum/description/
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> presentNumbers;

        vector<int> result;

        for (int i=0; i<nums.size(); i++) {

            if( presentNumbers.count(target-nums[i]) ) {

                result.push_back(i);
                result.push_back(presentNumbers[target-nums[i]]);

            }

            presentNumbers[nums[i]] = i;

        }

        return result;

    }
};
