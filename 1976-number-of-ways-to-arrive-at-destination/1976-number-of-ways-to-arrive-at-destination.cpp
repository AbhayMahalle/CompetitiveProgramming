class Solution {
public:
    const int MOD = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> edges;
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int time = road[2];

            edges[u].push_back({v, time});
            edges[v].push_back({u, time});
        }
        vector<long long> dist(n, 1e12);
        vector<long long> ways(n, 0);
        priority_queue<pair<long long, long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        ways[0] = 1;
        dist[0] = 0;
        pq.push({0, 0});
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            int u = t.second;
            long long time = t.first;
            for(auto &p : edges[u]){
                int v = p.first;
                long long nt = p.second;
                if(time+nt==dist[v]){
                    ways[v] = (ways[v]+ways[u])%MOD;
                }
                if(time+nt < dist[v]){
                    dist[v] = time + nt;
                    pq.push({dist[v], v});;
                    ways[v] = ways[u];
                }

            }
        }
        return ways[n-1];
    }
};