class Solution {
public:
    bool dfs(int i, vector<int>& visited, vector<int>&pathVis, vector<int>&seq, unordered_map<int, vector<int>>& mp){
        visited[i] = 1;
        pathVis[i] = 1;
        for(auto v : mp[i]){
            if(!visited[v]){
                if(dfs(v, visited, pathVis, seq, mp)) {
                    return true;
                }
            }
            else if(pathVis[v]){
                return true;
            }
        }
        pathVis[i] = 0;
        seq.push_back(i);
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        unordered_map<int, vector<int>> mp;
        for(auto&p : pre){
            mp[p[1]].push_back(p[0]);
        }
        vector<int> visited(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> seq;
        for(int i=0; i<n; i++){
            if(!visited[i] && !dfs(i, visited, pathVis, seq, mp) && seq.size()==n){
                reverse(seq.begin(), seq.end());
                return seq;
            }
        }
        return {};
    }
};