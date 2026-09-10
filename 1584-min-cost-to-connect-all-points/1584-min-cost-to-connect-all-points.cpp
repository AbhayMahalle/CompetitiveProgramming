class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> edges(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                int wt = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                edges[i].push_back({j, wt});
            }
        }
        vector<int> vis(n, 0);
        priority_queue<tuple<int, int, int>, 
            vector<tuple<int, int, int>>, 
            greater<tuple<int, int, int>>> pq;
        pq.push({0, 0, -1});
        vector<pair<int, int>> res;
        int cost = 0;
        while(!pq.empty()){
            auto [c, node, parent] = pq.top();
            pq.pop();
            if(vis[node]) continue;
            vis[node] = 1;
            if(parent!=-1) {
                cost += c;
                res.push_back({parent, node});
            }
            for(auto [v, wt] : edges[node]){
                if(!vis[v]){
                    pq.push({wt, v, node});
                }
            }
        }
        return cost;
    }
};