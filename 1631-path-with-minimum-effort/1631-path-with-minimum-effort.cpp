class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> absDiff(m, vector<int>(n, 1e9));
        absDiff[0][0] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        while(!q.empty()){
            auto t = q.front();
            int lastDiff = t.first;
            int i = t.second.first;
            int j = t.second.second;
            q.pop();
            for(int k=0; k<4; k++){
                int ni = i + dr[k];
                int nj = j + dc[k];
                if(ni<0 || nj <0 || ni>=m || nj>=n) continue;
                int curDiff = max(abs(heights[i][j]-heights[ni][nj]), lastDiff);
                if(curDiff < absDiff[ni][nj]){
                    absDiff[ni][nj] = curDiff;
                    q.push({curDiff, {ni, nj}});
                }
            }
        }
        return absDiff[m-1][n-1];
    }
};