class Solution {
public:
    const long long MOD = 1e9+7;
    int n;
    long long solve(int i, int g1, int g2, vector<int>& nums, vector<vector<vector<int>>> &dp) {
        if(i==n){
            return (g1!=0 && g1==g2);
        }
        if(dp[i][g1][g2]!=-1) return dp[i][g1][g2];
        long long cur = 0;
        cur = (cur + solve(i+1, gcd(g1, nums[i]), g2, nums, dp)) % MOD;
        cur = (cur + solve(i+1, g1, gcd(g2, nums[i]), nums, dp)) % MOD;
        cur = (cur + solve(i+1, g1, g2, nums, dp)) % MOD;
        return dp[i][g1][g2] = cur;
    }
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(201, vector<int>(201, -1)));
        return solve(0, 0, 0, nums, dp);
    }
};