class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        vector<int> duo;
        for(int i=0;i<n; i++){
            for(int j=0; j<n; j++){
                int newNum = nums[i]^nums[j];
                if(!(mp.find(newNum)!=mp.end())){
                    mp[newNum]= 1;
                    duo.push_back(newNum);
                }
            }
        }
        mp.clear();
        for(int i=0; i<duo.size(); i++){
            for(int j=0; j<n; j++){
                int cur = duo[i]^nums[j];
                mp[cur] = 1;
            }
        }
        return mp.size();
    }
};