class Solution {
public:
    int solve(int i, int j, string&s, vector<vector<int>> &dp){
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int answer;
        if(s[i]==s[j]){
            answer = solve(i, j-1, s, dp);
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
    int strangePrinter(string ss) {
        string s = "";
        s.push_back(ss[0]);
        for(char c : ss){
            if(c!=s.back()){
                s.push_back(c);
            }
        }
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, s.size()-1, s, dp);
    }
};