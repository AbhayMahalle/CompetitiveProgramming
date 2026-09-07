class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, int n, vector<int>& dr, vector<int>& dc,vector<vector<int>>& fruits){
        if(i<0 || j<0 || i>=n|| j>=n) return -1e9;
        if(i==n-1 && j==n-1) return 0;
        int sum = accumulate(dr.begin(), dr.end(), 0);
        if(sum==3 && i>j) return -1e9;
        if(sum==0 && j>i) return -1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int cur = -1e9;
        for(int d=0; d<dr.size(); d++){
            int ni = i + dr[d];
            int nj = j + dc[d];
            cur = max(cur, fruits[i][j] + solve(ni, nj, n, dr, dc, fruits));
        }
        return dp[i][j] = cur;
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int diagonal = 0;
        for(int i=0; i<n; i++){
            diagonal += fruits[i][i]; 
            fruits[i][i] = 0;
        }
        dp.resize(n, vector<int>(n, -1));
        vector<int> a = {1, 1, 1};
        vector<int> b = {0, -1, 1};
        int right = solve(0, n-1, n, a, b, fruits);
        int left = solve(n-1, 0, n, b, a, fruits);
        return left + diagonal + right;
    }
};