class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
        int size = s.size();
        
        if (size == 0)
            return 0;
        if (size == 1) 
            return 1;
        
        int i = 0; int j = 0;
        int res = 0;
        
        map<char, int> freq;
        
        while (i < size && freq[s[i]] == 0) {
            freq[s[i]]++;
            i++;
        }
        
        res = i;
        
        while (i < size) {
            while (j < i && freq[s[i]] == 1) {
                freq[s[j]]--;
                j++;
            }
            
            freq[s[i]]++;
            res = max(res, i - j + 1);
            
            i++;
        }
        
        return res;
    }
};