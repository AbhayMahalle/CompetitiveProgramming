class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = 0, b = 0;
        for(int n : nums){
            if(n>=a){
                b = a;
                a = n;
            }
            else if(n>b){
                b = n;
            }
        }
        a--;
        b--;
        return a * b;
    }
};