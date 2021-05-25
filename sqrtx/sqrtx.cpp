class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        
        if (x == 1)
            return 1;
        
        int lo = 0;
        int hi = x - 1;
        
        while (lo < hi) {
            int mid = lo + (hi - lo + 1)/2;
            
            long long int curr = (long long int) mid * (long long int)mid;
            
            if (curr <= x) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        
        return lo;
    }
};