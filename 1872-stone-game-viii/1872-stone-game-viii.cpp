class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int p, int n, vector<int>& stones){
        if(i>=n){
            return 0;
        }
        if(dp[i][p]!=-1) return dp[i][p];
        if(p){
            int take = stones[i] + solve(i+1, !p, n, stones);
            int notTake = INT_MIN;
            if(i+1<n) notTake = solve(i+1, p, n, stones);
            dp[i][p] = max(take, notTake);
        }
        else {
            int take = -stones[i] + solve(i+1, !p, n, stones);
            int notTake = INT_MAX;
            if(i+1<n) notTake = solve(i+1, p, n, stones);
            dp[i][p] = min(take, notTake);
        }
        return dp[i][p];
    }
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        for(int i=1; i<n; i++){
            stones[i] += stones[i-1];
        }
        dp.resize(n, vector<int>(2, -1));
        return solve(1, 1, n, stones);
    }
};