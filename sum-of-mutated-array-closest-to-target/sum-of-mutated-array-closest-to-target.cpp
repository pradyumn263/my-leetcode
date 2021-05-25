// Binary Search Implementation
class Solution {
public:
    
    int getSumOfArr(vector<int> &arr, int num) {
        int res = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            if(arr[i] > num) {
                res += num;
            } else {
                res += arr[i];
            }
        }
        
        return res;
    }
    
    int findBestValue(vector<int>& arr, int target) {
        int res = INT_MAX;
        int currDiff = INT_MAX;
        
        int lo = 0;
        int hi = *max_element(arr.begin(), arr.end());
        
        while (lo < hi) {
            int mid = lo + (hi - lo + 1)/2;
            
            int currSum = getSumOfArr(arr, mid);
            int temp = abs(target - currSum);
            
            if (temp < currDiff) {
                currDiff = temp;
                res = mid;
            }
            
            if (currSum < target) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        
        if (abs(target - getSumOfArr(arr, lo + 1)) < abs(target - getSumOfArr(arr, lo)))
            return lo + 1;
        
        return lo;
        
    }
};