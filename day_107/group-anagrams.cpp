class Solution {
public:
    string generate(string& word) {
        int arr[26] = {0};
        for (char &ch : word) {
            arr[ch - 'a']++;
        }
        string new_word = "";

        for (int i = 0; i < 26; i++) {
            if (arr[i] > 0) {
                new_word += string(arr[i], i + 'a');
            }
        }
        return new_word;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        unordered_map<string, vector<string>> mp;
        vector<vector<string>> result;

        for (int i = 0; i < n; i++) {
            string new_word = generate(strs[i]);
            mp[new_word].push_back(strs[i]);
        }

        for (auto &it : mp) {
            result.push_back(it.second);
        }

        return result;
    }
};
