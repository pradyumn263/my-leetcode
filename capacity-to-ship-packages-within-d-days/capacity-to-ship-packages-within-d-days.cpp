class Solution {
public:
    int daysToShip(vector<int> &nums, int minWeight) {
        int res = 0;
        int currentCapacity = minWeight;
        
        
        for (int i = 0; i < nums.size(); i++) {
            if (currentCapacity == 0) {
                res++;
                currentCapacity = minWeight;
            }
            
            if (currentCapacity >= nums[i]) {
                currentCapacity -= nums[i];
            } else {
                res++;
                currentCapacity = minWeight;
                currentCapacity -= nums[i];
            }
        }
        if (currentCapacity != minWeight)
            res++;
        return res;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int size = weights.size();
        
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);
        
        int res = hi;
        
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            
            int d = daysToShip(weights, mid);
            if (d > days) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        return lo;
    }
};