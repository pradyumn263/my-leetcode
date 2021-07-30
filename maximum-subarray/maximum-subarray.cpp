class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = max(nums[i], nums[i] + nums[i-1]);
            res = max(res, nums[i]);
        }
        return res;
    }
};