class Solution {
public:
    vector<int> getPrimes(int n){
        vector<bool> isPrime(n+1, true);
        vector<int> primes;
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i=2; i<=n; i++){
            if(isPrime[i]){
                primes.push_back(i);
                if(1LL*i*i<=n){
                    for(int j=i*i; j<=n; j+=i){
                        isPrime[j] = false;
                    }
                }
            }
        }
        return primes;
    }
    vector<int> fact(int n, vector<int> &primes){
        vector<int> factors;
        for(int p : primes){
            if(1LL*p*p>n) break;
            if(n%p==0){
                factors.push_back(p); 
                while(n%p==0){
                    n /= p;
                }
            }
        }
        if(n>1) factors.push_back(n);
        return factors;
    }
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> primes = getPrimes(sqrt(maxi));
        vector<vector<int>> factors(n);
        for(int i=0; i<n; i++){
            factors[i] = fact(nums[i], primes);
        }
        vector<int> freq(maxi+1, 0);
        int distinct = 0;
        int left = 0;
        int res = 0;
        int right = 0;
        while(right<n){
            for(int p : factors[right]){
                if(freq[p]==0){
                    distinct++;
                }
                freq[p]++;
            }
            while(distinct>k){
                for(int p : factors[left]){
                    freq[p]--;
                    if(freq[p]==0){
                        distinct--;
                    }
                }
                left++;
            }
            res = max(res, right-left+1);
            right++;
        }
        return res;
    }
};