/*
 * Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
 * Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
 * The tests are generated such that there is exactly one solution. You may not use the same element twice.
 * Your solution must use only constant extra space.
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int start = 0;
        int end = numbers.size() - 1;

        vector<int> result;

        while (start < end) {

            if (numbers[start] + numbers[end] > target) {

                end--;

            } else if (numbers[start] + numbers[end] < target) {

                start++;

            } else {
                result.push_back(start + 1);
                result.push_back(end + 1);
                break;
            }
        }

        return result;
    }
};
