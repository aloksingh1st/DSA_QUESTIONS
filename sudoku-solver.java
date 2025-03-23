class Solution {
    public void solveSudoku(char[][] board) {
        int[][] row = new int[9][9];
        int[][] col = new int[9][9];
        int[][] box = new int[9][9];

        // Initialize tracking arrays based on the current board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int val = board[i][j] - '0';
                int boxIndex = (i / 3) * 3 + j / 3;
                row[i][val - 1] = 1;
                col[j][val - 1] = 1;
                box[boxIndex][val - 1] = 1;
            }
        }

        // Start backtracking to solve the Sudoku
        find(board, row, col, box, 0);
    }

    private boolean find(char[][] board, int[][] row, int[][] col, int[][] box, int index) {
        if (index == 81) {
            return true;
        }
        int r = index / 9;
        int c = index % 9;

        if (board[r][c] != '.') {
            return find(board, row, col, box, index + 1);
        }

        int boxIndex;
        for (int i = 0; i < 9; i++) {
            boxIndex = (r / 3) * 3 + c / 3;
            if (row[r][i] == 0 && col[c][i] == 0 && box[boxIndex][i] == 0) {
                board[r][c] = (char) ('0' + i + 1);
                row[r][i] = 1;
                col[c][i] = 1;
                box[boxIndex][i] = 1;
                if (find(board, row, col, box, index + 1)) {
                    return true;
                }
                board[r][c] = '.';
                row[r][i] = 0;
                col[c][i] = 0;
                box[boxIndex][i] = 0;
            }
        }
        return false;
    }
}