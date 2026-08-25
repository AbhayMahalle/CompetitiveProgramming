class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        for(int n : nums){
            seen[n] = 1;
        }
        int cur = k;
        while(true){
            if(seen[cur]==0) return cur;
            cur += k;
        }
        return -1;
    }
};