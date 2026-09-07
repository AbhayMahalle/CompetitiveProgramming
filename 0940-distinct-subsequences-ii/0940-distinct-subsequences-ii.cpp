class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        int MOD = 1e9+7;
        vector<int> dp(n, 1);
        vector<int> countEndWith(26, 0);
        int sum = 0;
        for(int i=0; i<n; i++){
           int idx = s[i] - 'a';
           dp[i] = (dp[i] + sum - countEndWith[idx] + MOD) % MOD;
           sum = (sum + dp[i]) % MOD;
           countEndWith[idx] = (countEndWith[idx] + dp[i]) % MOD;
        }
        return sum;
    }
};