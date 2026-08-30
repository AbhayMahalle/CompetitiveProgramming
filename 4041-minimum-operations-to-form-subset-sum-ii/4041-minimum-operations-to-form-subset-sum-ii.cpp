class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 1e8));
        dp[0][0] = 0;

        for(int i = 0; i < n; i++){

            for(int s = 0; s <= sum; s++){
                if(dp[i][s] == 1e8) continue;

                // don't take
                dp[i + 1][s] = min(dp[i + 1][s], dp[i][s]);

                // take: try every reachable value of nums[i]
                int val = nums[i];
                int div = 0;

                while(val > 0){

                    long long cur = val;
                    int mul = 0;

                    while(cur <= sum){

                        if(s + cur <= sum){
                            dp[i + 1][s + (int)cur] = min(dp[i + 1][s + (int)cur], dp[i][s] + div + mul);
                        }

                        cur *= 2;
                        mul++;
                    }

                    val /= 2;
                    div++;
                }
            }
        }

        int res = dp[n][sum];

        return res >= 1e8 ? -1 : res;
    }
};