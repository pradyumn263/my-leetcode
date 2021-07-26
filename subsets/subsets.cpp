class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> currSet;
        vector<vector<int>> res;
        
        subsetsHelper(nums, 0, currSet, res);
        return res;
    }
    
    void subsetsHelper(vector<int> &nums, int index, vector<int> &currSet, vector<vector<int>> &res) {
        if (index == nums.size()) {
            res.push_back(currSet);
            return;
        }
        
        // Exclude current element
        subsetsHelper(nums, index+1, currSet, res);
        // Include current element
        currSet.push_back(nums[index]);
        subsetsHelper(nums, index+1, currSet, res);
        currSet.pop_back();
        return;
    }
};