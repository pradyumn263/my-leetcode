class Solution {
public:
    
    bool isSubseq(string &word, string &s) {
        if (word.size() > s.size())
            return false;
        
        int i = 0, j = 0;
        
        while (i < word.size() && j < s.size()) {
            if (word[i] == s[j]) {
                i++;
            }
            j++;
        }
        
        if (i == word.size())
            return true;
        return false;
    }
    
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [&](string &a, string &b) {
            if (a.size() != b.size()) {
                return a.size() > b.size();
            }
            
            if (a > b) {
                return false;
            }
            return true;
        });
        
        for (int i = 0; i < dictionary.size(); i++) {
            if (isSubseq(dictionary[i], s)) {
                return dictionary[i];
            }
        }
        return "";
    }
};