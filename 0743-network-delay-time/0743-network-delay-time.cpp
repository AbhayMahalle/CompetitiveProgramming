class Solution {
public:
    vector<int> solve(int n, int k, vector<vector<int>>& edge){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n+1, 1e9);
        dist[0] = 0;
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            int dis = t.first;
            int node = t.second;
            for(auto &e : edge){
                int u = e[0];
                int v = e[1];
                int w = e[2];
                if(u==node && dis + w < dist[v]){
                    dist[v] = dis + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist = solve(n, k, times);
        int delayTime = *max_element(dist.begin(), dist.end());
        return delayTime==1e9 ? -1 : delayTime;
    }
};