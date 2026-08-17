class Solution {
public:
    vector<vector<int>> dp;
    int solve(int l, int r, vector<int> &stoneValue, vector<int> &prefixSum){
        if(l==r){
            return 0;
        }
        else if(r-l==1) return min(stoneValue[l], stoneValue[r]);
        if(dp[l][r]!=-1) return dp[l][r];
        int cur = 0;
        int total = prefixSum[r+1]-prefixSum[l+1];
        int prefix = stoneValue[l];
        for(int i=l+1; i<=r; i++){
            if(prefix==total){
                cur = max(cur, prefix+solve(l, i-1, stoneValue, prefixSum));
                cur = max(cur, total+solve(i, r, stoneValue, prefixSum));
            }
            else if(prefix<total){
                cur = max(cur, prefix+solve(l, i-1, stoneValue, prefixSum));
            }
            else {
                cur = max(cur, total+solve(i, r, stoneValue, prefixSum));
            }
            prefix += stoneValue[i];
            total -= stoneValue[i];
        }
        return dp[l][r] = cur;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefixSum(n+1, 0);
        for(int i=1; i<=n; i++){
            prefixSum[i] += prefixSum[i-1] + stoneValue[i-1]; 
        }
        dp.resize(n, vector<int>(n, -1));
        return solve(0, n-1, stoneValue, prefixSum);
    }
};