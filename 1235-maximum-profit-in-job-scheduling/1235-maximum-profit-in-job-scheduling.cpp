class Solution {
public:
    vector<tuple<int, int, int>> intervals;
    vector<int> nxtIndex;
    vector<long long> dp;
    long long solve(int i){
        if(i>=intervals.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        long long skip = solve(i+1);
        auto &[l, r, p] = intervals[i];
        long long take = p;
        take += solve(nxtIndex[i]);
        return dp[i] = max(take, skip);
    }
    int jobScheduling(vector<int>& st, vector<int>& end, vector<int>& profit) {
        for(int i=0; i<profit.size(); i++){
            tuple<int, int, int> interval = {st[i], end[i], profit[i]};
            intervals.push_back(interval);
        }
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        nxtIndex.resize(n, n);
        for(int i=0; i<n; i++){
            auto &[l, r, p] = intervals[i];
            nxtIndex[i] = upper_bound(intervals.begin(), intervals.end(), make_tuple(r-1, INT_MAX, INT_MAX)) - intervals.begin();
        }
        dp.resize(n, -1);
        return solve(0);
    }
};