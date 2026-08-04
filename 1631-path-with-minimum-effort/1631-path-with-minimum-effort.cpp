class Solution {
public:
    int m, n;
    bool solve(int i, int j, int mid, vector<vector<int>>& heights, vector<vector<int>>& vis) {
        if(i == m-1 && j == n-1)
            return true;
        vis[i][j] = 1;
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        for(int k=0;k<4;k++){
            int ni = i + dr[k];
            int nj = j + dc[k];
            if(ni>=0 && ni<m && nj>=0 && nj<n && !vis[ni][nj] && abs(heights[i][j]-heights[ni][nj])<=mid){
                if(solve(ni,nj,mid,heights,vis)) return true;
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        int l = 0, r = 1e6;
        int res = r;
        while(l<=r){
            vector<vector<int>> visited(m, vector<int>(n, 0));
            int mid = l + (r-l)/2;
            if(solve(0, 0, mid, heights, visited)){
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return res;
    }

};