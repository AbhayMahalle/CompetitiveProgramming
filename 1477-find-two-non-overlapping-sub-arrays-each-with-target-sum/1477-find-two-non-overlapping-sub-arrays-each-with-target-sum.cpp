class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int n, int rem, vector<int>&idx){
        if(rem==0) return 0;
        if(i>=n) return 1e9;
        if(dp[i][rem]!=-1) return dp[i][rem];
        int take = 1e9;
        if(idx[i]!=-1){
            take = idx[i]-i + solve(idx[i], n, rem-1, idx);
        }
        int notTake = solve(i+1, n, rem, idx);
        return dp[i][rem] = min(take, notTake);
    }
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> prefix(n+1, 0);
        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i] + arr[i];
        }
        vector<int> idx(n+1, -1);
        unordered_map<int, int> lastSeen;
        for(int i=0; i<=n; i++){ 
            if(lastSeen.find(prefix[i]-target)!=lastSeen.end()){
                idx[lastSeen[prefix[i]-target]] = i;
            }
            lastSeen[prefix[i]] = i;
        }
        dp.resize(n+1, vector<int>(3, -1));
        int res = solve(0, n+1, 2, idx);
        return res>=1e9? -1 : res;
    }
};