class Solution {
public:
    int n;
    map<pair<int,int>, int> dp;

    int solve(vector<int>& stones, int ind, int sum) {
        if (ind == n)
            return abs(sum);

        if (dp.count({ind, sum}))
            return dp[{ind, sum}];

        int add = solve(stones, ind + 1, sum + stones[ind]);
        int sub = solve(stones, ind + 1, sum - stones[ind]);

        return dp[{ind, sum}] = min(add, sub);
    }

    int lastStoneWeightII(vector<int>& stones) {
        n = stones.size();
        return solve(stones, 0, 0);
    }
};