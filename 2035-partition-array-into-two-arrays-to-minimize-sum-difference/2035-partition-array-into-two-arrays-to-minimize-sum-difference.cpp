class Solution {
public:
    void find(int i, int n, int cnt, long long curSum, vector<int>&nums, unordered_map<int, vector<long long>>& sum){
        if(i>=n){
            sum[cnt].push_back(curSum);
            return;
        }
        find(i+1, n, cnt+1, curSum+nums[i], nums, sum);
        find(i+1, n, cnt, curSum, nums, sum);
    }
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<long long>> leftSum, rightSum;
        long long total = accumulate(nums.begin(), nums.end(), 0);
        find(0, n/2, 0, 0, nums, leftSum);
        find(n/2, n, 0, 0, nums, rightSum);
        int res = INT_MAX;
        for(auto &p : rightSum){
            sort(p.second.begin(), p.second.end());
        }
        for(int i=0; i<=n/2; i++){
            for(long long left : leftSum[i]){
                vector<long long> &rightVals = rightSum[n/2-i];
                int s = rightVals.size();
                int target = (total-2*left) / 2;
                auto idx = lower_bound(rightVals.begin(), rightVals.end(), target) - rightVals.begin();
                int cur;
                if(idx < s){
                    cur = abs(1LL * 2 * (1LL * left + 1LL * rightVals[idx]) - total);
                    res = min(res, cur);
                }
                if(idx - 1 >= 0 && s > 0){
                    cur = abs(1LL * 2 * (left + rightVals[idx-1]) - total);
                    res = min(res, cur);
                }
            }
        }
        return res;
    }
};