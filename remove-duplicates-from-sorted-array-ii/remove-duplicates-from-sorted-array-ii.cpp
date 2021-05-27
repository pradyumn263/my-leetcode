class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        
        if (size <= 1)
            return size;
        
        int i = 0, j = 0;
        
        while (i < size && j < size) { 
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            
            j++;
            
            if (j < size && nums[i] == nums[j]) {
                i++;
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j++;
            }
            // Make j go to next new number.
            while (j < size && nums[i] == nums[j])
                j++;
            // Make i go to next place for new number.
            i++;
        }
        return i;
    }
};