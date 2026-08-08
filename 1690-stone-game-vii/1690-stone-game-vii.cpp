class Solution {
public:
    int solve(int i, int j, vector<int>& stones, vector<vector<int>> &dp){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int left = stones[j] - stones[i] - solve(i+1, j, stones, dp);
        int right = 0;
        if(i>0) right = (stones[j-1] - stones[i-1]);
        else right = stones[j-1];
        right -= solve(i, j-1, stones, dp);
        return dp[i][j] = max(left, right);
    }
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        for(int i=1; i<n; i++){
            stones[i] += stones[i-1];
        }
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int i = 0, j = n-1;
        return solve(i, j, stones, dp);
    }
};