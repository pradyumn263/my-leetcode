class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> currset;
        sort(candidates.begin(), candidates.end());
        combinationHelper(res, candidates, currset, 0, target);
        return res;
    }
    
    void combinationHelper(vector<vector<int>> &res, vector<int> &nums, vector<int> &currset, int index, int target) {
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
        int tempIndex = index;
        while (tempIndex < nums.size() && nums[index] == nums[tempIndex])
            tempIndex++;
        combinationHelper(res, nums, currset, tempIndex, target);
        
        currset.push_back(nums[index]);
        combinationHelper(res, nums, currset, index+1, target - nums[index]);
        currset.pop_back();
        return;
    }
};