class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        priority_queue<
                        tuple<int, int, int>, 
                        vector<tuple<int, int, int>>, 
                        greater<tuple<int, int, int>>
                    > pq;
        pq.push({0, 0, src});
        while(!pq.empty()){
            auto [stop, dis, node] = pq.top();
            pq.pop();
            for(auto &f : flights){
                int u = f[0];
                int v = f[1];
                int w = f[2];
                if(u==node && stop<=k && (dis + w) < dist[v]){
                    dist[v]= dis + w;
                    pq.push({stop+1, dist[v], v});
                }
            }
        }
        int cheapest = dist[dst];
        return cheapest == INT_MAX ? -1 : cheapest;
    }
};