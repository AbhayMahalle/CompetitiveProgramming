class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;
    int solve(int i, int j, int bal, auto &grid){
        int cur = 0;
        if(grid[i][j]=='(') cur = 1;
        else cur = -1;
        bal += cur;
        if(bal<0) return 0;
        if(i==m-1 && j==n-1 && bal==0) return 1;
        if(dp[i][j][bal]!=-1) return dp[i][j][bal];
        int dr[] = {1, 0};
        int dc[] = {0, 1};
        for(int k=0; k<2; k++){
            int ni = i + dr[k];
            int nj = j + dc[k];
            if(ni<0 || nj <0 || ni>=m || nj>=n) continue;
            if(solve(ni, nj, bal, grid)) return dp[i][j][bal] = 1;
        }
        return dp[i][j][bal] = 0;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.resize(m+1, vector<vector<int>>(n+1, vector<int>(m+n+1, -1)));
        return solve(0, 0, 0, grid);
    }
};