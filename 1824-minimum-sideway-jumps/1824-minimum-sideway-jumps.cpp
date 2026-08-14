class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int curLane, int n, vector<int>& obstacles){
        if(i>=n) return 0;
        if(dp[i][curLane]!=-1) return dp[i][curLane];
        int curJump = 1e9;
        int a = 1e9, b = 1e9;
        if((curLane)!=(obstacles[i+1]-1)) curJump = min(curJump, solve(i+1, curLane, n, obstacles));
        else {
            if(((curLane+1)%3)!=(obstacles[i+1]-1) && ((curLane+1)%3)!=(obstacles[i]-1)) a = solve(i+1, (curLane+1)%3, n, obstacles);
            if(((curLane+2)%3)!=(obstacles[i+1]-1) && ((curLane+2)%3)!=(obstacles[i]-1)) b = solve(i+1, (curLane+2)%3, n, obstacles);
        }
        curJump = min(curJump, 1+min(a, b));
        return dp[i][curLane] = curJump;
    }
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        obstacles.push_back(0);
        dp.resize(n+1, vector<int>(3, -1));
        return solve(0, 1, n, obstacles);
    }
};