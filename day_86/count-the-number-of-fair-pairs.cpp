class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long ans = 0;
        sort(nums.begin(), nums.end());
        auto it = nums.begin() + 1;
        for(int i = 0; i < n - 1; ++i){
            int to_find_1 = lower - nums[i]; 
            int to_find_2 = upper - nums[i]; 
            auto it1 = lower_bound(it, nums.end(), to_find_1);
            auto it2 = upper_bound(it, nums.end(), to_find_2);
            ans += it2 - it1;
            it++;
        }
        return ans;
    }
};