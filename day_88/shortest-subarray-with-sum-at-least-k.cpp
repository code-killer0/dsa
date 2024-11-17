class Solution {
public:
    int shortestSubarray(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<long long> prefix(n + 1, 0);
        
        // Step 1: Build the prefix sum array
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        // Step 2: Initialize a deque to store indices of the prefix sums
        std::deque<int> dq;
        int minLength = INT_MAX;
        
        // Step 3: Iterate over the prefix sums
        for (int i = 0; i <= n; ++i) {
            // Step 4: Check for valid subarrays
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                minLength = std::min(minLength, i - dq.front());
                dq.pop_front(); // Remove the front element
            }
            
            // Step 5: Maintain the deque to keep the indices in increasing order of prefix sums
            while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
                dq.pop_back(); // Remove elements from back if they are greater than or equal to the current prefix sum
            }
            
            dq.push_back(i); // Add the current index to the deque
        }
        
        // Step 6: Return the result
        return minLength == INT_MAX ? -1 : minLength;
    }
};