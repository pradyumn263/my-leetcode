class Solution {
public:
    
    bool isPartitionAble(vector<int> &nums, int sum, int m) {
        int count = 1;
        
        int currTotal = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            currTotal += nums[i];
            
            if (currTotal > sum) {
                count++;
                currTotal = nums[i];
                
                if (count > m)
                    return false;
            }
        }
        
        return true;
    }
    
    
    
    int splitArray(vector<int>& nums, int m) {
        int size = nums.size();
        
        if (size == 0)
            return 0;
        
        int lo = *max_element(nums.begin(), nums.end());
        int hi = accumulate(nums.begin(), nums.end(), 0);
        
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            if (isPartitionAble(nums, mid, m)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
};