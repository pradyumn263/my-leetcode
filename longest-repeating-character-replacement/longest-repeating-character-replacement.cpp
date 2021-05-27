class Solution {
public:
    
    int getMaxCharCount(vector<int> &nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res = max(nums[i], res);
        }
        return res;
    }
    
    int characterReplacement(string s, int k) {
        int size = s.size();
        
        if (size <= k) {
            return size;
        }
        
        vector<int> freq(26, 0);
        int res = 0;
        int hi = 0, lo = 0;
       
        while (hi < size) {
            int maxFreq = getMaxCharCount(freq);
            if (maxFreq > (hi - lo) - k) {
                freq[s[hi]-'A']++;
                hi++;
            } else if (maxFreq == (hi - lo) - k) {
                if (freq[s[hi]-'A'] == maxFreq) {
                    freq[s[hi]-'A']++;
                    hi++;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
       
        res = hi;
        if (hi == size) {
            if (getMaxCharCount(freq) >= (hi - lo) - k)
                return hi;
            else return 0;
        }
       
        while (hi < size) {
            freq[s[hi]-'A']++;
            hi++;
            while (lo < size && lo < hi && getMaxCharCount(freq) < hi - lo - k) {
               
                freq[s[lo]-'A']--;
                lo++;
            }
            
            res = max(res, hi - lo);
        }
    
        while(lo < size && lo < hi && getMaxCharCount(freq) < hi - lo - k) {
            freq[s[lo]-'A']--;
            lo++;
        }
        
        res = max(res, hi - lo);
        
        return res;
        
    
    }
};