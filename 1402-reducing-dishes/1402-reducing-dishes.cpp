class Solution {
public:
    int solve(int i, int cur, int n, vector<int>& sat, vector<vector<int>>& dp){
        if(i>=n) return 0;
        if(dp[i][cur]!=-1) return dp[i][cur];
        int notTake = solve(i+1, cur, n, sat, dp);
        int take = cur*sat[i] + solve(i+1, cur+1, n, sat, dp);
        return dp[i][cur] = max(take, notTake);
    }
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(), sat.end());
        int n = sat.size();
        vector<vector<int>> dp(n, vector<int>(n+1 , -1));
        return solve(0, 1, n, sat, dp);
    }
};