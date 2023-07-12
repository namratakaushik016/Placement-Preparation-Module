class Solution {
public:
   bool isValid(vector<vector<char>>& board, int row, int col, char num) {
    // Check if num exists in the same row or column
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    // Check if num exists in the same 3x3 subgrid
    int subgridRow = (row / 3) * 3;
    int subgridCol = (col / 3) * 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[subgridRow + i][subgridCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudokuHelper(vector<vector<char>>& board) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (board[row][col] == '.') {
                for (char num = '1'; num <= '9'; ++num) {
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;

                        if (solveSudokuHelper(board)) {
                            return true;
                        }

                        board[row][col] = '.';  // backtrack
                    }
                }

                return false;  // no valid number found
            }
        }
    }

    return true;  // all cells are filled
}

void solveSudoku(vector<vector<char>>& board) {
    solveSudokuHelper(board);
}

    
};