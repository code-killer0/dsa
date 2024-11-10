class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int s = nums.size();
        int ans = INT_MAX;

        for(int i = 0;i<s;i++){
            int result = 0;
            for(int j = i;j<s;j++){
                result = result|nums[j];
                if(result >= k){
                    ans = min(ans,j-i+1);
                }
            }
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};
