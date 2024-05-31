/*
 *Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
 * [4,5,6,7,0,1,2] if it was rotated 4 times.
 * [0,1,2,4,5,6,7] if it was rotated 7 times.
 * Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
 * Given the sorted rotated array nums of unique elements, return the minimum element of this array.
 * You must write an algorithm that runs in O(log n) time.
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
*/

class Solution {
public:
    int findMin(vector<int>& nums) {

        int N = nums.size();

        if (N == 1 || nums[0] < nums[N - 1]) {
            return nums[0];
        }

        int start = 0;
        int end = N - 1;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            int next_element = (mid + 1) % N;
            int prev_element = (mid - 1 + N) % N;

            if (nums[mid] <= nums[next_element] &&
                nums[mid] <= nums[prev_element]) {
                return nums[mid];
            }

            if (nums[0] <= nums[mid]) {
                start = mid + 1;
            }

            else if (nums[N - 1] >= nums[mid]) {
                end = mid - 1;
            }
        }

        return 0;
    }
};
