class Solution {
public:
    
    int f(string &s) {
        if(s.size() == 0) {
            return 0;
        }
        if (s.size() == 1)
            return 1;
        
        sort(s.begin(), s.end());
        int res = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i-1] == s[i])
                res++;
            else 
                break;
        }
        return res;
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