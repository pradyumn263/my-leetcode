class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int i = 0;
        int j = m-1;
        
        while (i >= 0 && j >= 0 && i < n && j < m) {
            if (i >= 0 && j >= 0 && i < n && j < m && matrix[i][j] == target)
                return true;
            
            if (i >= 0 && j >= 0 && i < n && j < m && matrix[i][j] > target) {
                j--;
            }
            
            if (i >= 0 && j >= 0 && i < n && j < m && matrix[i][j] < target) {
                i++;
            }
        }
        
        return false;
    }
};