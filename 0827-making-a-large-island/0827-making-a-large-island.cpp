class Solution {
public:
    
    void dfs(int i, int j, int id, int m, int n, int &cur, auto &grid, auto &mark){
        mark[i][j] = id;
        cur++;
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        for(int d=0; d<4; d++){
            int ni = i + dr[d];
            int nj = j + dc[d];
            if(ni<0 || ni>=m || nj<0 || nj>=n) continue;
            if(grid[ni][nj]==0 || mark[ni][nj]==id) continue;
            dfs(ni, nj, id, m, n, cur, grid, mark);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> mark(m, vector<int>(n, 0));
        int id = 2;
        unordered_map<int, int> mp;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!mark[i][j] && grid[i][j]==1){
                    int cur = 0;
                    dfs(i, j, id, m, n, cur, grid, mark);
                    mp[id] = cur;
                    id++;
                }
            }
        }
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        int res = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                unordered_map<int, int> ids;
                if(grid[i][j]==0){
                    for(int d=0; d<4; d++){
                        int ni = i + dr[d];
                        int nj = j + dc[d];
                        if(ni<0 || ni>=m || nj<0 || nj>=n) continue;
                        if(grid[ni][nj]==0 || mark[ni][nj]<2) continue;
                        ids[mark[ni][nj]]++;
                    }
                    int cur =  1;
                    for(auto [id, f] : ids){
                        cur += mp[id];
                    }
                    res = max(res, cur);
                }
                else res = max(res, mp[mark[i][j]]);
            }
            
        }
        return res;
    }
};