class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0)
            return true;
        
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0])
                {
                    bool a = check(board, word, visited, i, j, 0);
                    if (a)
                        return true;
                }
            }
        }
        
        return false;
    }
    
    bool check(vector<vector<char>> &board, string &word, vector<vector<bool>> &visited, int row, int col, int index) {
        if (index == word.size())
            return true;
        
        if (row < 0 || col < 0 || row >= board.size() || col >= board[row].size() || visited[row][col]) 
            return false;
        
        if (board[row][col] != word[index])
            return false;
        visited[row][col] = true;
        bool ans =  check(board, word, visited, row + 1, col, index + 1) || check(board, word, visited, row - 1, col, index + 1) || check(board, word, visited, row, col + 1, index + 1) || check(board, word, visited, row, col - 1, index + 1);
        visited[row][col] = false;
        return ans;
    }
};