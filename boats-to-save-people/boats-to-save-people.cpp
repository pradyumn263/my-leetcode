class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int total = accumulate(people.begin(), people.end(), 0);
        int shipped = 0;
        int hi = people.size() - 1;
        int lo = 0;
        int res = 0;
        
        while (lo < hi) {
            if (people[lo] + people[hi] > limit) {
                shipped+=people[hi];
                hi--;
                res++;
                continue;
            }
            shipped += (people[lo] + people[hi]);
            lo++;
            hi--;
            res++;
        }
        
        if (shipped < total) {
            res++;
        }
        return res;
    }
};