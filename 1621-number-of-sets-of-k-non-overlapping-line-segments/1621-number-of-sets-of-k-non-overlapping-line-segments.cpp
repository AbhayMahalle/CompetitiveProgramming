class Solution {
public:
   int MOD = 1e9 + 7;
   // Memoization Code 
   long long solve(int i, int j, auto& dp, auto& prefix) {
       if(j == 0) return 1;
       if(i == 0) return 0;
       if(dp[i][j] != -1) return dp[i][j];
       long long sum = getPrefix(i - 1, j - 1, dp, prefix);
       return dp[i][j] = (solve(i - 1, j, dp, prefix) + sum) % MOD;
   }
   
   long long getPrefix(int i, int j, auto& dp, auto& prefix) {
       if(i < 0) return 0;
       if(prefix[i][j] != -1) return prefix[i][j];
       long long prevPrefix = getPrefix(i-1, j, dp, prefix);
       long long cur = solve(i, j, dp, prefix);
       return prefix[i][j] = (prevPrefix + cur) % MOD;
   }
   
   int numberOfSets(int n, int k) {
       vector<vector<long long>> dp(n, vector<long long>(k + 1, -1));
       vector<vector<long long>> prefix(n, vector<long long>(k + 1, -1));
       
       for(int i = 0; i < n; i++) {
           dp[i][0] = 1;
           prefix[i][0] = i + 1;
       }
       
       return solve(n - 1, k, dp, prefix);
   }
};