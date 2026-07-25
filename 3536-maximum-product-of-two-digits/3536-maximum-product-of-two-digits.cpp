class Solution {
public:
    int maxProduct(int n) {
        int a = -1, b = -1;
        while(n){
            int d = n%10;
            n = n/10;
            if(d>=a){
                b = a;
                a = d;
            }
            else if(d>b){
                b = d;
            }
        }
        return a * b;
    }
};