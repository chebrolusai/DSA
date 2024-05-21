/*
 * Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
 * You must not use any built-in exponent function or operator.
 *
 * https://leetcode.com/problems/sqrtx/description/
*/

class Solution {
public:
    int mySqrt(int x) {

        int start = 0;
        int end = x / 2 + 1;

        while (start <= end) {

            long int mid = start + (end - start) / 2;

            long int squared = mid * mid;

            if (squared == x) {
                return mid;
            }

            if (squared < x) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return end;
    }
};
