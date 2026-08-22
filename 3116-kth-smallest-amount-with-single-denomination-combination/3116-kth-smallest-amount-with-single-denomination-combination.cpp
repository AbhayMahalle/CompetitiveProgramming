class Solution {
public:
    long long lcm(long long a, long long b){
        return a * b / gcd(a, b);
    }
    long long count(long long mid, vector<int>& coins){
        int n = coins.size();
        long long cnt = 0;
        for(int mask=1; mask<(1<<n); mask++){
            long long l = 0;
            int bits = 0;
            for(int i=0; i<n; i++){
                if(mask & 1<<i){
                    bits++;
                    if(l==0) l = coins[i];
                    else l = lcm(l, coins[i]);
                    if(l>mid) break;
                }
            }
            long long left = mid / l;
            if(bits%2){
                cnt += left;
            }
            else cnt -= left;
        }
        return cnt;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high = *min_element(coins.begin(), coins.end());
        high *=  k * 1LL;
        long long res = high;
        while(low<=high){
            long long mid = low + (high - low) / 2;
            if(count(mid, coins)>=k){
                res = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return res;
    }
};