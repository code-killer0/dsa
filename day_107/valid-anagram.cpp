class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m= t.size();
        if(n!=m){
            return false;
        }
        vector<int>temp1(26,0);
        vector<int>temp2(26,0);
        for(int i =0;i<n;i++){
            temp1[s[i]-'a']++;
            temp2[t[i]-'a']++;
        }
        
        for(int i =0;i<26;i++){
            if(temp1[i] != temp2[i]){
                return false;
            }
        }
        return true;
    }
};