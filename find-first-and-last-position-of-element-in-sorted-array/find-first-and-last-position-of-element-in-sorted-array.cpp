class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        
        if (size == 0) {
            return {-1, -1};
        }
        
        int lo = 0;
        int hi = size - 1;
        
        vector<int> res;
        
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        if (nums[lo] != target) {
            return {-1, -1};
        }
        
        res.push_back(lo);
        
        lo = 0;
        hi = size - 1;
        
        while (lo < hi) {
            int mid = lo + (hi - lo + 1)/2;
            if (nums[mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }
        
        res.push_back(lo);
        return res;
    }
};