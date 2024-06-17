/*
 * You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
 * Return the max sliding window.
 *
 * https://leetcode.com/problems/sliding-window-maximum/description/
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> result;

        int start = 0;
        int end = 0;
        list<int> running_list;

        while (end < nums.size()) {

            while (running_list.size() && running_list.back() < nums[end]) {
                running_list.pop_back();
            }

            running_list.push_back(nums[end]);

            if (end - start + 1 < k) {
                end++;
            }

            else {

                result.push_back(running_list.front());

                if (running_list.front() == nums[start]) {
                    running_list.pop_front();
                }

                start++;
                end++;
            }
        }

        return result;
    }
};
