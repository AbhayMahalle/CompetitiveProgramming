class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        k = k % total;
        if(k==0) return grid;
        vector<vector<int>> res = grid;
        int a = m-1, b = n;
        int cnt = 0;
        while(cnt<k){
            b--;
            if(b<0){
                b = n-1;
                a--;
            }
            cnt++;
        }
        int ni = a, nj = b;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                res[i][j] = grid[ni][nj];
                nj++;
                if(nj==n){
                    nj = 0;
                    ni++;
                }
                if(ni>=m){
                    ni = 0, nj = 0;
                }
            }
        }
        
        return res;

    }
};