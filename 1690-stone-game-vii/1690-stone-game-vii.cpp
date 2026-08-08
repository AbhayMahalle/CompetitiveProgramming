class Solution {
public:
    int solve(int i, int j, int p, vector<int>& stones, vector<vector<vector<int>>> &dp){
        if(i>=j){
            return 0;
        }
        if(dp[i][j][p]!=-1) return dp[i][j][p];
        if(p){
            int left = stones[j] - stones[i] + solve(i+1, j, !p, stones, dp);
            int right = 0;
            if(i>0) right = (stones[j-1] - stones[i-1]);
            else right = stones[j-1];
            right += solve(i, j-1, !p, stones, dp);
            return dp[i][j][p] = max(left, right);
        }
        else {
            int left = -(stones[j] - stones[i]) + solve(i+1, j, !p, stones, dp);
            int right = 0;
            if(i>0) right = -(stones[j-1] - stones[i-1]);
            else right = -stones[j-1];
            right += solve(i, j-1, !p, stones, dp);
            return dp[i][j][p] = min(left, right);
        }
        return 0;
    }
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        for(int i=1; i<n; i++){
            stones[i] += stones[i-1];
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        int i = 0, j = n-1;
        return solve(i, j, 1, stones, dp);
    }
};