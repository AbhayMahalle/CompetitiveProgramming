class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = 0, even = 0;
        for(int i=1; i<=2*n; i++){
            if(i%2) odd += i;
            else even += i;
        }
        return gcd(even, odd);
    }
};