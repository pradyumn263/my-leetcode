class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res; 
        vector<int> currset;
        
        combineHelper(res, currset, k, n, 1);
        return res;
    }
    
    void combineHelper(vector<vector<int>> &res, vector<int> &currset, int k, int n, int start) {
        if (currset.size() > k)
            return;
        
        if (currset.size() == k) {
            res.push_back(currset);
            return;
        }
        
        for (int i = start; i <=n; i++) {
            currset.push_back(i);
            combineHelper(res, currset, k, n, i+1);
            currset.pop_back();
        }
    }
};