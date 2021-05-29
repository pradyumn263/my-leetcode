class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = nums1.size() - 1;
        int j = 0;
        
        int res = 0;
    
        for (j = nums2.size() - 1; j >= 0; j--) {
            int lo = 0;
            int hi = j < nums1.size() - 1 ? j : nums1.size() - 1;
            
            // first number <= nums2[j];
            while (lo < hi) {
                int mid = lo + (hi - lo)/2;
                if (nums1[mid] <= nums2[j]) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            
            if (nums1[lo] <= nums2[j]) {
                res = max(res, j - lo);
            }
        }
        
        return res;
    }
};