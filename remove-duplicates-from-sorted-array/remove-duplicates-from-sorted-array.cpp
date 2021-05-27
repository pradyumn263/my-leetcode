class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1)
            return size;
        
        int i = 0, j = 1;
        
        while (j < size) {
            while(j < size && nums[i] == nums[j])
                j++;
            
            if (j == size) {
                break;
            }
            
            i++;
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j++;
        }
        return i+1;
    }
};