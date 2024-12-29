#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = INT_MIN;
        int max_val = values[0];
        for(int i =1;i<values.size();i++){
            ans = max(ans,(max_val+values[i]-i)); 
            max_val = max(max_val,values[i]+i);
        }
        return ans;
    }
};