class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int a = 0;
        for(int i = 0;i<s.size();i++){
            if(a < spaces.size() && i == spaces[a]){
                ans += " ";
                a++;
            }
            ans += s[i];
        }
        return ans;
    }
};