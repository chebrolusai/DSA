/*
 * Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
 * You must write an algorithm with O(log n) runtime complexity.
 *
 * https://leetcode.com/problems/binary-search/description/
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int start = 0;
        int end   = nums.size() - 1;

        while ( start <= end ) {

            int mid = start + (end - start)/2;

            if ( nums[mid] == target ) {
                return mid;
            }

            if ( nums[mid] > target ) {

                end = mid-1;

            }
            else {
                start = mid + 1;
            }

        }

        return -1;

    }
};
