class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> currset;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        subsetsHelper(nums, res, currset, 0);
        return res;
    }
    
    void subsetsHelper(vector<int> &nums, vector<vector<int>> &res, vector<int> &currset, int index) {
        if (index == nums.size()) {
            res.push_back(currset);
            return;
        }
        
        int tempIndex = index;
        while(tempIndex < nums.size() && nums[tempIndex] == nums[index]) {
            tempIndex++;
        }
        
        int count = tempIndex - index;
        for (int i = 0; i <= count; i++) {
            if (i)
                currset.push_back(nums[index]);
            subsetsHelper(nums, res, currset, tempIndex);
        }
        while (count--)
            currset.pop_back();
    }
};