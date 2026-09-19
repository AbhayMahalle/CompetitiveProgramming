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
        int dsize(int i){
            return size[i];
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisJointSet *ds = new DisJointSet(n);
        map<pair<int, int>, int> id;
        for(int i=0; i<n; i++){
            int p = stones[i][0];
            int q = stones[i][1];
            id[{p, q}] = i;
        }
        for(int i=0; i<n; i++){
            int r = stones[i][0];
            int c = stones[i][1];
            for(int j=0; j<n; j++){
                if(i==j) continue;
                if(r==stones[j][0]){
                    ds->unionBySize(i, j);
                }
                if(c==stones[j][1]){
                    ds->unionBySize(i, j);
                }
            }
            
        }
        int cnt = 0;
        int size = n;
        for(int i=0; i<n; i++){
            if(i==ds->uParent(i)){
                size = ds->dsize(i);
                if(size!=1) cnt += (size-1);
            } 
        }
        return cnt;
    }
};