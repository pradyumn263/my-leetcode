class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        if (size < 3) {
            return {};
        }
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int i = 0;
        while (i < size - 2) {
            int lo = i + 1;
            int hi = size - 1;
            
            int target = -nums[i];
            
            while (lo < hi && lo < size && hi > 0 && hi > i) {
                if (nums[lo] + nums[hi] == target) {
                    res.push_back({nums[i], nums[lo], nums[hi]});
                    
                    lo++;
                    while(lo != size - 1 && lo < hi && nums[lo] == nums[lo - 1])
                        lo++;
                } else {
                    if (nums[lo] + nums[hi] > target) {
                        hi--;
                    } else {
                        lo++;
                    }
                }
            }
            
            i++;
            while (i < size - 2 && nums[i] == nums[i-1]) {
                i++;
            }
        } 
        
        return res;
    }
};