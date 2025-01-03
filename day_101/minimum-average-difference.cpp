#include <bits/stdc++.h>
using namespace std;

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
    int minimumAverageDifference(vector<int>& nums) {
        long long start_sum = 0, end_sum = findSum(nums, nums.size());
        int n = nums.size();
        int ans = -1, min_diff = INT_MAX;

        for (int i = 0; i < n; i++) {
            start_sum += nums[i];
            end_sum -= nums[i];
            
            long long left_avg = start_sum / (i + 1);
            long long right_avg = (i == n - 1) ? 0 : end_sum / (n - i - 1);

            int diff = abs(left_avg - right_avg);

            if (diff < min_diff) {
                min_diff = diff;
                ans = i;
            }
        }

        return ans;
    }
};
