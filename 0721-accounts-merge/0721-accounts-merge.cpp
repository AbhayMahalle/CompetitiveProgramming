class DisjointSet {
    vector<int> size, parent;
    public:
    DisjointSet(int n){
        size.resize(n, 1);
        parent.resize(n, 0);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int sz(int node){
        return size[node];
    }
    int Uparent(int node){
        if(parent[node]==node) return node;
        return parent[node] = Uparent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ult_u = Uparent(u);
        int ult_v = Uparent(v);
        if(ult_v==ult_u) return;
        if(size[ult_u]<size[ult_v]){
            size[ult_v] += size[ult_u];
            parent[ult_u] = ult_v;
        }
        else{
            size[ult_u] += size[ult_v];
            parent[ult_v] = ult_u;
        }
    }

};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mp;
        int n = accounts.size();
        DisjointSet *ds = new DisjointSet(n);
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                if(mp.find(accounts[i][j])!=mp.end()){
                    ds->unionBySize(mp[accounts[i][j]], i);
                }
                else mp[accounts[i][j]] = i;
            }
        }
        vector<vector<string>> res(n);
        for(int i=0; i<n; i++){
            int idx = ds->Uparent(i);
            if(idx==i) res[i].push_back(accounts[i][0]);
        }
        for(int i=0; i<n; i++){
            int idx = ds->Uparent(i);
            for(int j=1; j<accounts[i].size(); j++){
                res[idx].push_back(accounts[i][j]);
            }
        }
        erase_if(res, [](const vector<string> &v){
            return v.empty();
        });
        for(auto &vec : res) {
            sort(vec.begin()+1, vec.end());
            vec.erase(unique(vec.begin(), vec.end()), vec.end());
        }
        return res;
    }
};