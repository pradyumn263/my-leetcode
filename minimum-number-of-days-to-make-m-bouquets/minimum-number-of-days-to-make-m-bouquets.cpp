class Solution {
public:
    
    int numberOfBouquets(vector<int> &nums, int currentDay, int currentIndex, int flowersLeft, int flowersNeeded) {
        if(currentIndex == nums.size() && flowersLeft == 0)
            return 1;
        
        if(currentIndex == nums.size())
            return 0;
        
        if(flowersLeft == 0) {
            return 1 + numberOfBouquets(nums, currentDay, currentIndex, flowersNeeded, flowersNeeded);
        }
        
        if (nums[currentIndex] <= currentDay) {
            return numberOfBouquets(nums, currentDay, currentIndex + 1, flowersLeft - 1, flowersNeeded);
        }
        
        if (nums[currentIndex] > currentDay) {
            return numberOfBouquets(nums, currentDay, currentIndex + 1, flowersNeeded, flowersNeeded);
        }
        return 0;
    }
    
    bool canMake(vector<int> &nums, int day, int count, int windowSize) {
        int res = numberOfBouquets(nums, day, 0, windowSize, windowSize);
        return count <= res;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int size = bloomDay.size();
        if (k * m > size)
            return -1;
        
        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());
        
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            
            if (canMake(bloomDay, mid, m, k)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        if (canMake(bloomDay, lo, m, k))
            return lo;
        
        return -1;
    }
};