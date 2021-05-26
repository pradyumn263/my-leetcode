class Solution {
public:
    
    int f(string &s) {
       int size = s.size();
        if (size == 0)
            return 0;
        
        if (size == 1) 
            return 1;
        
        vector<int> freq(26, 0);
        
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            if(freq[i] != 0)
                return freq[i];
        }
        return 0;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        if(queries.size() == 0)
            return {};
        
        int size = words.size();
        
        // Sort Words
        sort(words.begin(), words.end(), [&](string &a, string &b) {
            return f(a) < f(b);
        });
       
        vector<int> res;
        
        for(int i = 0; i < queries.size(); i++) {
            int lo = 0;
            int hi = words.size() - 1;
            
            while (lo < hi) {
                int mid = lo + (hi - lo)/2;
                
                if (f(queries[i]) < f(words[mid])) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            
            if (f(words[lo]) > f(queries[i])) {
                res.push_back(size - lo);
            } else {
                res.push_back(0);
            }
        }
        return res;
        
    }
};