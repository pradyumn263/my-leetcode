class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int lo = 0, hi = 0, res = INT_MAX;
        
        for (hi = 0; hi < nums.size(); hi++) {
            target -= nums[hi];
            while (target <= 0) {
                res = min(res, hi - lo + 1);
                target += nums[lo];
                lo++;
            }
        }
        
        while (target <= 0 && lo < nums.size()) {
            res = min(res, hi - lo + 1);
            target += nums[lo];
            lo++;
        }
        if (res == INT_MAX)
            return 0;
        return res;
    }
};