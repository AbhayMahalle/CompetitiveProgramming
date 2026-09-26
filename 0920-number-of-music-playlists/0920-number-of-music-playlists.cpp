class Solution {
public:
    int n, goal, k;
    const int MOD = 1e9+7;
    vector<vector<int>> memo;
    int solve(int song, int curGoal){
        if(song==n && curGoal==0) return 1;
        if(song>n || curGoal==0) return 0;
        if(memo[song][curGoal]!=-1) return memo[song][curGoal];
        long long take = 0, skip = 0;
        take = (1LL * (n-song) * solve(song+1, curGoal-1)) % MOD;
        if(song>k){
            skip = (1LL* (song-k) * solve(song, curGoal-1)) % MOD;
        }
        return memo[song][curGoal] = (take + skip) % MOD;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        this->n = n;
        this->goal = goal;
        this->k = k;
        memo.resize(n+1, vector<int>(goal+1, -1));
        return solve(0, goal);
    }
};