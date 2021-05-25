class Solution {
public:
    
    bool canTravel(vector<int> &nums, double hour, int speed) {
        double res = 0;

        for (int i = 0; i < nums.size(); i++) {
            double a;
            if (i == nums.size() - 1) {
                a = (double) nums[i]/(double) speed;
            } else {
                a = ceil((double) nums[i]/(double) speed);
            }
            res += a;
        }
        return res <= hour;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int size = dist.size();
        if (size - 1 > floor(hour))
            return -1;
        
        int lo = 1;
        int hi = 10000000;
        
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            
            if(canTravel(dist, hour, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        if (canTravel(dist, hour, lo))
            return lo;
        
        return -1;
    }
};