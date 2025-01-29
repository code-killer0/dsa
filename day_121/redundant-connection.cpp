class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();

        vector<vector<int>> adj(n+1);

        

        for(vector<int> edge: edges)
        {
            vector<bool> visited(n+1, false);
            if(dfs(edge[0], edge[1], adj, visited ))
            {
                return edge;
            }

            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);

        }

        return {};
    }

    bool dfs(int u, int target, vector<vector<int>>& adj, vector<bool>& visited)
    {
        if(u == target)return true;

        visited[u] = true;

        for(int v: adj[u])
        {
            if(!visited[v])
            {
                if(dfs(v, target, adj, visited))
                return true;
            }

        }

        return false;
    } 
};