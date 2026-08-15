class Solution {
public:
    int findNthDigit(int n) {
        if(n<=9) return n;
        n -= 9;
        long long st = 1;
        while(true){
            long long d = to_string(10LL*st).size();
            long long total = 9LL*st*10*d;
            if(n>total){
                n -= total;
                st *= 10;
                continue;
            }
            long long dig = st * 10 + (n-1)/d;
            long long pos = (n-1)%d;
            string num = to_string(dig);
            return num[pos]-'0';
        }
        return -1;
    }
};