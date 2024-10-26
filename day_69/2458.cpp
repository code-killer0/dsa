/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
map<int,int> mp,maxmp;
class Solution {
public:
    static bool cmp(pair<int,int> & a, pair<int,int> &b){
        return a.first > b.first;
    }
    void dfs(TreeNode* tmp, int lvl){
        if(!tmp){
            return;
        }

        maxmp[tmp -> val] = lvl;
        dfs(tmp -> left, lvl + 1);
        dfs(tmp -> right, lvl + 1);
        int lft = 0, rgt = 0;
        lft = tmp -> left ? maxmp[tmp -> left -> val] : 0;
        rgt = tmp -> right ? maxmp[tmp -> right -> val] : 0;
        maxmp[tmp -> val] = max({lft,rgt,maxmp[tmp->val]});

    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {

        mp.clear();
        maxmp.clear();
        map<int,vector<pair<int,int>>> allLvl;

        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        while(!q.empty()){
            TreeNode* tmp = q.front().first;
            int lvl = q.front().second;
            q.pop();
            mp[tmp -> val] = lvl;

            if(tmp -> left){
                q.push({tmp -> left, lvl+1});
            }
            if(tmp -> right){
                q.push({tmp -> right, lvl+1});
            }

        }
        dfs(root,0);

        for(auto it : maxmp){
            int node = it.first;
            int maxdepth = it.second;
            int lvl = mp[node];
            allLvl[lvl].push_back({maxdepth,node});
        }

        for(auto &it : allLvl){
            sort(it.second.begin(),it.second.end(),cmp);
        }
        vector<int> ans;
        for(int i : queries){
            int lvl = mp[i];
            bool printed = 0;
            for(auto h : allLvl[lvl]){
                int depth = h.first;
                int node = h.second;
                if(node != i){
                    ans.push_back(depth);
                    printed = 1;
                    break;
                }
                
            }
            if(!printed){
                ans.push_back(lvl-1);
            }
        }

        for(auto i : allLvl[2]){
            cout<<i.first<<" "<<i.second<<endl;
        }

        return ans;
    }
};