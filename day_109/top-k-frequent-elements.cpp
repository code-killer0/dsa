class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto &num : nums) {
            mp[num]++;
        }

        vector<pair<int, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second; 
        });

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].first);
        }

        return ans;
    }
};
