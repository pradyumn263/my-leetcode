class Solution {
public:
    int minimumLength(string s) {
        int lo = 0, hi = s.size() - 1;
        
        while (1) {
            if (lo == hi)
                return 1;
            int currChar = s[lo];
            if (s[hi] != currChar)
                return hi - lo + 1;
            while (lo < hi) {
                if (s[lo] == currChar)
                    lo++;
                else break;
            }
            if (lo == hi)
                return 0;
            while (hi > lo) {
                if (s[hi] == currChar)
                    hi--;
                else break;
            }
        }
        
        return s.size();
    }
};