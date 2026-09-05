class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        queue<pair<int, pair<int, int>>> q;
        if(grid[0][0]) return -1;
        dist[0][0] = 1;
        q.push({1, {0, 0}});
        vector<int> dr = {1, 0, 1, 0, -1, -1, -1, 1};
        vector<int> dc = {0, 1, 1, -1, 0, -1, 1, -1};
        while(!q.empty()){
            auto t = q.front();
            int dis = t.first;
            int i = t.second.first;
            int j = t.second.second;
            q.pop();
            for(int k=0; k<8; k++){
                int ni = i + dr[k];
                int nj = j + dc[k];
                if(ni<0 || ni>=m || nj<0 || nj>=n) continue;
                if(!grid[ni][nj] && dis + 1 < dist[ni][nj]){
                    dist[ni][nj] = dis + 1;
                    q.push({dist[ni][nj], {ni, nj}});
                }
            }
        }
        int res = dist[m-1][n-1];
        return res >= 1e9 ? -1 : res;
    }
};