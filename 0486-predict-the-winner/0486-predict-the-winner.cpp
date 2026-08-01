class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(int i, int j, int turn, int p1, int p2, vector<int>&nums){
        if(i==j){
            if(!turn){
                p1 += nums[i];
            }
            else {
                p2 += nums[i];
            }
            dp[i][j][turn] = p1-p2;
            return p1-p2;
        }
        if(!turn){
            dp[i][j][turn] = max(solve(i+1, j, !turn, p1+nums[i], p2, nums), solve(i, j-1, !turn, p1+nums[j], p2, nums));
        }
        else {
            dp[i][j][turn] = min(solve(i+1, j, !turn, p1, p2+nums[i], nums), solve(i, j-1, !turn, p1, p2+nums[j], nums));
        }
        return dp[i][j][turn];
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, vector<vector<int>>(n, vector<int>(2, -1)));
        int res = solve(0, n-1, 0, 0, 0, nums);
        return res>=0;
    }
};