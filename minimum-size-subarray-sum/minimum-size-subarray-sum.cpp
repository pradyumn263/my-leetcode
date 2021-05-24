class Solution {
public:
    
    int binarySearch(vector<int> &nums, int start, int end, int target) {
        int lo = start;
        int hi = end;
        
        if (hi <= lo) {
            return -1;
        }
        
        while (lo < hi) {
            int mid = lo + (hi - lo + 1)/2;
            
            if (nums[mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }
        if (nums[lo] <= target) {
            return lo;
        }
        
        return -1;
    }
    
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        int res = INT_MAX;
        if (size == 0)
            return 0;
        
        if (size == 1) {
            if (nums[0] == target)
                return 1;
            return 0;
        }
    
        for (int i = 1; i < size; i++) {
            nums[i] += nums[i-1];
        }
        
        for (int i = 0; i < size; i++) {
            int toFind = nums[i] - target;
            if (toFind == 0) {
                res = min(res, i + 1);
                continue;
            }
            
            if (nums[i] >= target) {
                res = min(res, i + 1);
            }
        
            int ind = binarySearch(nums, 0, i - 1, toFind);
            if (ind == -1)
                continue;
            res = min(res, i - ind);
        }
        
        if (res == INT_MAX)
            return 0;
        
        return res;
    }
};