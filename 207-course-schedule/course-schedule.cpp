class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& isVis, vector<bool>& isPath){
        isVis[node] = true;
        isPath[node] = true;

        for(auto it : adj[node]){
            if(!isVis[it]){
                if(dfs(it, adj, isVis, isPath)) return true;
            }
            else if(isPath[it]){
                return true;
            }
        }

        isPath[node] = false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& pre) {
        
        vector<vector<int>> adj(n);
        for(int i = 0; i < pre.size(); i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }

        vector<bool> isVis(n, false);
        vector<bool> isPath(n, false);

        for(int i = 0; i < n; i++){
            if(!isVis[i]){
                if(dfs(i, adj, isVis, isPath)) return false;
            }
        }
        return true;
    }
};