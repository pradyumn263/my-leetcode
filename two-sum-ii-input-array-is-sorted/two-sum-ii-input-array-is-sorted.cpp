class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        
        if (size == 0) {
            return {};
        }
        
        int lo = 0;
        int hi = size - 1;
        
        while (lo < hi) {
            if (nums[lo] + nums[hi] > target) {
                hi--;
                continue;
            }
            
            if (nums[lo] + nums[hi] < target) {
                lo++;
                continue;
            }
            
            if (nums[lo] + nums[hi] == target) {
                return {lo + 1, hi + 1};
            }
        }
        return {lo + 1, hi + 1};
    }
};