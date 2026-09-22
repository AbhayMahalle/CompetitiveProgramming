class Solution {
public:
    using ll = long long;
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> res(k, 0);
        for(auto &num : nums) num %= k;
        vector<vector<ll>> dp(n, vector<ll>(k, 0));
        dp[0][nums[0]]++;
        for(int i=1; i<n; i++){
            dp[i][nums[i]]++;
            for(int j=0; j<k; j++){
                ll prod = (j*nums[i]) % k;
                dp[i][prod] += dp[i-1][j];
            }
            
        }
        for(int i=0; i<n ;i++){
            for(int j=0; j<k; j++){
                res[j] += dp[i][j];
            }
        }
        return res;
    }
};