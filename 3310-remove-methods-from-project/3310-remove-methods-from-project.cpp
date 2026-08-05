class Solution {
public:
    int check = 0;
    void dfs(int node, int k, vector<int> &visited, vector<vector<int>>& edges){
        if(visited[node]==2) check = 1;
        visited[node] = 1;
        for(auto &e: edges[node]){
            if(visited[e]!=1){
                dfs(e, k, visited, edges);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> visited(n, 0);
        vector<vector<int>> edges(n);
        for(auto v : invocations){
            edges[v[0]].push_back(v[1]);
        }
        dfs(k, k, visited, edges);
        for(int i=0; i<n; i++){
            if(visited[i]==1) visited[i] = 2;
        }
        for(int i=0; i<n; i++){
            if(visited[i]) continue;
            dfs(i, k, visited, edges);
        }
        vector<int> res;
        for(int i=0; i<n; i++){
            if(visited[i]==1 || check) res.push_back(i);
        }
        return res;
    }
};