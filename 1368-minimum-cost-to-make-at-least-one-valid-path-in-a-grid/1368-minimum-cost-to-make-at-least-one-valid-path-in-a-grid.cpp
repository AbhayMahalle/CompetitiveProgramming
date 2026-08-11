class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, 0, 0});
        while(!pq.empty()){
            auto [dis, i, j] = pq.top();
            pq.pop();
            if(grid[i][j]==1){
                if(j+1<n && (dist[i][j]) < dist[i][j+1]){
                    dist[i][j+1]  = dist[i][j];
                    pq.push({dist[i][j+1], i, j+1});
                }
                if(i+1<m && (dist[i][j]+1) < dist[i+1][j]){
                    dist[i+1][j]  = dist[i][j]+1;
                    pq.push({dist[i+1][j], i+1, j});
                }
                if(i-1>=0 && (dist[i][j]+1) < dist[i-1][j]){
                    dist[i-1][j]  = dist[i][j]+1;
                    pq.push({dist[i-1][j], i-1, j});
                }
                if(j-1>=0 && (dist[i][j]+1) < dist[i][j-1]){
                    dist[i][j-1]  = dist[i][j]+1;
                    pq.push({dist[i][j-1], i, j-1});
                }
            }
            else if(grid[i][j]==2){
                if(j+1<n && (dist[i][j]+1) < dist[i][j+1]){
                    dist[i][j+1]  = dist[i][j]+1;
                    pq.push({dist[i][j+1], i, j+1});
                }
                if(i+1<m && (dist[i][j]+1) < dist[i+1][j]){
                    dist[i+1][j]  = dist[i][j]+1;
                    pq.push({dist[i+1][j], i+1, j});
                }
                if(i-1>=0 && (dist[i][j]+1) < dist[i-1][j]){
                    dist[i-1][j]  = dist[i][j] + 1;
                    pq.push({dist[i-1][j], i-1, j});
                }
                if(j-1>=0 && (dist[i][j]) < dist[i][j-1]){
                    dist[i][j-1]  = dist[i][j];
                    pq.push({dist[i][j-1], i, j-1});
                }
            }
            else if(grid[i][j]==3){
                if(j+1<n && (dist[i][j]+1) < dist[i][j+1]){
                    dist[i][j+1]  = dist[i][j]+1;
                    pq.push({dist[i][j+1], i, j+1});
                }
                if(i+1<m && (dist[i][j]) < dist[i+1][j]){
                    dist[i+1][j]  = dist[i][j];
                    pq.push({dist[i+1][j], i+1, j});
                }
                if(i-1>=0 && (dist[i][j]+1) < dist[i-1][j]){
                    dist[i-1][j]  = dist[i][j]+1;
                    pq.push({dist[i-1][j], i-1, j});
                }
                if(j-1>=0 && (dist[i][j]+1) < dist[i][j-1]){
                    dist[i][j-1]  = dist[i][j]+1;
                    pq.push({dist[i][j-1], i, j-1});
                }
            }
            else if(grid[i][j]==4){
                if(j+1<n && (dist[i][j]+1) < dist[i][j+1]){
                    dist[i][j+1]  = dist[i][j]+1;
                    pq.push({dist[i][j+1], i, j+1});
                }
                if(i+1<m && (dist[i][j]+1) < dist[i+1][j]){
                    dist[i+1][j]  = dist[i][j]+1;
                    pq.push({dist[i+1][j], i+1, j});
                }
                if(i-1>=0 && (dist[i][j]) < dist[i-1][j]){
                    dist[i-1][j]  = dist[i][j];
                    pq.push({dist[i-1][j], i-1, j});
                }
                if(j-1>=0 && (dist[i][j]+1) < dist[i][j-1]){
                    dist[i][j-1]  = dist[i][j]+1;
                    pq.push({dist[i][j-1], i, j-1});
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }
        return dist[m-1][n-1];
    }
};