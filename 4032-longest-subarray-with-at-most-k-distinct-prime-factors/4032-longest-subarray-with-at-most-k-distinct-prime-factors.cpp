class Solution {
public:
    // Generate all prime numbers up to n
    vector<int> getPrimes(int n) {
        vector<bool> isPrime(n + 1, true);
        vector<int> primes;

        isPrime[0] = false;
        if (n >= 1) isPrime[1] = false;

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primes.push_back(i);

                // Mark all multiples of i as composite
                if (1LL * i * i <= n) {
                    for (int j = i * i; j <= n; j += i) {
                        isPrime[j] = false;
                    }
                }
            }
        }

        return primes;
    }

    // Return distinct prime factors of n
    vector<int> fact(int n, vector<int>& primes) {
        vector<int> factors;

        for (int p : primes) {
            // No need to continue after sqrt(n)
            if (1LL * p * p > n)
                break;

            if (n % p == 0) {
                // Add the prime only once
                factors.push_back(p);

                // Remove all occurrences of p
                while (n % p == 0) {
                    n /= p;
                }
            }
        }

        // If something greater than 1 remains, it's prime
        if (n > 1) {
            factors.push_back(n);
        }

        return factors;
    }

    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        // Find the largest number
        int maxi = *max_element(nums.begin(), nums.end());

        // Sieve only up to sqrt(maxi) — that's the largest divisor fact()
        // ever tests, since trial division breaks at p*p > n and n <= maxi.
        // The "+2" guards against sqrt()'s floating-point rounding.
        int sieveLimit = (int) sqrt((double) maxi) + 2;
        vector<int> primes = getPrimes(sieveLimit);

        // Store distinct prime factors of every number
        vector<vector<int>> factors(n);
        for (int i = 0; i < n; i++) {
            factors[i] = fact(nums[i], primes);
        }

        // Tracking Frequency
        unordered_map<int, int> freq;

        int distinct = 0;
        int left = 0;
        int res = 0;

        // Expand the window using right
        for (int right = 0; right < n; right++) {

            // Add nums[right]
            for (int p : factors[right]) {
                if (freq[p] == 0) {
                    distinct++;   // new prime introduced to the window
                }
                freq[p]++;
            }

            // Shrink the window while invalid
            while (distinct > k) {
                for (int p : factors[left]) {
                    freq[p]--;
                    if (freq[p] == 0) {
                        distinct--;   // prime completely gone from the window
                    }
                }
                left++;
            }

            // Current window is valid
            res = max(res, right - left + 1);
        }

        return res;
    }
};