class Solution {
public:
    int countLessThanEqualTo(vector<int> &nums, int n) {
        int res = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= n) {
                res++;
            }
        }
        return res;
    }
    
    int findDuplicate(vector<int>& nums) {
        int size = nums.size();
        
        int lo = 0;
        int hi = size - 1;
        
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            
            int count = countLessThanEqualTo(nums, mid);
            
            if (count > mid) {
               hi = mid; 
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};