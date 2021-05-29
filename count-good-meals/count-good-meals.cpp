class Solution {
public:
    int countPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            
            for (int j = 0; j < 22; j++) {
                int k = 1 << j;
                if (mp.find(k-nums[i]) != mp.end()) {
                    count += mp[k-nums[i]];
                }
            }
            mp[nums[i]]++;
            res = (res%1000000007 + count%1000000007)%1000000007;
        }
        return res;
    }
};