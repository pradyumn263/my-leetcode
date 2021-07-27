class Solution {
public:
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int res = 0;
        queensHelper(board, res, 0);
        return res;
    }
    
    void queensHelper(vector<string> &board, int &res, int col) {
        if (col == board.size()) {
            res++;
            return;
        }
        
        for (int i = 0; i < board.size(); i++) {
            if (!isAttacked(board, i, col)) {
                board[i][col] = 'Q';
                queensHelper(board, res, col+1);
                board[i][col] = '.';
            }
        }
    }
    
    bool isAttacked(vector<string> &board, int row, int col) {
        // Check if something is there on the row.
        for (int j = 0; j < col; j++) {
            if (board[row][j] == 'Q')
                return true;
        }
        
        int i = row - 1, j = col - 1;
        
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q')
                return true;
            i--;
            j--;
        }
        
        i = row+1; j=col-1;
        
        while (j >= 0 && i < board.size()) {
            if (board[i][j] == 'Q')
                return true;
            i++;
            j--;
        }
        return false;
    }
};