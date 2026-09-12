class Solution {
public:
    using P = pair<long long, vector<int>>;

    map<tuple<int, int, int>, int> originalIndex;
    vector<tuple<int, int, int>> intervals;
    vector<int> nxtIndex;
    vector<vector<P>> dp;

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
        dp.resize(n, vector<P>(5, {0, {}}));
        for(int i=n-1; i>=0; i--){
            for(int k=1; k<=4; k++){
                P skip = {0, {}};
                if(i+1<n) skip = dp[i+1][k];
                auto &[l, r, w] = intervals[i];
                int nxt = nxtIndex[i];
                P take = {0, {}};
                if(nxt<n) take = dp[nxt][k-1];
                take.second.push_back(originalIndex[intervals[i]]);
                sort(take.second.begin(), take.second.end());
                take.first += w;
                if(take.first>skip.first){
                    dp[i][k] = take;
                }
                else if(skip.first>take.first){
                    dp[i][k] = skip;
                }
                else dp[i][k] = min(take, skip);
            }
        }
        return dp[0][4].second;
    }
};