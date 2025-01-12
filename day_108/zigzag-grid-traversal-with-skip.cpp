class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int>temp;
        vector<int>ans;
        int m = grid.size();
        int n = grid[0].size();
    
        for (int i = 0; i < m; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < n; j++) {
                    temp.push_back(grid[i][j]);
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                     temp.push_back(grid[i][j]);
                }
            }
        }
        for(int i =0;i<temp.size();i = i+2){
            ans.push_back(temp[i]);
        }
        return ans;
    }
};