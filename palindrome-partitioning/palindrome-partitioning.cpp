class Solution {
public:
    bool isPal(string &s, int i, int j) {
        if (i == j)
            return true;
        if (i > j)
            return false;
        
        while (j > i) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<string> currset;
        vector<vector<string>> res;
        partitionHelper(s, currset, res, 0);
        return res;
    }
    
    void partitionHelper(string &s, vector<string> &currset, vector<vector<string>> &res, int index) {
        if (index == s.size()) {
            res.push_back(currset);
            return;
        }
        
        for (int i = index; i < s.size(); i++) {
            if (isPal(s, index, i)) {
                currset.push_back(s.substr(index, i - index + 1));
                partitionHelper(s, currset, res, i + 1);
                currset.pop_back();
            }
        } 
            
        return;
    }
};