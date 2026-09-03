class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int last, int m, vector<int>&nums, unordered_map<int, vector<int>>& idx){
        if(i>=nums.size()) return 0;
        if(dp[i][last]!=-1) return dp[i][last];
        int res = 0;
        if(idx.find(nums[i])!=idx.end()){
            for(auto &j : idx[nums[i]]){
                if(j>last || last==m){
                    res = max(res, 1+solve(i+1, j,m, nums, idx));
                    break;
                }
            }
        }
        res = max(res, solve(i+1, last,m, nums, idx));
        return dp[i][last] = res;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int, vector<int>> idx;
        dp.resize(n, vector<int>(m+1, -1));
        for(int i=0; i<m; i++){
            idx[nums2[i]].push_back(i);
        }
        return solve(0, m, m, nums1, idx);
    }
};