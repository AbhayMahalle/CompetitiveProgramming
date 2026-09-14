class Solution {
public:
    using P = pair<int, int>;
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<P, vector<P>, greater<P>> pq;
        int n = events.size();
        int cnt = 0;
        int j = 0;
        int m = 0;
        for(int i=0; i<n; i++){
            m = max(events[i][1], m);
        }
        for(int i=1; i<=m; i++){
            while(j<n && i>=events[j][0]) {
                pq.push({events[j][1], events[j][0]});
                j++;
            }
            while(!pq.empty() && pq.top().first<i) pq.pop();
            if(!pq.empty()){
                pq.pop();
                cnt++;
            }
        }
        return cnt;
    }
};