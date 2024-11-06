class Solution {
public:
    int countSetBits(int n) {
        int cnt = 0;
        while (n) {
            cnt += n & 1;
            n >>= 1;
        }
        return cnt;
    }

    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int flag = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (nums[j] > nums[j + 1]) {
                    flag = 1;
                    if (countSetBits(nums[j]) != countSetBits(nums[j + 1]))
                        return false;
                    swap(nums[j], nums[j + 1]);
                }
            }
            if (flag == 0)
                return true;
        }
        return true;
    }
};