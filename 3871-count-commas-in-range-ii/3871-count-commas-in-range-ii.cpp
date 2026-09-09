class Solution {
public:
    long long countCommas(long long n) {
        if(n <= 999) return 0;

        long long totalCommas = 0;
        long long start = 1000;

        while(start <= n){
            totalCommas += n - start + 1;
            start *= 1000;
        }

        return totalCommas;
    }
};