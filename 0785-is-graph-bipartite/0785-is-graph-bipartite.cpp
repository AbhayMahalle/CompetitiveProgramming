class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);
        for(int i=0; i<n; i++){
            if(visited[i]) continue;
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while(!q.empty()){
                int s = q.size();
                while(s--){
                    int cur = q.front();
                    q.pop();
                    for(auto&v : graph[cur]){
                        if(visited[v]==0){
                            q.push(v);
                            if(visited[cur]==1){
                                visited[v] = 2;
                            }
                            else visited[v] = 1;
                        }
                        else if(visited[v]==visited[cur]) return false;
                    }
                }
            }
        }
        return true;
    }
};