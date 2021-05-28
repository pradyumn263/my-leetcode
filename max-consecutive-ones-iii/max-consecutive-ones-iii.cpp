class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        if (nums.size() <= k) {
            return nums.size();
        }
        
        int lo = 0, hi = 0, res = 0;
        
        for (hi = 0; hi < nums.size(); hi++) {
            if (nums[hi] == 0)
                k--;
            while(k < 0) {
                if (nums[lo] == 0) {
                    k++;
                }
                lo++;
            }
            res = max(res, hi - lo + 1);
        }
        return res;
    }
};