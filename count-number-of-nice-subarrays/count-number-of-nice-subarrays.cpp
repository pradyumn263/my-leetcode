class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
    
    int atMost(vector<int> &nums, int k) {
        if (k < 0)
            return 0;
        
        int lo = 0, hi = 0, res = 0;
        
        for (hi = 0; hi < nums.size(); hi++) {
            if (nums[hi]%2) {
                k--;
            }
            while(k < 0) {
                if (nums[lo]%2)
                    k++;
                lo++;
            }
            res+=(hi - lo + 1);
        }
        return res;
    }
};