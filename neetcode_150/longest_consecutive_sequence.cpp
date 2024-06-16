/*
 * Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
 * You must write an algorithm that runs in O(n) time.
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_map<int, int> numbers;

        for (auto it : nums) {
            numbers[it] = 0;
        }

        int result = 0;

        unordered_map<int, int> sequence;

        for (int i = 0; i < nums.size(); i++) {

            if (numbers[nums[i]] > 0) {
                continue;
            }

            int count = 0;

            int temp = nums[i];

            while (numbers.count(temp)) {

                numbers[temp] = 1;
                count++;
                temp++;

                if (sequence.count(temp)) {
                    count += sequence[temp];
                    break;
                }
            }

            sequence[nums[i]] = count;

            if (count > result) {
                result = count;
            }
        }

        return result;
    }
};
