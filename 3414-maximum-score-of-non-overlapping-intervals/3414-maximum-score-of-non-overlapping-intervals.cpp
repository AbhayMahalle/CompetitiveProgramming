class Solution {
public:
    using P = pair<long long, vector<int>>;

    map<tuple<int, int, int>, int> originalIndex;
    vector<tuple<int, int, int>> intervals;
    vector<int> nxtIndex;
    vector<vector<P>> dp;

    P solve(int i, int k){
        if(k==0 || i>=intervals.size()) return {0, {}};
        if(dp[i][k].first!=-1){
            return dp[i][k];
        }
        P skip = solve(i+1, k);
        auto &[l, r, w] = intervals[i];
        P take = solve(nxtIndex[i], k-1);
        take.second.push_back(originalIndex[intervals[i]]);
        sort(take.second.begin(), take.second.end());
        take.first += w;
        if(take.first>skip.first){
            return dp[i][k] = take;
        }
        else if(skip.first>take.first){
            return dp[i][k] = skip;
        }
        return dp[i][k] = min(take, skip);
    }
    vector<int> maximumWeight(vector<vector<int>>& a) {
        for(int i=0; i<a.size(); i++){
            if(originalIndex.find({a[i][0], a[i][1], a[i][2]})!=originalIndex.end()){
                continue;
            }
            originalIndex[{a[i][0], a[i][1], a[i][2]}] = i;
        }
        for(auto &[interval, index] : originalIndex){
            intervals.push_back(interval);
        }
        int n = intervals.size();
        nxtIndex.resize(n, n);
        for(int i=0; i<n; i++){
            auto &[l, r, w] = intervals[i];
            nxtIndex[i] = upper_bound(intervals.begin(), intervals.end(), 
                make_tuple(r, INT_MAX, INT_MAX)) - intervals.begin();
        }
        dp.resize(n, vector<P>(5, {-1, {}}));
        return solve(0, 4).second;
    }
};