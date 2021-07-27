class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        string currset;
        
        caseHelper(res, s, currset, 0);
        return res;
    }
    
    void caseHelper(vector<string> &res, string &s, string &currset, int index) {
        if (index == s.size()) {
            res.push_back(currset);
            return;
        }
        
        if (isalpha(s[index])) {
            currset.push_back(toupper(s[index]));
            caseHelper(res, s, currset, index+1);
            currset.pop_back();
            currset.push_back(tolower(s[index]));
            caseHelper(res, s, currset, index + 1);
            currset.pop_back();
        } else {
            currset.push_back(s[index]);
            caseHelper(res, s, currset, index + 1);
            currset.pop_back();
        }
    }
};