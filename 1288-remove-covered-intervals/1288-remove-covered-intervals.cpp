class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for(auto &p : intervals){
            int l = p[0];
            int r = p[1];
            if(res.empty()){
                res.push_back(p);
            }
            else{
                if(res.back()[1]==r){
                    res.back()[0] = min(l, res.back()[0]);
                }
                else if(l<=res.back()[0] && res.back()[1]<=r) {
                    res.back()[0] = l;
                    res.back()[1] = r;
                }
                else if(res.back()[1]<=r || res.back()[1]<=l){
                    res.push_back(p);
                }
            }
        }
        return res.size();
    }
};