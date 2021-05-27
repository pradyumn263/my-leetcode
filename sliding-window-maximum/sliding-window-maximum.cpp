class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return {};
        if (k > nums.size())
            return {*max_element(nums.begin(), nums.end())};
        
        deque<int> dq;
        vector <int> res;
        int i = 0, j = 0;
        
        for (i = 0; i < k; i++) {
            while(!dq.empty() && dq.back() < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        
        while(i < nums.size()) {
            if (!dq.empty())
                res.push_back(dq.front());
            
            while(!dq.empty() && dq.back() < nums[i])
                dq.pop_back();
            dq.push_back(nums[i]);
            i++;
            if (!dq.empty() && dq.front() == nums[j])
                dq.pop_front();
            j++;
        }
        res.push_back(dq.front());
        return res;
    }
};