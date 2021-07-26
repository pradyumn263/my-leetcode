class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> currset;
        combinationHelper(res, currset, 1, n, k);
        return res;
    }
  
    void combinationHelper(vector<vector<int>> &res, vector<int> &currset, int start, int sum, int k) {
        if (currset.size() > k)
            return;
        
        if (currset.size() == k) {
            if (sum == 0)
            {
                res.push_back(currset);
            }
            return;
        }
        
        if (sum <= 0)
            return;
        
        for (int i = start; i <= 9; i++) {
            currset.push_back(i);
            combinationHelper(res, currset, i+1, sum - i, k);
            currset.pop_back();
        }
    }
};