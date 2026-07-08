class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        queue<int> q;
        unordered_map<int, int> mp;
        int opr = 0;
        for(int n : nums){
            if(mp.count(n)){
               q.push(n);
            }
            else mp[n]++;
        }
        int i = nums[0];
        while(!q.empty()){
            if(mp.count(i)==0 && q.front()<i){
                int f = q.front();
                opr += abs(f-i);
                q.pop();
            }
            i++;
        }
        return opr;
    }
};