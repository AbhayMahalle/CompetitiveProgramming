class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int target=0;
        for(int i:nums) target+=i;
        target-=x;
        if(target==0) return n;
        int left=0,sum=0,ans=0;
        for(int right=0;right<n;right++){
            sum+=nums[right];
            while(left<=right&&sum>target){
                sum-=nums[left];
                left++;
            }
            if(sum==target) ans=max(ans,right-left+1);
        }
        if(ans) return n-ans;
        return -1;
    }
};