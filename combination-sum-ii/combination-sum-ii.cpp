class Solution {
public:
    // Check Commit history for another implementation
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> currset;
        sort(candidates.begin(), candidates.end());
        combinationHelper(res, candidates, currset, 0, target);
        return res;
    }
    
    void combinationHelper(vector<vector<int>> &res, vector<int> &nums, vector<int> &currset, int index, int target) {
        if (target == 0) {
            res.push_back(currset);
            return;
        }
        
        if (target < 0 || index >= nums.size())
            return;
        
        for (int i = index; i < nums.size(); i++) {
            if (i != index && nums[i] == nums[i-1]) continue;
            
            currset.push_back(nums[i]);
            combinationHelper(res, nums, currset, i+1, target-nums[i]);
            currset.pop_back();
        }
    }
};