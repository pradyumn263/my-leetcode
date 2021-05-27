// Number of Subarrays with goal 1's
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       if (goal > nums.size())
           return 0;
        
        vector<pair<int,int>> zcount(nums.size(), {0,0});
        int lastOneCount = nums.size()-1;
        
        for (int i = nums.size()-1; i >= 0; i--) {
            if (nums[i] == 1) {
                lastOneCount = i;
                continue;
            } else {
                zcount[i].first = lastOneCount-i;
                zcount[i].second = lastOneCount;
            }
        }
        
        int res = 0;
        
        int hi = 0, lo = 0;
        int count = 0;
        
        while(hi < nums.size() && count <= goal) {
            
            if (nums[hi])
                count++;
            hi++;
            if(count == goal)
                break;
        }
        
        if(count < goal)
            return 0;
        if(count == goal && zcount[lo].second == zcount[hi-1].second) {
            res += 1 + (zcount[lo].first - zcount[hi-1].first);
        } else if(count == goal && zcount[lo].second < hi - 1) {
            res+= 1 + zcount[lo].first;
        } else if (count == goal) {
            res++;
        }
        while(hi < nums.size()) {
            if(nums[hi])
                count++;
            hi++;
            
            while(lo < hi && count > goal) {
                if(nums[lo])
                    count--;
                lo++;
            }
            if (lo == hi)
                continue;
            if(lo < nums.size() && zcount[lo].second == zcount[hi-1].second) {
                res += 1 + zcount[lo].first - zcount[hi-1].first;
            } else if(lo < nums.size() && zcount[lo].second < hi - 1) {
                res+=1 + zcount[lo].first;
            } else {
                if (hi < nums.size() && lo < nums.size() && count == goal)
                    res++;
            }
            cout << "HI: " << hi << " LO: " << lo << " RES: " << res << "\n";
        }
        
        return res;
        
    }
};