class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<=n-k; i++){
            unordered_map<int, int> temp;
            for(int j=i; j<i+k; j++){
                temp[nums[j]]++;
            }
            for(auto &p : temp){
                mp[p.first]++;
            }
        }
        int res = -1;
        for(auto &p : mp){
            if(p.second==1 && res<p.first){
                res = p.first;
            }
        }
        return res;
    }
};