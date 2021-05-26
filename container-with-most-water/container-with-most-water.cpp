class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        
        int i = size - 1;
        int j = 0;
        
        if (size == 0 || size == 1) {
            return 0;
        }
        
        int res = 0;
        
        while (j < i) {
            int curr = (i - j) * min(height[i], height[j]);
            
            if (height[i] <= height[j]) {
                i--;
            } else {
                j++;
            }
            
            res = max(res, curr);
        }
        return res;
    }
};