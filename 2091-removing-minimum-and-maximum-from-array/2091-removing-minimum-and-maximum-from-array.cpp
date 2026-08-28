class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0;
        int maxIdx = 0;
        for(int i=0; i<n; i++){
            if(nums[minIdx]>nums[i]){
                minIdx = i;
            }
            if(nums[maxIdx]<nums[i]){
                maxIdx = i;
            }
        }
        int left = min(minIdx, maxIdx);
        int right = max(minIdx, maxIdx);
        int front = right+1;
        int back = n - left;
        int frontBack = (left+1) + (n-right);
        int minDeletion = min({front, back, frontBack});
        return minDeletion;
    }
};