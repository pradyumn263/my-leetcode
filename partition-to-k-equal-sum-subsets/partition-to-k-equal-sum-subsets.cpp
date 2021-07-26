class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int requiredSum = totalSum/k;
        vector<bool> visited(nums.size(), false);
        int maxNum = *max_element(nums.begin(), nums.end());
        if (totalSum % k != 0 || maxNum > requiredSum)
            return false;
       
        return canPartition(nums, visited, requiredSum, requiredSum, k, 0);
        
    }
    
    bool canPartition(vector<int> &nums, vector<bool> &visited, int currsum, int requiredSum, int k, int start) {
        if (k == 0 && allVisited(visited)) {
            return true;
        }
        
        if (currsum < 0)
            return false;
        
        if (currsum == 0) {
            return canPartition(nums, visited, requiredSum, requiredSum, k - 1, 0);
        }
        
        for (int i = start; i < nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                bool ans = canPartition(nums, visited, currsum - nums[i], requiredSum, k, i + 1);
                if (ans)
                    return true;
                visited[i] = false;
            }
        }
        return false;
    }
    
    bool allVisited(vector<bool> &visited) {
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i])
                return false;
        }
        return true;
    }
    
    
};