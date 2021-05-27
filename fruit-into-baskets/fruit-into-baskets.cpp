class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int res = 0;
        vector<int> count(50000, 0);
        int countDiff = 0;
        
        int lo = 0; int hi = 0;
        
        while (hi < tree.size()) {
            if (count[tree[hi]] == 0 && countDiff == 2)
                break;
            
            if (count[tree[hi]] == 0) {
                countDiff++;
            }
            count[tree[hi]]++;
            hi++;
        }
        
        res = hi;
        
        while (hi < tree.size()) {
            if (count[tree[hi]] == 0) {
                countDiff++;
            }
            count[tree[hi]]++;
            hi++;
            while(countDiff > 2) {
                count[tree[lo]]--;
                if (count[tree[lo]] == 0) {
                    countDiff--;
                }
                lo++;
            }
            
            res = max(res, hi - lo);
        }
        
        if (countDiff <= 2) {
            res = max(res, hi - lo);
        }
        return res;
    }
};