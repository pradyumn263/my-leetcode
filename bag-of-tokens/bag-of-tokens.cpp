class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        
        if (tokens.size() == 0)
            return 0;
        
        int lo = 0, hi = tokens.size() - 1;
        int score = 0;
        int maxScore = 0;
        while (lo <= hi) {
            if (power < tokens[lo]) {
                if (score >= 1) {
                    power+= tokens[hi];
                    score--;
                    hi--;
                    continue;
                } else {
                    return maxScore;
                }
            
            }
            power -= tokens[lo];
            score++;
            maxScore = max(score, maxScore);
            lo++;            
        }
        
        return maxScore;
        
    }
};