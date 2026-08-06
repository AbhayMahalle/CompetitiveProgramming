class Solution {
public:
    int smallestNumber(int n, int t) {
        int cur = n;
        int temp = cur;
        int product = 1;
        while(temp){
            product *= (temp%10);
            temp /= 10;
        }
        while(product%t!=0){
            cur++;
            temp = cur;
            product = 1;
            while(temp){
                product *= (temp%10);
                temp /= 10;
            }
        }

        return cur;
    }
};