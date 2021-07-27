class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0);
        
        dp[nums.size() - 1] = nums[nums.size() - 1];
        
        for (int i = nums.size() - 2; i >= 0; i--) {
            dp[i] = max(nums[i] + dp[i+2], dp[i+1]);
        }
        return dp[0];
    }
};