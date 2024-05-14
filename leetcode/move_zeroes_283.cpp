/*
 * Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 * Note that you must do this in-place without making a copy of the array.
 *
 * https://leetcode.com/problems/move-zeroes/description/
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int left_pointer = 0;

        for( int right_pointer=0; right_pointer < nums.size(); right_pointer++ ) {

            if ( nums[right_pointer] != 0 ) {
                swap(nums[right_pointer],nums[left_pointer]);
                left_pointer++;
            }

        }

    }
};
