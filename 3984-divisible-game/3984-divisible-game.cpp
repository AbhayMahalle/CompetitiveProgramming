class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end())+10;
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
                long long maxSum = LLONG_MIN, cur = 0;
                for(int &n : nums){
                    if(n%k){
                        cur -= n;
                    }
                    else cur += n;
                    maxSum = max(maxSum, cur);
                    if(cur<0) cur = 0;
                    
                }
                if(bestdiff<maxSum){
                    bestdiff = maxSum;
                    bestk = k;
                }
                else if(maxSum==bestdiff){
                    bestk = min(k, bestk);
                }
            }
        }
        long long res = (1LL*bestdiff*bestk)%mod;
        if(res<0) res += mod;
        return res%mod;
    }
};