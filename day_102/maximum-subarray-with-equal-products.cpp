class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size(), ans = 0, maxi = 0, maxLCMPoss = 10000;
        for(int i = 0 ; i < n ; i++){
            int Gcd = nums[i], Lcm = nums[i], pro = 1;
            for(int j = i ; j < n ; j++){
                Gcd = __gcd(Gcd, nums[j]);
                Lcm = lcm(Lcm, nums[j]);
                pro *= nums[j];
                if(pro > maxLCMPoss)
                    break;
                if(pro == Gcd * Lcm)
                    maxi = max(maxi, j - i + 1);
            }
        }
        return maxi;
    }
};