class Solution {
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

public:
    int swimInWater(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0,0}});

        while(!pq.empty()){

            auto val = pq.top();
            pq.pop();

            int tm = val.first;
            int cr = val.second.first;
            int cc = val.second.second;

            if(cr == row - 1 && cc == col - 1){
                return tm;
            }

            if(tm > dist[cr][cc]) continue;

            for(int i = 0; i < 4; i++){

                int nr = cr + dir[i][0];
                int nc = cc + dir[i][1];

                if(nr >= 0 && nc >= 0 && nr < row && nc < col){
                    int newTime = max(tm, grid[nr][nc]);

                    if(dist[nr][nc] > newTime){
                        dist[nr][nc] = newTime;
                        pq.push({newTime, {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};