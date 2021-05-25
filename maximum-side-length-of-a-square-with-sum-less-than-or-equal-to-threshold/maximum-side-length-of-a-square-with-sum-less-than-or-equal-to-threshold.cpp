// Binary Search Implementation
class Solution {
public:
    void computeMatrix(vector<vector<int>> &mat, vector<vector<int>> &presum) {
        int n = mat.size();
        int m = mat[0].size();
        
        for (int j = 0; j < m; j++) {
            presum[0][j] = mat[0][j];
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                presum[i][j] = mat[i][j] + presum[i-1][j];
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                presum[i][j] += presum[i][j-1];
            }
        }
    }
    
    int getSum(vector<vector<int>> &mat, int i1, int j1, int i2, int j2) {
        int res = mat[i2][j2];
        
        if (i1 > 0) {
            res -= mat[i1-1][j2];
        }
        
        if (j1 > 0) {
            res -= mat[i2][j1-1];
        }
        
        if (i1 > 0 && j1 > 0) {
            res += mat[i1-1][j1-1];
        }
        
        return res;
    }
    
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        if (n == 0)
            return 0;
        
        int m = mat[0].size();
        
        vector<vector<int>> presum(n, vector<int> (m, 0)); 
        computeMatrix(mat, presum);
        
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int lo = 0;
                int hi;
                if (m - j > n - i) {
                    hi = n - i - 1;
                } else {
                    hi = m - j - 1;
                }
                
                while(lo < hi) {
                    int mid = lo + (hi - lo + 1)/2;
                    
                    if (getSum(presum, i, j, i + mid, j + mid) <= threshold) {
                        lo = mid;
                    } else {
                        hi = mid - 1;
                    }
                }
                
                if (getSum(presum, i, j, i + lo, j + lo) <= threshold) {
                    res = max(res, lo + 1);
                }
            }
        }
        
        return res;
    }
};