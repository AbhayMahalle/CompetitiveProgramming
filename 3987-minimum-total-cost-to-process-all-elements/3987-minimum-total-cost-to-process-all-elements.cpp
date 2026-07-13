class Solution {
public:
    int MOD = 1e9+7;
    int minimumCost(vector<int>& nums, int k) {
        long long r = k;
        long long cost = 0;
        long long c = 0;
        for(long long n : nums){
            if(r>=n){
                r -= n;
            }
            else {
                long long req = (n/k) - (r/k);
                while((req*k+r<n)) req++;
                r += (req*k);
                c += req;
                r -= n;
            }
        }
        c = c%MOD;
        return (1LL*c*(c+1)/2) % MOD;
    }
};