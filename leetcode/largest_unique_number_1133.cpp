/*
 * Given an integer array nums, return the largest integer that only occurs once. If no integer occurs once, return -1.
 *
 * https://leetcode.com/problems/largest-unique-number/description/
*/

class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        
        unordered_map<int,int> freq;

        int result = -1;

        for(int i=0; i<nums.size(); i++) {
            freq[nums[i]]++;
        }

        for(auto it: freq) {
            if ( it.second == 1 && it.first > result ) {
                result = it.first;
            }
        }

        return result;

    }
};
