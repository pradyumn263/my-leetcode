class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> currset(n, string(n, '.'));
        queenHelper(res, currset, 0);
        return res;
    }
    
    
    void queenHelper(vector<vector<string>> &res, vector<string> &currset, int col) {
        if (col == currset.size()) {
            res.push_back(currset);
            return;
        }
        
        for (int i = 0; i < currset.size(); i++) {
            if (!isAttacked(currset, i, col)) {
                currset[i][col] = 'Q';
                queenHelper(res, currset, col+1);
                currset[i][col] = '.';
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