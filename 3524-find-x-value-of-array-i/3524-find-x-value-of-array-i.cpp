class Solution {
public:
    using ll = long long;
    int n;
    ll solve(int i, int preProd, int r, int k, vector<int>&nums, vector<vector<ll>> &dp){
        if(i==n) return 0;
        if(dp[i][preProd]!=-1) return dp[i][preProd];
        ll take = 0, notTake = 0;
        if(preProd==k){
            take = (r==nums[i]) + solve(i+1, nums[i], r, k, nums, dp);
            notTake = solve(i+1, k, r, k, nums, dp);
        }
        else {
            ll newPro = (preProd * nums[i]) % k;
            take = (newPro==r) + solve(i+1, newPro, r, k, nums, dp);
        }
        return dp[i][preProd] = take + notTake;
    }
    vector<ll> resultArray(vector<int>& nums, int k) {
        n = nums.size();
        vector<ll> res(k, 0);
        for(int &num : nums) num = num % k;
        for(int r=0; r<k; r++){
            vector<vector<ll>> dp(n, vector<ll>(k+1, -1));
            res[r] = solve(0, k, r, k, nums,dp);
        }
        return res;
    }
};