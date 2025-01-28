class Solution {
public:
    int minimumLength(string s) {
        int ans = 0;
        unordered_map<char,int>mp;
        for(auto a: s){
            mp[a]++;
        }  
        for(auto a:mp){
          if(a.second % 2 == 0){
            ans += 2;
          }  
          else{
            ans += 1;
          }
        }
        return ans;
    }
};