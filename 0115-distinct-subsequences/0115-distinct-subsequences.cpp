class Solution {
public:
    int ways(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take = 0;
        if(s[i]==t[j]){
            take = ways(i-1, j-1, s, t, dp);
        }
        int notTake = ways(i-1, j, s, t, dp);
        return dp[i][j] = take + notTake;
    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return ways(m-1, n-1, s, t, dp);
    }
};