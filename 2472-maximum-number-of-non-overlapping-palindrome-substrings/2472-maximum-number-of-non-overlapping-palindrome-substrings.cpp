class Solution {
public:
    vector<int> dp;
    int solve(int i, int n, vector<pair<int, int>>& ranges){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        auto p = ranges[i];
        int l = p.first, r = p.second;
        int take = 0;
        if(l!=-1){
            take = 1 + solve(r+1, n, ranges);
        }
        int notTake = solve(i+1, n, ranges);
        return dp[i] = max(take, notTake);
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if(k==1) return n;
        vector<pair<int, int>> ranges(n, {-1, -1});
        vector<bool> find(n, false);
        for(int i=0; i<n; i++){
            int l = i-1, r = i+1;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    if(r-l+1>=k){
                        if(find[l]) break;
                        ranges[l] = {l, r};
                        find[l] = true;
                        break;
                    }
                    l--;
                    r++;
                }
                else break;
            }
            l = i, r = i+1;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    if(r-l+1>=k){
                        if(find[l]) break;
                        ranges[l] = {l, r};
                        find[l] = true;
                        break;
                    }
                    l--;
                    r++;
                }
                else break;
            }
        }
        dp.resize(n, -1);
        return solve(0, n, ranges);
        
    }
};