class Solution {
public:
    bool canEat(vector<int> &nums, int speed, int limit) {
       int res = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < speed) {
                res++;
            } else {
                res += nums[i]/speed;
                
                if (nums[i] % speed) {
                    res++;
                }
            }
            
        }
        
        return res <= limit;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int size = piles.size();
        
        if (size == 1) {
            if (h > piles[0])
                return 1;
            
            else {
                return ceil((double) piles[0]/ (double) h);
            }
        }
        
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());
        
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            
            if (canEat(piles, mid, h)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
};