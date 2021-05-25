class Solution {
public:
    
    bool canMake(vector<int> &nums, int day, int count, int windowSize) {
        // Basically Sliding Maximum
        int lo = 0;
        int hi = 0;
        
        int res = 0;
        
        deque<int> dq;
        
        while (hi < windowSize) {
            while(!dq.empty() && dq.back() < nums[hi])
                dq.pop_back();
            
            dq.push_back(nums[hi]);
            hi++;
        }
        
        while(hi < nums.size()) {
            if(dq.front() <= day) {
                res++;
                
                while(!dq.empty())
                    dq.pop_front();
                
                lo = hi;
                 while (hi < lo + windowSize && hi < nums.size()) {
                    while(!dq.empty() && dq.back() < nums[hi])
                        dq.pop_back();

                    dq.push_back(nums[hi]);
                    hi++;
                }
                
                if (hi - lo < windowSize) {
                    return res >= count;
                }
                
                continue;
            }
            
            while(!dq.empty() && dq.back() < nums[hi])
                dq.pop_back();
            
            if(!dq.empty() && dq.front() == nums[lo])
                dq.pop_front();
            
            dq.push_back(nums[hi]);
            lo++;
            hi++;
        }
        
        if(dq.front() <= day) {
            res++;
        }
        
        return res >= count;
        
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int size = bloomDay.size();
        if (k * m > size)
            return -1;
        
        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());
        
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            
            if (canMake(bloomDay, mid, m, k)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        if (canMake(bloomDay, lo, m, k))
            return lo;
        
        return -1;
    }
};