class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int maxSoFar = INT_MIN;
        int maxAtAns = INT_MIN;

        for (int i = 0; i < n; i++) {
            maxSoFar = max(maxSoFar, nums[i]);
            if (i == ans) {
                maxAtAns = max(maxAtAns, nums[i]);
            }
            if (nums[i] < maxAtAns - k) {
                ans = i + 1;
                maxAtAns = maxSoFar;
            }
        }
        return ans < n ? ans : -1;
    }
};