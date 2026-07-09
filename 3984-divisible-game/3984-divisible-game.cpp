class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end()) + 100;
        vector<bool> primes(maxi+1, true);
        primes[0] = false;
        primes[1] = false;
        for(int i=2; i*i<=maxi; i++){
            if(primes[i]){
                for(int j=i*i; j<=maxi; j+=i){
                    primes[j]  = false;
                }
            }
        }
        long long bestdiff = LLONG_MIN;
        long long bestk = 2;
        long long mod = 1e9+7;
        for(int i=0; i<=maxi; i++){
            if(primes[i]){
                long long k = i;
                vector<int> temp = nums;
                for(auto &n : temp){
                    if(n%k){
                        n = -n;
                    }
                }
                long long maxSum = temp[0], cur = 0;
                for(int n : temp){
                    cur += n;
                    maxSum = max(maxSum, cur);
                    if(cur<0) cur = 0;
                    
                }
                bestdiff = bestdiff % (long long)(1e9+7);
                if(bestdiff<maxSum){
                    bestdiff = maxSum;
                    bestk = k;
                }
                else if(maxSum==bestdiff){
                    bestk = min(k, bestk);
                }
            }
        }
        long long res = (1LL*bestdiff*bestk)%(long long)(1LL*(1e9+7));
        if(res<0) res += mod;
        return res%(long long)(1LL*(1e9+7));
    }
};