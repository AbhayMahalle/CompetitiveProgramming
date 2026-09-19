class Solution {
public:
    vector<vector<int>> res;
    vector<int> tin, low, vis;
    int timer = 0;
    void dfs(int node, int parent, vector<vector<int>>& con) {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        for (auto v : con[node]) {
            if (v == parent) continue;
            if (vis[v]) {
                low[node] = min(low[node], tin[v]);
            }
            else {
                dfs(v, node, con);
                low[node] = min(low[node], low[v]);
                if (low[v] > tin[node]) {
                    res.push_back({node, v});
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> con(n);
        for (auto &e : connections) {
            con[e[0]].push_back(e[1]);
            con[e[1]].push_back(e[0]);
        }
        tin.resize(n, -1);
        low.resize(n, -1);
        vis.resize(n, 0);
        dfs(0, -1, con);
        return res;
    }
};