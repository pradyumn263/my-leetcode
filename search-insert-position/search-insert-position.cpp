class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        int lo = 0;
        int hi = size - 1;
        
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            
            if (target > nums[mid]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        if (nums[lo] >= target)
            return lo;
        
        return lo + 1;
    }
};