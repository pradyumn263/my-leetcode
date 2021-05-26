class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        
        sort(nums.begin(), nums.end());
        int res = 100000;
        int i = 0;
        while (i < size - 2) {
            int lo = i + 1;
            int hi = size - 1;
            
            int t = target - nums[i];
            
            while (lo < hi) {
                if (nums[lo] + nums[hi] == t)
                    return target;
                
                if (abs(res - target) > abs((nums[lo] + nums[hi] + nums[i]) - target)) {
                    res = nums[lo] + nums[i] + nums[hi];
                }
                
                if (nums[lo] + nums[hi] > t) {
                    hi--;
                } else {
                    lo++;
                }
            }
            
            i++;
        }
        return res;
    }
};