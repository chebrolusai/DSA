/*
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 *
 * https://leetcode.com/problems/valid-sudoku/description/
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<char> rowSet, colSet;

        for (int i = 0; i < 9; i++) {

            for (int j = 0; j < 9; j++) {

                if (rowSet.count(board[i][j]) || colSet.count(board[j][i])) {
                    return false;
                }

                if (board[i][j] != '.') {
                    rowSet.insert(board[i][j]);
                }
                if (board[j][i] != '.') {
                    colSet.insert(board[j][i]);
                }
            }

            rowSet.clear();
            colSet.clear();
        }

        for (int iStart = 0; iStart < 9; iStart += 3) {

            for (int jStart = 0; jStart < 9; jStart += 3) {

                unordered_set<char> boxSet;

                for (int i = iStart; i < iStart + 3; i++) {

                    for (int j = jStart; j < jStart + 3; j++) {

                        if (boxSet.count(board[i][j])) {
                            return false;
                        }

                        if (board[i][j] != '.') {
                            boxSet.insert(board[i][j]);
                        }
                    }
                }
            }
        }

        return true;
    }
};
