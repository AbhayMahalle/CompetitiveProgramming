class Solution {
public:
    bool dfs(int i, vector<int> &vis, vector<int>& pathVis, vector<vector<int>>& graph) {
        vis[i] = 1;
        pathVis[i] = 1;
        for(auto v : graph[i]){
            if(!vis[v]){
                if(dfs(v, vis, pathVis, graph)) return true;
            }
            else if(pathVis[v]){
                return true;
            }
        }
        pathVis[i] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> safe(n, false);
        int i = 0;
        for(auto &v : graph){
            if(v.empty()){
                safe[i] = true;
            }
            i++;
        }
        vector<int> res;
        for(int i=0; i<n; i++){
            vector<int> vis(n, false);
            vector<int> pathVis(n, false);
            if(!dfs(i, vis, pathVis, graph)) res.push_back(i);
        }
        return res;
    }
};