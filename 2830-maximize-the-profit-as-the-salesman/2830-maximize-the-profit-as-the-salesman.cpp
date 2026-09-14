class Solution {
public:
    vector<tuple<int,int,int>> offers;
    vector<int> dp;
    vector<int> nxtIdx;
    int solve(int i, int n){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int skip = solve(i+1, n);
        auto [l, r, g] = offers[i];
        int take = g;
        take += solve(nxtIdx[i], n);
        return dp[i] = max(take, skip);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& off) {
        for(auto it : off){
            offers.push_back(make_tuple(it[0], it[1], it[2]));
        }
        sort(offers.begin(), offers.end());
        int m = offers.size();
        nxtIdx.resize(m, m);
        for(int i=0; i<m; i++){
            auto &[l, r, g] = offers[i];
            nxtIdx[i] = upper_bound(
                offers.begin(),
                offers.end(),
                make_tuple(r, INT_MAX, INT_MAX)
            ) - offers.begin();
        }
        dp.resize(m+1, -1);
        return solve(0, m);
    }
};