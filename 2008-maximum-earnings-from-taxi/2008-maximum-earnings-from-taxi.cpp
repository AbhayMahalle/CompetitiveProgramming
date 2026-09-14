class Solution {
public:
    using ll = long long;
    vector<tuple<int, int, int>> intervals;
    vector<ll> dp;
    vector<int> nxtIdx;
    ll solve(int i, int n){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        ll skip = solve(i+1, n);
        auto &[l, r, t] = intervals[i];
        ll take = r-l+t;
        take += solve(nxtIdx[i], n);
        return dp[i] = max(take, skip);
    }
    ll maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        for(auto &r : rides){
            intervals.push_back(make_tuple(r[0], r[1], r[2]));
        }
        int m = intervals.size();
        sort(intervals.begin(), intervals.end());
        nxtIdx.resize(m, m);
        for(int i=0; i<m; i++){
            auto [l, r, t] = intervals[i];
            nxtIdx[i] = upper_bound(
                intervals.begin(), 
                intervals.end(),
                make_tuple(r-1, INT_MAX, INT_MAX)
            ) - intervals.begin();
        }
        dp.resize(m+1, -1);
        return solve(0, m);
    }
};