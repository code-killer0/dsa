class Solution { 
public:
    void dfsToCheckBiPartite(int node, vector<vector<int>>& adj, vector<int>& colors, int color, bool& possible, vector<int>& components){
        
        components.push_back(node);
        colors[node] = color;

        for(int child : adj[node]){
            if(colors[child]==-1){
                dfsToCheckBiPartite(child, adj, colors, color^1, possible, components);
            }
            else{
                if(colors[child]==colors[node]){
                    possible = false;
                    return;
                }
            }
        }
    }
    int bfsToFindMaxDepth(int node, vector<vector<int>>& adj){
        queue<int> q;
        vector<int> visited(adj.size(), -1);
        q.push(node);
        visited[node] = 0;
        int maxDepth = 1;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int neighbour : adj[curr]){
                if(visited[neighbour] == -1){
                    visited[neighbour] = visited[curr] + 1;
                    maxDepth = max(maxDepth, visited[neighbour] + 1);
                    q.push(neighbour);
                }
            }
        }
        return maxDepth;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++){
            int a = edges[i][0];
            a--;
            int b = edges[i][1];
            b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int totalGroups = 0;

        vector<int> colors(n, -1);
        
        for(int i=0; i<n; i++){
            if(colors[i]==-1){
                vector<int> components;
                
                bool possible = true;
                dfsToCheckBiPartite(i, adj, colors, 0, possible, components);
                if(!possible) return -1;

                
                int ans = 0;
                
                for(auto it : components){
                    int depth = bfsToFindMaxDepth(it, adj);
                    ans = max(ans, depth);
                }
                totalGroups+=ans;
            }
        }
        return totalGroups;
    }
};