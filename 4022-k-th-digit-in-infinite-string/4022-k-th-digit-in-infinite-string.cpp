class Solution {
public:
    int kthDigit(long long k) {
        if(k<=9) return k;
        k = k - 9;
        long long st = 1;
        while(true){
            long long d = to_string(1LL*10*st).size();
            long long total = 1LL * 9 * st * 10 * d;
            if(k>total){
                k -= total;
                st *= 10;
                continue;
            }
            long long b = (k-1)/(10*d) + st;
            long long pos = (k-1)%(10*d);
            long long idx = pos/d;
            long long dig = pos%d;
            long long num;
            if(b%2){
                num = 10*b + 9 - idx;
            }
            else {
                num = 10*b + idx;
            }
            string s = to_string(num);
            return s[dig] - '0';
        }
        return -1;
    }
};