/*
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 * Notice that the solution set must not contain duplicate triplets.
 *
 * https://leetcode.com/problems/3sum/description/
*/

class Solution {
public:
    void twoSum(vector<int>& nums, int targetIndex,
                vector<vector<int>>& result) {

        unordered_map<int, int> numberOccurances;

        int target = -1 * nums[targetIndex];

        for (int i = targetIndex + 1; i < nums.size(); i++) {

            if (numberOccurances.count(target - nums[i])) {

                result.push_back(
                    {nums[targetIndex], nums[i], target - nums[i]});

                while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
                    i++;
                }
            }

            numberOccurances[nums[i]]++;
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] > 0) {
                break;
            }

            if (i == 0 || nums[i] != nums[i - 1]) {
                twoSum(nums, i, result);
            }
        }

        return result;
    }
};
