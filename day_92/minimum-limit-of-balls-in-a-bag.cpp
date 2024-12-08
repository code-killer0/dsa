class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        auto canDivide = [&](int maxSize) {
            int operations = 0;
            for (int num : nums) {
                if (num > maxSize) {
                    operations += (num - 1) / maxSize; // Calculate required operations
                }
                if (operations > maxOperations) {
                    return false;
                }
            }
            return true;
        };

        int left = 1, right = *max_element(nums.begin(), nums.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDivide(mid)) {
                result = mid;
                right = mid - 1; // Try smaller sizes
            } else {
                left = mid + 1; // Try larger sizes
            }
        }

        return result;
    }
};
