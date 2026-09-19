class DisjointSet {
    vector<int> size, parent;
    public:
    DisjointSet(int n){
        size.resize(n, 1);
        parent.resize(n, 0);
        for(int i=0; i<n; i++) parent[i] = i;
    }

    int sz(int node) {
        return size[node];
    }

    int uParent(int node){
        if(node==parent[node]) return node;
        return parent[node] = uParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ult_u = uParent(u);
        int ult_v = uParent(v);
        if(ult_u==ult_v) return;
        if(size[ult_u] < size[ult_v]){
            size[ult_v] += size[ult_u];
            parent[ult_u] = ult_v;
        }
        else {
            size[ult_u] += size[ult_v];
            parent[ult_v] = ult_u;
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        DisjointSet *ds = new DisjointSet(m*n);
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0) continue;
                for(int d=0; d<4; d++){
                    int ni = i + dr[d];
                    int nj = j + dc[d];
                    if(ni<0 || ni>=m || nj<0 || nj>=n) continue;
                    if(grid[ni][nj]==0) continue;
                    ds->unionBySize(i*n+j, ni*n+nj);
                }
            }
        }
        int res = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                unordered_map<int, int> ids;
                if(grid[i][j]==0){
                    for(int d=0; d<4; d++){
                        int ni = i + dr[d];
                        int nj = j + dc[d];
                        if(ni<0 || ni>=m || nj<0 || nj>=n) continue;
                        if(grid[ni][nj]==0) continue;
                        ids[ds->uParent(ni*n+nj)]++;
                    }
                    int cur =  1;
                    for(auto [id, f] : ids){
                        cur += ds->sz(id);
                    }
                    res = max(res, cur);
                }
                else res = max(res, ds->sz(i*n+j));
            }
        }
        return res;
    }
};