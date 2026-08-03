class Solution {
public:
    int solve(int i, int p, int n, vector<int>& stoneValue, vector<vector<int>>& dp){
        if(i>=n) return 0;  
        if(dp[i][p]!=-1) return dp[i][p];
        int cur = INT_MIN;
        if(!p){
            int prefix = 0;
            for(int j=i; j<min(i+3, n); j++){
                prefix += stoneValue[j];
                cur = max(cur, prefix+solve(j+1, !p, n, stoneValue, dp));
            }
        }
        else{
            cur = INT_MAX;
            int prefix = 0;
            for(int j=i; j<min(i+3, n); j++){
                prefix += stoneValue[j];
                cur = min(cur, -prefix+solve(j+1, !p, n, stoneValue, dp));
            }
        }
        return dp[i][p] = cur;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        int res = solve(0, 0, n, stoneValue, dp);
        if(res>0) return "Alice";
        else if(res<0) return "Bob";
        return "Tie";
    }
};