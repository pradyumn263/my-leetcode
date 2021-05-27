class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
    
    int atMost(vector<int> &nums, int k) {
        if (k < 0)
            return 0;
        
        int lo = 0;
        int hi = 0;
        
        int count = 0;
        vector<int> freq(30000, 0);
        int res = 0;
        
        for(hi = 0; hi < nums.size(); hi++) {
            freq[nums[hi]]++;
            if(freq[nums[hi]] == 1)
                k--;
            
            while(k < 0) {
                freq[nums[lo]]--;
                if(freq[nums[lo]] == 0)
                    k++;
                lo++;
            }
            
            res+=(hi - lo + 1);
        }
        return res;
    }
};