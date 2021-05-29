class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = 0;
        int lo = 0; 
        int hi = 0;
        
        int sum = 0;
        
        for (hi = 0; hi < nums.size(); hi++) {
            if (hi == lo) {
                sum += nums[hi];
            } else {
                if (nums[hi] > nums[hi-1]) {
                    sum+=nums[hi];
                    
                } else {
                    lo = hi;
                    sum = 0;
                    sum += nums[hi];
                }
            }
            res = max(res, sum);
        }
        return res;
    }
};