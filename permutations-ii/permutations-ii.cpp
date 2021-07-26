class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> currset;
        vector<bool> visited(nums.size(), false);
        
        sort(nums.begin(), nums.end());
        permutationHelper(nums, res, currset, visited);
        return res;
    }
    
    void permutationHelper(vector<int> &nums, vector<vector<int>> &res, vector<int> &currset, vector<bool> &visited) {
        if (allVisited(visited)) {
            res.push_back(currset);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i-1] && !visited[i-1])
                continue;
            
            if (!visited[i]) {
                visited[i] = true;
                currset.push_back(nums[i]);
                
                permutationHelper(nums, res, currset, visited);
                visited[i] = false;
                currset.pop_back();
            }
        }
    }
    
    bool allVisited(vector<bool> &visited) {
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i])
                return false;
        }
        return true;
    }
};