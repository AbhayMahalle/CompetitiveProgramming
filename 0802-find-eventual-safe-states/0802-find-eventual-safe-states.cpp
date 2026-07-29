class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> degree(n, 0);
        vector<vector<int>> edges(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<graph[i].size(); j++){
                edges[graph[i][j]].push_back(i);
            }
        }
        for(int i = 0; i<n ;i++){
            for(auto e : edges[i]){
                degree[e]++;
            }
        }
        vector<int> res;
        queue<int> q;
        for(int i=0; i<n; i++){
            cout << degree[i] << " ";
            if(!degree[i]){
                q.push(i);
                res.push_back(i);
            }
        }
        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(auto e : edges[t]){
                degree[e]--;
                if(degree[e]==0){
                    q.push(e);
                    res.push_back(e);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};