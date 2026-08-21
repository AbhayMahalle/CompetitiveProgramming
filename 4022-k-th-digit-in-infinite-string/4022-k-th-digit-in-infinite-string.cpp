class Solution {
public:
    int kthDigit(long long k) {
        long long d = 1;
        long long st = 1;
        long long total = 9;
        while(k>total){
            k -= total;
            d++;
            st *= 10;
            total = 9LL * d * st;
        }
        if(d==1) return k;
        st = st/10;
        long long blockSize = 10 * d;
        long long blockIndex = (k-1) / blockSize;
        long long b = st + blockIndex;
        long long pos = (k-1) % blockSize;
        long long idx = pos / d;
        long long digit = pos % d;
        long long number;
        if(b%2==0){
            number = 10 * b + idx;
        }
        else {
            number = 10 * b + 9 - idx;
        }
        return to_string(number)[digit]-'0';
    }
};