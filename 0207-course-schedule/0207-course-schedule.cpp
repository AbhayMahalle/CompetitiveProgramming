class Solution {
public:
    bool dfs(int i, vector<int>& visited, vector<int>& pathVis,  unordered_map<int, vector<int>> &mp) {
        visited[i] = 1;
        pathVis[i] = 1;
        for(auto v : mp[i]){
            if(!visited[v]){
                if(dfs(v, visited, pathVis, mp)) return true;
            }
            else if(pathVis[v]){
                return true;
            }
        }
        pathVis[i] = 0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        for(auto &p : prerequisites){
            mp[p[1]].push_back(p[0]);
        }
        vector<int> visited(n, 0);
        vector<int> pathVis(n, 0);
        for(int i=0; i<n; i++){
            if(dfs(i, visited, pathVis, mp)){
                return false;
            }
        }
        return true;
    }
};