class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        int maxi = n;
        int cur = 1;
        while(cur<n){
            cur *= 2;
        }
        if(cur==n) return cur*2;
        return cur;
    }
};