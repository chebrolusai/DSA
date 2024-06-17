/*
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
 *
 * https://leetcode.com/problems/trapping-rain-water/
*/

class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        vector<int> left(n, 0), right(n, 0);

        int max_height = height[0];
        left[0] = -1;

        for (int i = 1; i < height.size(); i++) {

            if (height[i] > max_height) {
                max_height = height[i];
                left[i] = -1;
            }

            else {
                left[i] = max_height;
            }
        }

        max_height = height[n - 1];
        right[n - 1] = -1;

        for (int i = n - 1; i >= 0; i--) {

            if (height[i] > max_height) {
                max_height = height[i];
                right[i] = -1;
            }

            else {
                right[i] = max_height;
            }
        }

        int result = 0;

        for (int i = 1; i < n - 1; i++) {

            int min_between_left_right = min(left[i], right[i]);

            result += max(0, min_between_left_right - height[i]);
        }

        return result;
    }
};
