class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        
        if (size < 4) {
            return {};
        }
        sort(nums.begin(), nums.end());
        int i = 0;
        
        vector<vector<int>> res;
        
        while (i < size - 3) {
            int j = i + 1;
            while (j < size - 2) {
                int lo = j + 1;
                int hi = size - 1;
                
                int t = target - nums[i] - nums[j];
                
                while (lo < hi) {
                    if (nums[lo] + nums[hi] == t) {
                        res.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                        
                        lo++;
                        while (lo < size && nums[lo] == nums[lo - 1]) {
                            lo++;
                        }
                    } else {
                        if (nums[lo] + nums[hi] > t) {
                            hi--;
                        } else {
                            lo++;
                        }
                    }
                }
                
                j++;
                while (j < size && nums[j] == nums[j-1]) {
                    j++;
                }
            }
            i++;
            
            while(i < size && nums[i] == nums[i-1]){
                i++;
            }
        }
        
        return res;
    }
};