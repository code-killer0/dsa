class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        sort(nums.begin(),nums.end());
        int cnt=0,longest=1;
        int lastSmallest=INT_MIN;
        for(int i =0;i<nums.size();i++){
            if(nums[i]-1==lastSmallest){
                cnt+=1;
                lastSmallest=nums[i];
            }
            else if (lastSmallest!=nums[i]){
                cnt =1;
                lastSmallest = nums[i];
            }
            longest = max(longest,cnt);
        }
        return longest;
    }
};