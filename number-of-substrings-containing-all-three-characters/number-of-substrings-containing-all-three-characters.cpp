class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        int lo = 0;
        int hi = 0;
        
        if (s.size() < 3) {
            return 0;
        }
        vector <int> count(3, 0);
        
        for (hi = 0; hi < s.size(); hi++) {
            count[s[hi]-'a']++;
            
            while(count[0] && count[1] && count[2]) {
                count[s[lo]-'a']--;
                lo++;
            }
            res += lo;
        }
        return res;
    }
};