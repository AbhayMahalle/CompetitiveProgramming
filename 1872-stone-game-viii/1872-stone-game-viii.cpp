class Solution {
public:
    vector<vector<int>> diff;
    int solve(int i, int player, int n, vector<int>& prefixSum){
        if(i>=n){
            // Out of Boundary!
            return 0;
        }
        if(diff[i][player]!=-1) return diff[i][player];
        if(player){
            // Alice is Trying to Maximize the score differece
            int take = prefixSum[i] + solve(i+1, !player, n, prefixSum);
            int notTake = INT_MIN;
            if(i+1<n) notTake = solve(i+1, player, n, prefixSum);
            diff[i][player] = max(take, notTake);
        }
        else {
            // Bob is Trying to Minimize the score differece
            int take = -prefixSum[i] + solve(i+1, !player, n, prefixSum);
            int notTake = INT_MAX;
            if(i+1<n) notTake = solve(i+1, player, n, prefixSum);
            diff[i][player] = min(take, notTake);
        }
        return diff[i][player];
    }
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefixSum = stones;
        // Maintaining the prefixSum bcoz
        // leftMost stones will be converted into 1
        for(int i=1; i<n; i++){
            prefixSum[i] += prefixSum[i-1];
        }
        //Player 1 : Alice
        //Player 0 : Bob
        int player = 1;
        int i = 1;
        //Starting with 1 bcoz in each turn x>1
        diff.resize(n, vector<int>(2, -1));
        return solve(i, player, n, prefixSum);
    }
};