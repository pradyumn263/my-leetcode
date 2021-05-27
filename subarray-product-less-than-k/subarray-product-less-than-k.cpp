class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int size = nums.size();
        
        int hi = 0;
        int lo = 0;
        
        long long int currProduct = 1;
        int res = 0;
        
        while (hi < size) {
            if (currProduct * nums[hi] < k) {
                currProduct*= nums[hi];
                hi++;
                
                res += (hi - lo);
            } else {
                break;
            }
        }
        
        while (hi < size) {
            currProduct*= nums[hi];
            hi++;
            
            while(currProduct >= k && lo < hi) {
                currProduct /= nums[lo];
                lo++;
            }
            
            res += (hi - lo);
        }
        
        return res;
        
    }
};