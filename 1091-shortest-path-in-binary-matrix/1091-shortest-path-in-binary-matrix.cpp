class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<int, int>> q;
        q.push({0, 0});
        if(grid[0][0]==1) return -1;
        vis[0][0] = 1;
        int len = 1;
        int can = 0;
        while(!q.empty()){
            int s = q.size();
            int b = 0;
            while(s--){
                auto p = q.front();
                q.pop();
                int i = p.first, j = p.second;
                if(i==n-1 && j==n-1) {
                    b = 1;
                    can = 1;
                    break;
                }
                // Down
                if (i + 1 < n && !vis[i + 1][j] && !grid[i + 1][j]) {
                    vis[i + 1][j] = 1;
                    q.push({i + 1, j});
                }
                // Up
                if (i - 1 >= 0 && !vis[i - 1][j] && !grid[i - 1][j]) {
                    vis[i - 1][j] = 1;
                    q.push({i - 1, j});
                }
                // Right
                if (j + 1 < n && !vis[i][j + 1] && !grid[i][j + 1]) {
                    vis[i][j + 1] = 1;
                    q.push({i, j + 1});
                }
                // Left
                if (j - 1 >= 0 && !vis[i][j - 1] && !grid[i][j - 1]) {
                    vis[i][j - 1] = 1;
                    q.push({i, j - 1});
                }
                // Down-Right
                if (i + 1 < n && j + 1 < n && !vis[i + 1][j + 1] && !grid[i + 1][j + 1]) {
                    vis[i + 1][j + 1] = 1;
                    q.push({i + 1, j + 1});
                }
                // Down-Left
                if (i + 1 < n && j - 1 >= 0 && !vis[i + 1][j - 1] && !grid[i + 1][j - 1]) {
                    vis[i + 1][j - 1] = 1;
                    q.push({i + 1, j - 1});
                }
                // Up-Right
                if (i - 1 >= 0 && j + 1 < n && !vis[i - 1][j + 1] && !grid[i - 1][j + 1]) {
                    vis[i - 1][j + 1] = 1;
                    q.push({i - 1, j + 1});
                }
                // Up-Left
                if (i - 1 >= 0 && j - 1 >= 0 && !vis[i - 1][j - 1] && !grid[i - 1][j - 1]) {
                    vis[i - 1][j - 1] = 1;
                    q.push({i - 1, j - 1});
                }
            }
            if(b) break;
            len++;
        }
        if(!can) return -1;
        return len;
    }
};