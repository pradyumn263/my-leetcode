class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastOccur(26, 0);
        for (int i = 0; i < s.size(); i++) {
            lastOccur[s[i]-'a'] = i;
        }
        vector<int> res;
        int lo = 0, hi = 0, start = 0;;
        while (lo < s.size() && hi < s.size()) {
            hi = lastOccur[s[lo]-'a'];
            start = lo;
            while (lo < hi) {
                hi = max(hi, lastOccur[s[lo]-'a']);
                lo++;
            }
            
            res.push_back(lo - start + 1);
            lo++;
            start = lo;
        }
        return res;
        
    }
};