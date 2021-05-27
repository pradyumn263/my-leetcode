class Solution {
public:
    
    void swap(vector<int> &nums, int i1, int i2) {
        int temp = nums[i1];
        nums[i1] = nums[i2];
        nums[i2] = temp;
        return;
    }
    
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        
        if (nums.size() == 2) {
            if (nums[0] > nums[1]) {
                swap(nums, 0, 1);
            }
            return;
        }
        
        int lo = 0; int hi = nums.size() - 1;
        int i = 0;
        while(i <= hi) {
            if (nums[i] == 0) {
                swap(nums, lo, i);
                if (lo == i)
                    i++;
                lo++;
            } else if (nums[i] == 1) {
                i++;
            } else {
                swap(nums, hi, i);
                hi--;
            }
        }        
    }
};