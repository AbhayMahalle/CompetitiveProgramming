class Solution {
public:
    int solve(int i, int p, int m, vector<int> &piles, vector<vector<vector<int>>>& dp){
        int n = piles.size();
        if(i>=n){
            return 0;
        }
        if(dp[i][m][p]!=-1) return dp[i][m][p];
        int cur = INT_MIN;
        if(!p){
            int pre = 0;
            for(int j=i; j<min(i+(2*m), n); j++){
                pre += piles[j];
                cur = max(cur, pre + solve(j+1, !p, max(m, j-i+1), piles, dp));
            }
        }
        else {
            cur = INT_MAX;
            int pre = 0;
            for(int j=i; j<min(i+(2*m), n); j++){
                pre += piles[j];
                cur = min(cur, -pre + solve(j+1, !p, max(m, j-i+1), piles, dp));
            }
        }
        return dp[i][m][p] = cur;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        int total = accumulate(piles.begin(), piles.end(), 0);
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2*n, vector<int>(2, -1)));
        int diff = solve(0, 0, 1, piles, dp);
        return (total + diff)/2;
    }
};