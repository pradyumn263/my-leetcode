// Number of Subarrays with goal 1's
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return atMost(nums, goal) - atMost(nums, goal-1);
    }
    
    int atMost(vector<int> &nums, int sum) {
        if (sum < 0)
            return 0;
        
        int lo = 0, hi = 0;
        int res = 0, curr = 0;
        
        while(hi < nums.size()) {
            if (nums[hi] + curr > sum)
                break;
            
            curr+=nums[hi];
            hi++;
            
            if (curr <= sum) {
                res+=hi;
            }
        }
        
        while (hi < nums.size()) {
            curr += nums[hi];
            hi++;
            
            while(curr > sum) {
                curr -= nums[lo];
                lo++;
            }
            if (curr <= sum) {
                res+= (hi - lo);
            }
        }
        
        return res;
    }
    
    
};