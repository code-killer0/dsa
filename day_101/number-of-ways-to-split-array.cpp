class Solution {
private:
    long long findSum(vector<int>& nums, int n) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        return sum;
    }

public:
    int waysToSplitArray(vector<int>& nums) {
        long long start_sum = 0, end_sum = findSum(nums, nums.size());
        int ans = 0, n = nums.size();

        for (int i = 0; i < n - 1; i++) { 
            start_sum += nums[i];
            end_sum -= nums[i];
            if (start_sum >= end_sum) {
                ans++;
            }
        }
        return ans;
    }
};
