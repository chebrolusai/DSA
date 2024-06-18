/*
 * You are given an m x n integer matrix matrix with the following two properties:
 * Each row is sorted in non-decreasing order.
 * The first integer of each row is greater than the last integer of the previous row.
 * Given an integer target, return true if target is in matrix or false otherwise.
 * You must write a solution in O(log(m * n)) time complexity.
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
*/

class Solution {
public:

    bool rowBinarySearch( vector<int>& row, int target ) {

        int start = 0;
        int end   = row.size()-1;

        while ( start <= end ) {

            int mid = start + ( end - start )/2;
            
            if ( target > row[mid] ) {

                start = mid + 1;

            }
            else if ( target < row[mid] ) {

                end = mid - 1;

            }
            else {
                return true;
            }

        }

        return false;

    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int start = 0;
        int end   = matrix.size()-1;
        int n     = matrix[0].size();

        while ( start <= end ) {

            int mid = start + ( end - start )/2;

            if ( target > matrix[mid][n-1] ) {

                start = mid + 1;

            }
            else if ( target < matrix[mid][0] ) {

                end = mid - 1;

            }
            
            else {

                return rowBinarySearch(matrix[mid], target);

            }

        }

        return false;

    }
};
