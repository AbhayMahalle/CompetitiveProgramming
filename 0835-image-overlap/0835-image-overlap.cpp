class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int maxOverlap = 0;
        map<pair<int, int>, int> diff;
        for(int r1=0; r1<n; r1++){
            for(int c1=0; c1<n; c1++){
                if(img1[r1][c1]==0) continue;
                for(int r2=0; r2<n; r2++){
                    for(int c2=0; c2<n; c2++){
                        if(img2[r2][c2]==0) continue;
                        int rDiff = r1-r2;
                        int cDiff = c1-c2;
                        diff[{rDiff, cDiff}] = 1;
                    }
                }
            }
        }
        for(auto &p : diff){
            auto [rDiff, cDiff] = p.first; 
            int overlap = 0;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    int r = i + rDiff;
                    int c = j + cDiff;
                    if(r<0 || c<0 || r>=n || c>=n){
                        continue;
                    }
                    if(img2[i][j]==img1[r][c] && img2[i][j]==1) overlap++;
                }
            }
            maxOverlap = max(maxOverlap, overlap);
        }
        return maxOverlap;
    }
};