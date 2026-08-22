class Solution {
public:
    long long solve(int mask, int last, int start, vector<vector<int>>& req, vector<vector<long long>> &minTimeMemo) {
        int prevMask = mask ^ (1<<last);
        if(prevMask==0){
            long long time = max(abs(start-req[last][1]), req[last][0]);
            return minTimeMemo[mask][last] = time;
        }
        if(minTimeMemo[mask][last] != -1) return minTimeMemo[mask][last];
        long long time = LLONG_MAX;
        for(int i=0; i<req.size(); i++){
            if(!(prevMask & (1<<i))) continue;
            long long travel = abs(req[last][1]-req[i][1]);
            travel += solve(prevMask, i, start, req, minTimeMemo);
            long long totalTime = max(travel, (long long)req[last][0]);
            time = min(time, totalTime);
        }
        return minTimeMemo[mask][last] = time;
    }
    long long elevatorRequests(int n, int start, vector<vector<int>>& req) {
        int m = req.size();
        int fullfill = (1<<m) - 1;
        long long minTime = LLONG_MAX;
        vector<vector<long long>> minTimeMemo(1<<m, vector<long long>(m, -1));
        for(int i=0; i<m; i++){
            minTime = min(minTime, solve(fullfill, i, start, req, minTimeMemo));
        }
        return minTime;
    }
};