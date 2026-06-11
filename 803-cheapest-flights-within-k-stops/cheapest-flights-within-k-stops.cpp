class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < flights.size(); i++){
            int strNode = flights[i][0];
            int endNode = flights[i][1];
            int cost = flights[i][2];

            adj[strNode].push_back({endNode, cost});
        }
        queue<pair<int, pair<int,int>>> q;
        vector<int> dist(n, 1e9);

        dist[src] = 0;
        q.push({0, {src, 0}});

        while(!q.empty()){
            auto val = q.front();
            q.pop();

            int stops = val.first;
            int node = val.second.first;
            int cost = val.second.second;

            if(stops > k) continue;

            for(auto it : adj[node]){
                int neigh = it.first;
                int cst = it.second;

                if(cost + cst < dist[neigh] && stops <= k){
                    dist[neigh] = cost + cst;

                    q.push({
                        stops + 1,
                        {neigh, cost + cst}
                    });
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};