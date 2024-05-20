/*
 * A peak element is an element that is strictly greater than its neighbors.
 * Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
 * You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
 * You must write an algorithm that runs in O(log n) time.
 *
 * https://leetcode.com/problems/find-peak-element/description/
*/

class Solution {
public:

    int findPeakElement(vector<int>& nums) {
        
        int N = nums.size();

        if ( N == 1 ) {
            return 0;
        }

        if (N == 2) {
            if ( nums[0] > nums[1] ) {
                return 0;
            }
            return 1;
        }
 
        int start = 0;
        int end   = nums.size() -1;

        while(start <= end) {

            int mid = start + (end - start)/2;

            if ( (mid == 0 && nums[mid] > nums[mid+1]) ||  (mid == N-1 && nums[N-1] > nums[N-2]) ) {
                return mid;
            }

            if (nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]) {
                return mid;
            }

            if ( nums[mid] < nums[mid+1] ) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }


        }

        return -1;

    }
};
