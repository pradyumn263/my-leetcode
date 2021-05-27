class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> nums;
        int res = 0;
        for (int i = 0; i < difficulty.size(); i++) {
            nums.push_back({profit[i], difficulty[i]});
        }
        
        sort(nums.begin(), nums.end(), [&](pair<int, int> &a, pair<int,int> &b) {
            if (a.first != b.first)
                return a.first > b.first;
            
            return a.second < b.second;
        });
        
        for (int i = 0; i < worker.size(); i++) {
            int j = 0;
            
            while(j < nums.size() && nums[j].second > worker[i])
                j++;
            
            if (j == nums.size())
                continue;
            
            else res += nums[j].first;
        }
        return res;
    }
};