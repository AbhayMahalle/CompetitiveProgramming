class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int firstTwo = nums[0] * nums[1];
        int last = nums[n-1] * nums[n-2] * nums[n-3];
        return max({firstTwo*nums[n-1], last, firstTwo*nums[2]});
    }
};