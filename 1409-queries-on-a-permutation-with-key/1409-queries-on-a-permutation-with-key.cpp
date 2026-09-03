class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> per(m, 0);
        for(int i=1; i<=m; i++){
            per[i-1] = i;
        }
        vector<int> res;
        for(auto q : queries){
            int cur = 0;
            int j = -1;
            for(int i=0; i<m; i++){
                if(per[i]==q){
                    res.push_back(i);
                    per.erase(per.begin()+i);
                    break;
                }
            }
            reverse(per.begin(), per.end());
            per.push_back(q);
            reverse(per.begin(), per.end());
        }
        return res;
    }
};