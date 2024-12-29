class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> sums(n - k + 1, 0);
        int windowSum = 0;
        for (int i = 0; i < n; i++) {
            windowSum += nums[i];
            if (i >= k - 1) {
                sums[i - k + 1] = windowSum;
                windowSum -= nums[i - k + 1];
            }
        }

        vector<int> left(sums.size(), 0);
        int leftMaxIndex = 0;
        for (int i = 0; i < sums.size(); i++) {
            if (sums[i] > sums[leftMaxIndex]) {
                leftMaxIndex = i;
            }
            left[i] = leftMaxIndex;
        }

        vector<int> right(sums.size(), 0);
        int rightMaxIndex = sums.size() - 1;
        for (int i = sums.size() - 1; i >= 0; i--) {
            if (sums[i] >= sums[rightMaxIndex]) {
                rightMaxIndex = i;
            }
            right[i] = rightMaxIndex;
        }

   
        int maxSum = 0;
        vector<int> result(3);
        for (int mid = k; mid < sums.size() - k; mid++) {
            int l = left[mid - k], r = right[mid + k];
            int totalSum = sums[l] + sums[mid] + sums[r];
            if (totalSum > maxSum) {
                maxSum = totalSum;
                result = {l, mid, r};
            }
        }

        return result;
    }
};