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
        
        sort(worker.begin(), worker.end(), [&](int a, int b) {
            return a > b;
        });
        
        int i = 0;
        int j = 0;
        
        while (i < worker.size() && j < nums.size()) {
            if (worker[i] < nums[j].second) {
                j++;
                continue;
            }
            
            if (j < nums.size()) {
                res+= nums[j].first;
                i++;
            }
        }
        
        while (i < worker.size()) {
            if (worker[i] >= nums[j-1].second) {
                res+=nums[j-1].first;
                i++;
            } else {
                break;
            }
        }
        return res;
    }
};