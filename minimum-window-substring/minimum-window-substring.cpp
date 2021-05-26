class Solution {
public:
    
    bool isSame(unordered_map<char, int> &a, unordered_map<char, int> &b) {
        for (auto it = b.begin(); it != b.end(); it++) {
            if (a[it->first] < it->second)
                return false;
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        if (s.size() < t.size())
            return "";
        
        unordered_map<char, int> tfreq;
        for (int i = 0; i < t.size(); i++) {
            tfreq[t[i]]++;
        }

        int startIndex = 0; int size = s.size();
        int lo = 0, hi = 0;
        
        unordered_map<char, int> currFreq;
        
        while (hi < s.size() && !isSame(currFreq, tfreq)) {
            currFreq[s[hi]]++;
            
            hi++;
        }
        
        if (!isSame(currFreq, tfreq))
            return "";
        
        while (hi < s.size()) {
            if (isSame(currFreq, tfreq)) {
                if (hi - lo < size) {
                    startIndex = lo;
                    size = hi - lo;
                }
            }
            
            while(isSame(currFreq, tfreq) && lo < hi) {
                if (hi - lo < size) {
                    startIndex = lo;
                    size = hi - lo;
                }
                currFreq[s[lo]]--;
                lo++;
            }
            
            currFreq[s[hi]]++;
            hi++;
        }
        
         
        while(isSame(currFreq, tfreq) && lo < hi) {
            if (hi - lo < size) {
                startIndex = lo;
                size = hi - lo;
            }
            currFreq[s[lo]]--;
            lo++;
        }
        
        
        return s.substr(startIndex, size);

    }
};