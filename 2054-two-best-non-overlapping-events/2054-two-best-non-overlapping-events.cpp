class Solution {
public:
    vector<tuple<int, int, int>> intervals;
    vector<int> nxtIdx;
    vector<vector<int>> dp;
    int solve(int i, int k){
        if(i>=intervals.size() || k==0) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int skip = solve(i+1, k);
        auto &[l, r, v] = intervals[i];
        int take = v;
        take += solve(nxtIdx[i], k-1);
        return dp[i][k] = max(take, skip);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        for(auto &e : events){
            intervals.push_back(make_tuple(e[0], e[1], e[2]));
        }
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        nxtIdx.resize(n, n);
        for(int i=0; i<n; i++){
            auto &[l, r, v] = intervals[i];
            nxtIdx[i] = upper_bound(
                intervals.begin(),
                intervals.end(),
                make_tuple(r, INT_MAX, INT_MAX)
            ) - intervals.begin();
        }
        dp.resize(n, vector<int>(3, -1));
        return solve(0, 2);
    }
};