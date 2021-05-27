class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int size = word.size();
        if (size < 5)
            return 0;
        
        string s = "aeiou";
        int start = 0, end = 0;
        int res = 0;
        int currInd = 0;
        int i = 0;
        while (i < word.size()) {
            start = i;
            bool completed = true;
            for (currInd = 0; currInd < s.size(); currInd++){
                if (word[i] != s[currInd]) {
                    if(currInd == 0)
                        i++;
                    completed = false;
                    break;
                }
                while(i < word.size() && word[i] == s[currInd])
                    i++;
            }
            
            if (i == word.size() && currInd != s.size()) {
                return res;
            }
            
            if(!completed) {
                continue;
            } else {
                res = max(res, i - start);
            }
        }
        return res;
    }
};