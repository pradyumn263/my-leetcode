class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0)
            return false;
        
        int m = matrix[0].size();
        
        int i = 0;
        int j = m - 1;
        
        while (i < n && matrix[i][j] < target) {
            i++;
        }
        
        if (i == n)
            return false;
        
        while (j >= 0 && matrix[i][j] > target) {
            j--;
        }
        
        if (j < 0)
            return false;
        
        if (matrix[i][j] != target)
            return false;
        
        return true;
    }
};