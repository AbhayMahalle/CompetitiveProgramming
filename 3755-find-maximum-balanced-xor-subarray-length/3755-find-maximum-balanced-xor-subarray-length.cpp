class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<string, int> mp;
        int prefix = 0, diff = 0;
        int res = 0;
        mp["0.0"] = -1;
        for(int i=0; i<n; i++){
            prefix ^= nums[i];
            if(nums[i]%2) diff++;
            else diff--;
            string key = to_string(prefix);
            key += '.';
            key += to_string(diff);
            if(mp.find(key)!=mp.end()){
                int len = i - mp[key];
                res = max(res, len);
            }
            else mp[key] = i;
        }
        return res;
    }
};