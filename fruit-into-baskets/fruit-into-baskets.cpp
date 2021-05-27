class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int res = 0;
        vector<int> count(50000, 0);
        int countDiff = 0;
        
        int lo = 0; int hi = 0;
        
        for (hi = 0; hi < tree.size(); hi++) {
            count[tree[hi]]++;
            if(count[tree[hi]] == 1) {
                countDiff++;
            }
            
            while (countDiff > 2) {
                count[tree[lo]]--;
                if (count[tree[lo]] == 0)
                    countDiff--;
                lo++;
            }
            
            res = max(res, (hi - lo + 1));
        }
        return res;
    }
};