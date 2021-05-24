class Solution {
public:
    
    int binarySearch(vector<int> &nums, int start, int end, int target) {
        int lo = start;
        int hi = end;
        if (lo == hi) {
            if (nums[lo] == target) {
                return lo;
            }
            return -1;
        }
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            
            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        if (nums[lo] == target) {
            return lo;
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
        int size = nums.size();
        if (size == 0) {
            return -1;
        }
        
        if (size == 1) {
            return nums[0] == target ? 0 : -1;
        }
        
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
        
        if (nums[lo] > nums[0]) {
            lo = 0;
        }
        
        if (lo == 0) {
            return binarySearch(nums, lo, size-1, target);
        }
        
        if (target >= nums[0]) {
            return binarySearch(nums, 0, lo - 1, target);
        }
        
        return binarySearch(nums, lo, size - 1, target);
    }
};