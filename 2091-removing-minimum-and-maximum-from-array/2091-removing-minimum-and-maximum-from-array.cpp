class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = 0;
        int maxi = 0;
        for(int i=0; i<n; i++){
            if(nums[mini]>nums[i]){
                mini = i;
            }
            if(nums[maxi]<nums[i]){
                maxi = i;
            }
        }
        cout << mini << " " << maxi << endl;
        int front = max(mini, maxi)+1;
        int back = n - min(mini, maxi);
        int frontBack = (min(mini, maxi)+1) + (n-max(mini, maxi));
        int minDeletion = min({front, back, frontBack});
        return minDeletion;
    }
};