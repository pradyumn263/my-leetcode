class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> currset;
        vector<bool> visited(nums.size(), false);
        
        permutationHelper(nums, res, visited, currset);
        return res;
        
    }
    
     void permutationHelper(vector<int> &nums, vector<vector<int>> &res, vector<bool> &visited, vector<int> currset) {
        if (currset.size() == nums.size()) {
            res.push_back(currset);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                currset.push_back(nums[i]);
                permutationHelper(nums, res, visited, currset);
                visited[i] = false;
                currset.pop_back();
            }
        }
    }
};