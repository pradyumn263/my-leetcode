/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

// Binary Search Implementation
class Solution {
public:
    
    bool nextElementIsLarger(int ind, MountainArray &nums) {
        int size = nums.length();
        
        if (ind == size - 1)
            return false;
        
        return nums.get(ind) < nums.get(ind + 1);
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int size = mountainArr.length();
        
        int lo = 0;
        int hi = size - 1;
        
        
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            
            if (nextElementIsLarger(mid, mountainArr)) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        int peakIndex = lo;
        
        lo = 0;
        hi = peakIndex;
        while(lo < hi) {
            int mid = lo + (hi - lo)/2;

            if (mountainArr.get(mid) < target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        if (mountainArr.get(lo) == target) {
            return lo;
        }
        
        lo = peakIndex;
        hi = size-1;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1)/2;

            if (mountainArr.get(mid) < target) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }

        if (mountainArr.get(lo) == target) {
            return lo;
        }
        
        return -1;
    }
};