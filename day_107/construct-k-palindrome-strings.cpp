class Solution {
public:
    bool canConstruct(string s, int k) {
      if(s.size()<k) return false;
      unordered_map<int,int>mp;
      int no = 0;
      for(auto a:s) mp[a]++;
      for(auto &it :mp) if(it.second % 2 ==1) no++;
      return no <= k;  
    }
};