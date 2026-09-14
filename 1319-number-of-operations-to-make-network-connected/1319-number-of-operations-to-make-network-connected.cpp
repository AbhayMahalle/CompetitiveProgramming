class DisJointSet {
    vector<int> size, parent;
    public:
        DisJointSet(int n){
            size.resize(n+1, 1);
            parent.resize(n);
            for(int i=0; i<n; i++){
                parent[i] = i;
            }
        }
        
        int uParent(int u){
            if(u==parent[u]) return u;
            return parent[u] = uParent(parent[u]);
        }

        void unionBySize(int u, int v){
            int ulp_u = uParent(u);
            int ulp_v = uParent(v);
            if(ulp_u==ulp_v) return;
            if(size[ulp_v]<size[ulp_u]){
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
            else {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connect) {
        int c = connect.size();
        if(c<n-1) return -1;
        DisJointSet *ds = new DisJointSet(n);
        for(auto &e : connect){
            ds->unionBySize(e[0], e[1]);
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(i==ds->uParent(i)) cnt++;
        }
        return cnt-1;
    }
};