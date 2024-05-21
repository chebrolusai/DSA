/*
 * Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.
 * Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.
 *
 * https://leetcode.com/problems/minimum-common-value/description/
*/

class Solution {
public:
    bool binarySearch(vector<int>& nums, int target) {

        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return true;
            }

            if (target > nums[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return false;
    }

    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        for (int i = 0; i < nums1.size(); i++) {

            if (binarySearch(nums2, nums1[i])) {
                return nums1[i];
            }
        }

        return -1;
    }
};
