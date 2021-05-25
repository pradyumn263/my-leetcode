class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        
        if (size == 0)
            return 0;
        
        int lo = 0;
        int hi = size - 1;
        
        while (lo < hi - 1) {
            int mid = lo + (hi - lo)/2;
            int mid1 = mid + 1;
            
            if (nums[mid] > nums[mid1]) {
                hi = mid;
            } else {
                lo = mid1;
            }
        }
        
        return nums[lo] > nums[hi] ? lo : hi;
    }
};