class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
            return 0;
        
        if (size == 1) 
            return nums[0];
        
        if (size == 2) 
            return min(nums[1], nums[0]);
        
        int lo = 0;
        int hi = size - 1;
        
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            
            if (nums[mid] > nums[0]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        if (lo != size-1 && nums[lo] > nums[lo + 1]) {
            lo = lo + 1;
        }
        
        if (nums[lo] > nums[0]) {
            lo = 0;
        }
        return nums[lo];
    }
};