class Solution {
public:
    
    bool isSame(vector<int> &a, vector<int> &b) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) {
            return false;
        }
        
        vector<int> f1(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            f1[s1[i]-'a']++;
        }
        
        int lo = 0;
        int hi = 0;
        vector<int> f2(26, 0);
        
        while(hi < s1.size()) {
            f2[s2[hi]-'a']++;
            hi++;
        }
        
        if (isSame(f1,f2))
            return true;
        
        while(hi < s2.size()) {
            f2[s2[hi]-'a']++;
            f2[s2[lo]-'a']--;
            
            if (isSame(f1,f2))
                return true;
            
            lo++;
            hi++;
        }
        
        return false;
    }
};