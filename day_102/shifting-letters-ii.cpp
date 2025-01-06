class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int>v(n+1);
        for(auto i:shifts){
            int delta = i[2] ? 1 : -1;
            v[i[0]]+=delta;
            v[i[1]+1]-=delta;
        }
        int curr = 0;
        vector<int>v1(n);
        for(int i=0;i<n;i++){
            curr += v[i];
            v1[i]+=curr;
        }
        for(int i=0;i<n;i++){
            int shift = (s[i] - 'a' + v1[i]) % 26;
            if(shift<0) shift+=26;
            s[i]='a'+shift;
        }
        return s;
    }
};