class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 1e8));
        dp[0][0] = 0;

        for(int i = 0; i < n; i++) {

            for(int s = 0; s <= sum; s++) {
                if(dp[i][s] == 1e8) continue;

                // don't take
                dp[i + 1][s] = min(dp[i + 1][s], dp[i][s]);

                // take: try every value nums[i] can turn into
                long long val = nums[i];
                int mul = 0;

                while(val <= 1LL * sum * 2 || mul == 0) {
                    long long cur = val;
                    int div = 0;

                    while(cur > 0) {
                        if(cur <= sum && s + cur <= sum) {
                            dp[i + 1][s + (int)cur] = min(dp[i + 1][s + (int)cur], dp[i][s] + mul + div);
                        }

                        cur /= 2;
                        div++;
                    }

                    val *= 2;
                    mul++;
                }

                int d = nums[i] / 2;

                if(s + d <= sum) {
                    dp[i + 1][s + d] = min(dp[i + 1][s + d], dp[i][s] + 1);
                }
            }
        }

        int res = dp[n][sum];

        return res >= 1e8 ? -1 : res;
    }
};