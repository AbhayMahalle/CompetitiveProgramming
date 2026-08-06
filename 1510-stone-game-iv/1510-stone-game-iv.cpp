class Solution {
public:
    bool solve(int p, int n, vector<vector<int>> &dp){
        if(n==0){
            if(p) return true;
            return false;
        }
        if(dp[n][p]!=-1) return dp[n][p];
        if(!p){
            long long t = n;
            long long cur = 1;
            int b = 1;
            while(t-cur>=0){
                if(solve(!p, t-cur, dp)) return dp[n][p] = true;
                b++;
                cur = 1LL*  b * b;
            }
        }
        else{
            long long t = n;
            long long cur = 1;
            int b = 1;
            while(t-cur>=0){
                if(!solve(!p, t-cur, dp)) return dp[n][p] = false;
                b++;
                cur = 1LL*  b * b;
            }
        }
        if(p) return dp[n][p] = true;
        return dp[n][p] = false;
    }
    bool winnerSquareGame(int n) {
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solve(0, n, dp);
    }
};