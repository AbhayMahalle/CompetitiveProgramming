class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dist(n, vector<int>(k+1, INT_MAX));
        dist[src][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, 0, src});
        while(!pq.empty()){
            auto [dis, stop, node] = pq.top();
            pq.pop();
            for(auto &f : flights){
                int u = f[0];
                int v = f[1];
                int w = f[2];
                if(u==node && stop<=k && (dis + w) < dist[v][stop]){
                    dist[v][stop] = dis + w;
                    pq.push({dist[v][stop], stop+1, v});
                }
            }
        }
        int cheapest = *min_element(dist[dst].begin(), dist[dst].end());
        return cheapest == INT_MAX ? -1 : cheapest;
    }
};