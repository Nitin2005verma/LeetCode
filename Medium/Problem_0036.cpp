

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check rows
        for (int i = 0; i < 9; ++i) {
            unordered_map<char, int> rowMap;
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c != '.') {
                    if (rowMap[c]++) return false;
                }
            }
        }
        // Check columns
        for (int j = 0; j < 9; ++j) {
            unordered_map<char, int> colMap;
            for (int i = 0; i < 9; ++i) {
                char c = board[i][j];
                if (c != '.') {
                    if (colMap[c]++) return false;
                }
            }
        }
        // Check 3x3 sub-boxes
        for (int boxRow = 0; boxRow < 3; ++boxRow) {
            for (int boxCol = 0; boxCol < 3; ++boxCol) {
                unordered_map<char, int> boxMap;
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        int row = boxRow * 3 + i;
                        int col = boxCol * 3 + j;
                        char c = board[row][col];
                        if (c != '.') {
                            if (boxMap[c]++) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
