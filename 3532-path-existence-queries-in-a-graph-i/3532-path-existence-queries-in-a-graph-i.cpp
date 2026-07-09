class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> mark(n, 0);
        int cur = 0;
        for(int i=1; i<n; i++){
            if(abs(nums[i]-nums[i-1])>maxDiff){
                cur++;
            }
            mark[i] = cur;
        }
        vector<bool> res;
        for(auto &q : queries){
            int l = q[0];
            int r = q[1];
            if(mark[l]==mark[r]) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};