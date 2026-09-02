class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(int i, int m, int n, vector<string>&strs, vector<pair<int, int>> &freq){
        if(i>=strs.size()) return 0;
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        int one = freq[i].first;
        int zero = freq[i].second;
        int cur = 0;
        cur = max(cur, solve(i+1, m, n, strs, freq));
        if(m-zero>=0 && n-one>=0){
            cur = max(cur, 1+solve(i+1, m-zero, n-one, strs, freq));
        }
        return dp[i][m][n] = cur;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        vector<pair<int, int>> freq;
        for(auto &str : strs){
            int one = 0;
            int zero = 0;
            for(auto &c : str){
                if(c=='0') zero++;
                else one++;
            }
            freq.push_back({one, zero});
        }
        dp.resize(s, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return solve(0, m, n, strs, freq);
    }
};