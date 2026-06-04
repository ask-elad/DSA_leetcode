class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {

        int r = row;
        int c = col;

        while (c >= 0) {
            if (board[r][c] == 'Q') return false;
            c--;
        }

        r = row;
        c = col;

        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r--;
            c--;
        }

        r = row;
        c = col;

        while (r < n && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r++;
            c--;
        }

        return true;
    }

    void nQueen(int col, vector<string>& board, int& cnt) {

        if (col == board.size()) {
            cnt++;
            return;
        }

        for (int row = 0; row < board.size(); row++) {

            if (isSafe(row, col, board, board.size())) {

                board[row][col] = 'Q';
                nQueen(col + 1, board, cnt);
                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {

        vector<string> board(n, string(n, '.'));
        int cnt = 0;

        nQueen(0, board, cnt);

        return cnt;
    }
};