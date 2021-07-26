class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currset;
        vector<vector<int>> res;
        
        combinationHelper(candidates, target, currset, 0, res);
        return res;
    }
    
    void combinationHelper(vector<int> &nums, int target, vector<int> &currset, int index, vector<vector<int>> &res) {
        if (index == nums.size()) {
            if (target == 0)
                res.push_back(currset);
            return;
        }
        
        if (target == 0) {
            res.push_back(currset);
            return;
        }
        
        if (target < 0)
            return;
        
        // Exclude this element
        combinationHelper(nums, target, currset, index+1, res);
        
        // Include this element
        currset.push_back(nums[index]);
        combinationHelper(nums, target - nums[index], currset, index, res);
        currset.pop_back();
        return;
    }
}; 