/*
 * Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int i = 0;
        int j = matrix[0].size() - 1;

        while (j >= 0 && i < matrix.size()) {

            if (matrix[i][j] == target) {
                return true;
            }

            if (target > matrix[i][j]) {
                i++;
            }

            else {
                j--;
            }
        }

        return false;
    }
};
