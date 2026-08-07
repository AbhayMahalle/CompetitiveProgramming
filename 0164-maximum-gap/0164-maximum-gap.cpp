class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int diff = 0;
        int n = nums.size();
        for(int i=1; i<n; i++){
            diff = max(diff, nums[i]-nums[i-1]);
        }
        return diff;
    }
};