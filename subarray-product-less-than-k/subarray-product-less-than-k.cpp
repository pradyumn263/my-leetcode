class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int size = nums.size();
        
        int hi = 0;
        int lo = 0;
        
        long long int currProduct = 1;
        int res = 0;
        
        for (hi = 0; hi < nums.size(); hi++) {
            currProduct *= nums[hi];
            while(lo <= hi && currProduct >= k) {
                currProduct /= nums[lo];
                lo++;
            }
            if (currProduct < k) {
                res += (hi - lo + 1);
            }
        }
        
        return res;
        
    }
};