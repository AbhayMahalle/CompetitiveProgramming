class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<pair<int, int>> maxi(n, {-1, -1});
        for(int i=0; i<n; i++){
            maxi[i] = {a[i]+b[i], i};
        }
        sort(maxi.begin(), maxi.end());
        reverse(maxi.begin(), maxi.end());
        int alice = 0, bob = 0;
        for(int i=0; i<n; i++){
            if(i%2) bob += b[maxi[i].second];
            else alice += a[maxi[i].second];
        }
        if(alice>bob) return 1;
        else if(bob>alice) return -1;
        return 0;
    }
};