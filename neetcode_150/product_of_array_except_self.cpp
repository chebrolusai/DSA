/*
 * Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 * You must write an algorithm that runs in O(n) time and without using the division operation.
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> leftToRightProduct(nums.size());
        vector<int> rightToLeftProduct(nums.size());

        int left = 1;
        int right = 1;

        for (int i = 0; i < nums.size(); i++) {

            leftToRightProduct[i] = left * nums[i];
            left = left * nums[i];
        }

        for (int i = nums.size() - 1; i >= 0; i--) {

            rightToLeftProduct[i] = right * nums[i];
            right = right * nums[i];
        }

        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {

            if (i == 0) {
                result.push_back(rightToLeftProduct[1]);
            } else if (i == nums.size() - 1) {
                result.push_back(leftToRightProduct[nums.size() - 2]);
            } else {

                result.push_back(rightToLeftProduct[i + 1] *
                                 leftToRightProduct[i - 1]);
            }
        }

        return result;
    }
};
