class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = 0, high = n*n;
        int res = 0;
        while(low<=high){
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            int mid = low + (high-low)/2;
            visited[0][0] = true;
            queue<pair<int, int>> q;
            if(grid[0][0]<=mid) q.push({0, 0});
            bool check = false;
            while(!q.empty()){
                int s = q.size();
                while(s--){
                    auto p = q.front();
                    q.pop();
                    int i = p.first, j = p.second;
                    if(i==n-1 && j==n-1) {
                        check = true;
                        break;
                    }
                    if(i-1>=0 && grid[i-1][j]<=mid && !visited[i-1][j]){
                        visited[i-1][j] = true;
                        q.push({i-1, j});
                    }
                    if(j-1>=0 && grid[i][j-1]<=mid && !visited[i][j-1]){
                        visited[i][j-1] = true;
                        q.push({i, j-1});
                    }
                    if(i+1<n && grid[i+1][j]<=mid && !visited[i+1][j]){
                        visited[i+1][j] = true;
                        q.push({i+1, j});
                    }
                    if(j+1<n && grid[i][j+1]<=mid && !visited[i][j+1]){
                        visited[i][j+1] = true;
                        q.push({i, j+1});
                    }
                }
                if(check) break;
            }
            if(check){
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res;
    }
};