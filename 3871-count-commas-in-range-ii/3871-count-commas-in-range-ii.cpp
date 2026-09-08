class Solution {
public:
    long long countCommas(long long n) {
        if(n<=999) return 0;
        long long cnt = 0;
        long long start = 1000;
        long long end = 9999;
        int digit = 4;
        while(end<1e15){
            int mul = (digit-1)/3;
            if(n>=start && n<=end){
                cnt += mul*(n-start+1);
                break;
            }
            cnt += 1LL*mul*(end-start+1);
            start = start*10;
            end = end*10+9;
            digit++;
        }
        if(n==1e15) cnt += 5;
        return cnt;
    }
};