class Solution {
public:
    vector<int> dp;
    bool solve(int mask, int rem, int maxI) {
        if(dp[mask] != -1)return dp[mask];

        for(int i = 1; i <= maxI; i++) {
            if(mask & (1 << i)) continue;
            if(i >= rem) return dp[mask] = true;
            // If opponent cannot win, current player wins
            if(!solve(mask | (1 << i), rem - i, maxI)) return dp[mask] = true;
        }
        return dp[mask] = false;
    }
    bool canIWin(int maxI, int total) {
        if(total == 0) return true;
        if(maxI * (maxI + 1) / 2 < total) return false;
        dp.assign(1 << (maxI + 1), -1);
        return solve(0, total, maxI);
    }
};