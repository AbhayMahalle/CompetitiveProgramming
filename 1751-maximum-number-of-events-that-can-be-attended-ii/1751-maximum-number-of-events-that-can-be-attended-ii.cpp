class Solution {
public:
    vector<tuple<int, int,int>> intervals;
    vector<vector<long long>> dp;
    vector<int> nxtIndex;

    long long solve(int i, int k){
        if(k==0 || i>=intervals.size()) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        long long skip = solve(i+1, k);
        auto &[l, r, v] = intervals[i];
        long long take = v;
        take += solve(nxtIndex[i], k-1);
        return dp[i][k] = max(take, skip);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        for(auto e : events){
            tuple<int, int,int> t = {e[0], e[1], e[2]};
            intervals.push_back(t);
        }
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        nxtIndex.resize(n, n);
        for(int i=0; i<n; i++){
            auto &[l, r, v] = intervals[i];
            nxtIndex[i] = upper_bound(intervals.begin(), intervals.end(), 
                make_tuple(r, INT_MAX, INT_MAX)) - intervals.begin();
        }
        dp.resize(n, vector<long long>(k+1, -1));
        return solve(0, k);
    }
};