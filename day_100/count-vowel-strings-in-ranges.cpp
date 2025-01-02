class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    bool isVowelString(const string& s) {
        return isVowel(s.front()) && isVowel(s.back());
    }

    vector<int> vowelStrings(const vector<string>& words, const vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefixSum(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + (isVowelString(words[i]) ? 1 : 0);
        }

        vector<int> result;
        for (const auto& query : queries) {
            int l = query[0], r = query[1];
            result.push_back(prefixSum[r + 1] - prefixSum[l]);
        }

        return result;
    }
};


