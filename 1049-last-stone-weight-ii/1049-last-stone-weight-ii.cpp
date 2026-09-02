class Solution {
public:
    void solve(int i, int n, int cur, vector<int>& stones, vector<int>& vec){
        if(i==n){
            vec.push_back(cur);
            return;
        }
        solve(i+1, n, cur+stones[i], stones, vec);
        solve(i+1, n, cur-stones[i], stones, vec);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        vector<int> left;
        vector<int> right;
        solve(0, n/2, 0, stones, left);
        solve(n/2, n, 0, stones, right);
        int res = INT_MAX;
        sort(right.begin(), right.end());
        for(int i=0; i<left.size(); i++){
            int l = 0, r = right.size()-1;
            while(l<=r){
                int mid = l + (r-l)/2;
                if(left[i]+right[mid]>=0) res = min(res, left[i]+right[mid]);
                if(left[i]+right[mid]==0){
                    return 0;
                }
                else if(left[i]+right[mid]>0){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
        }
        return res;
    }
};