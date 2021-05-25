class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        int lo = 0;
        int hi = size - 1;
        
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            
            if (nums[mid] < nums[0]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
            
        }
        if (nums[lo] < nums[0]) 
            return nums[lo];
        return nums[0];
    }
};