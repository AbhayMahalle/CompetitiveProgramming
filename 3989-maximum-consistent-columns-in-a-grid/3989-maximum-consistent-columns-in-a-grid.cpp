class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int solve(int j, int prev, vector<vector<int>>& grid, int limit){
        if(j==n){
            return 0;
        }
        if(dp[j][prev]!=-1) return dp[j][prev];
        int take = 0, notTake = 0;
        if(prev==n){
            take = 1 + solve(j+1, j, grid, limit);
        }
        else {
            bool check = true;
            for(int i=0; i<m; i++){
                if(abs(grid[i][prev]-grid[i][j])>limit){
                    check = false;
                    break;
                }
            }
            if(check) take = 1 + solve(j+1, j, grid, limit);
        }
        notTake = solve(j+1, prev, grid, limit);
        return dp[j][prev] = max(take, notTake);
    }
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        m = grid.size();
        n = grid[0].size();
        dp.resize(n, vector<int>(n+1, -1));
        return solve(0, n, grid, limit);
    }
};