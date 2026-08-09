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
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<long long>> leftSum, rightSum;
        long long total = accumulate(nums.begin(), nums.end(), 0);
        find(0, n/2, 0, 0, nums, leftSum);
        find(n/2, n, 0, 0, nums, rightSum);
        for(auto &p : rightSum){
            sort(p.second.begin(), p.second.end());
        }
        for(int i=0; i<=n/2; i++){
            for(long long left : leftSum[i]){
                for(int j=0; j<=n/2; j++){
                    vector<long long> &rightVals = rightSum[j];
                    int s = rightVals.size();
                    int k = i + j;
                    if(k==0 || k==n || (total*k)%n) continue;
                    int target = (total*k)/n - left;
                    auto idx = lower_bound(rightVals.begin(), rightVals.end(), target) - rightVals.begin();
                    if(idx < s &&  rightVals[idx]==target) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};