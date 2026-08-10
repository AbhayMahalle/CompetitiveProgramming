class Solution {
public:
    void find(int i, int n, int cnt, long long curSum, vector<int>& nums, unordered_map<int, vector<long long>> &sum){
        if(i>=n){
            sum[cnt].push_back(curSum);
            return;
        }
        find(i+1, n, cnt+1, curSum+nums[i], nums, sum);
        find(i+1, n, cnt, curSum, nums, sum);
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, vector<long long>> leftSum, rightSum;
        find(0, n/2, 0, 0, nums, leftSum);
        find(n/2, n, 0, 0, nums, rightSum);

        for(auto &p : rightSum){
            sort(p.second.begin(), p.second.end());
        }

        long long total = accumulate(nums.begin(), nums.end(), 0);
        int res = abs(total - goal);

        for(int i=0; i<=n/2; i++){
            for(long long &left : leftSum[i]){
                for(int j=0; j<=n/2; j++){
                    long long target = goal - left;
                    auto &right = rightSum[j];
                    int s = right.size();
                    int idx = lower_bound(right.begin(), right.end(), target) - right.begin();
                    if(idx<s){
                        int cur = abs((left+right[idx])-goal);
                        if(cur==0) return 0;
                        res = min(res, cur);
                    }
                    if(idx-1>=0){
                        int cur = abs((left+right[idx-1])-goal);
                        if(cur==0) return 0;
                        res = min(res, cur);
                    }
                }
            }
        }
        return res;

    }
};