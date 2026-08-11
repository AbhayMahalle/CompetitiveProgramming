class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int num : nums) mp[num]++;
        int pre = 0;
        for(int i=0; i<n; i++){
            pre = 0;
            while(i+1<n && nums[i]+1==nums[i+1]){
                pre += nums[i];
                i++;
            }
            pre += nums[i];
            break;
        }
        while(mp.find(pre)!=mp.end()){
            pre++;
        }
        return pre;
    }
};