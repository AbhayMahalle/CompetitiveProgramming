class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for(auto e: edges){
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int res = -1;
        int minCnt = INT_MAX;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(i!=j && dist[i][j]<=dt){
                    cnt++;
                }
            }
            if(cnt<=minCnt){
                res = i;
            }
            minCnt = min(cnt, minCnt);
            
        }
        return res;
    }
};