class DisjointSet {
    unordered_map<char, char> parent;
    public:
    DisjointSet(){
        for(char c='a'; c<='z'; c++){
            parent[c] = c;
        }
    }

    char uparent(char c){
        if(c==parent[c]) return c;
        return parent[c] = uparent(parent[c]);
    }

    void unionSize(char u, char v){
        char ult_u = uparent(u);
        char ult_v = uparent(v);
        if(ult_u==ult_v) return;
        if(ult_u<=ult_v){
            parent[ult_v] = ult_u;
        }
        else {
            parent[ult_u] = ult_v;
        }
    }

};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        DisjointSet *ds = new DisjointSet();
        for(int i=0; i<n; i++){
            ds->unionSize(s1[i], s2[i]);
            ds->unionSize(s2[i], s1[i]);
        } 
        string res;
        for(char c : baseStr){
            res.push_back(ds->uparent(c));
        }
        return res;
    }
};