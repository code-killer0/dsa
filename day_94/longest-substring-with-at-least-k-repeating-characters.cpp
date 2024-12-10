class Solution {
public:
    int longestSubstring(string s, int k) {
        return helper(s, 0, s.size(), k);
    }

private:
    int helper(const string& s, int start, int end, int k) {
        if (end - start < k) return 0;
        map<char, int> freq;
        for (int i = start; i < end; i++) freq[s[i]]++;
        for (int i = start; i < end; i++) {
            if (freq[s[i]] < k) {
                int left = helper(s, start, i, k);
                int right = helper(s, i + 1, end, k);
                return max(left, right);
            }
        }
        return end - start;
    }
};
