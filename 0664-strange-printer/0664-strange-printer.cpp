class Solution {
public:
    int solve(int i, int j, string&s, vector<vector<int>> &dp){
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int answer;
        if(s[i]==s[j] || s[j]==s[j-1]){
            answer = solve(i, j-1, s, dp);
        }
        else if(s[i]==s[i+1]){
            answer = solve(i+1, j, s, dp);
        }
        else {
            answer = solve(i, j-1, s, dp) + 1;
            for(int k=i; k<j; k++){
                if(s[k]==s[j]){
                    answer = min(answer, solve(i, k-1, s, dp) + solve(k, j-1, s, dp));
                }
            }
        }
        return dp[i][j] = answer;
    }
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, s.size()-1, s, dp);
    }
};