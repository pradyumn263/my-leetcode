class Solution {
public:
    
    int getDivisionSum(vector<int> &nums, int n) {
        int size = nums.size();
        
        int res = 0;
        for (int i = 0; i < size; i++) {
            res += ceil((double) nums[i]/ (double) n);
        }
        
        return res;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int size = nums.size();
        
        int lo = 1;
        int hi = *max_element(nums.begin(), nums.end());
        
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            
            if (getDivisionSum(nums, mid) > threshold) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
        
    }
};