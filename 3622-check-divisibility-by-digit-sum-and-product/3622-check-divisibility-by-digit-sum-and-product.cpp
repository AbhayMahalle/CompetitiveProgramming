class Solution {
public:
    bool checkDivisibility(int n) {
        int product = 1;
        int sum = 0;
        int fixN = n;
        while(n!=0){
            sum += n%10;
            product *= (n%10);
            n /= 10;
        }
        return fixN%(product+sum)==0;
    }
};