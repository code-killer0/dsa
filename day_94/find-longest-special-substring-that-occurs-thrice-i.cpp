class Solution {
public:
    int max(int x, int y){
        return (x>y)?x:y;
    }
    int maximumLength(string s) {
        int n = s.length();
        map<string, int> mp;
        for(int i=0; i<s.length(); i++){
            for(int j=i; j<s.length(); j++){
                string str;
                for(int k = i; k<=j; k++){
                    str.push_back(s[k]);
                }
                set<char> st;
                for(int l=0; l<str.length(); l++){
                    st.insert(str[l]);
                }
                if(st.size() == 1){
                    mp[str]++;
                }
            }
        }
        int maxi = -1;
        for(auto it: mp){
            cout<<it.first<<" "<<it.second<<" ";
            if(it.second >= 3){
                maxi = max(maxi, it.first.length());
            }
        }
        return maxi;
    }
};