class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis){

        vis[node] = 1;
        for(int nei : adj[node]){

            if(nei == parent) continue;

            if(vis[nei]) return true;
            if(dfs(nei, node, adj, vis)){
                return true;
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        vector<vector<int>> adj(edges.size() + 1);
        for(auto& edge : edges){

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            vector<int> vis(edges.size() + 1, 0);

            if(dfs(u, -1, adj, vis)){
                return edge;
            }
        }
        return {};
    }
};