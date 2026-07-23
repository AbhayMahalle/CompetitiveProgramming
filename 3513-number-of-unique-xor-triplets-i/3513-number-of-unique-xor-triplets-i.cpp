class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        int maxi = n;
        for(int i=n; i>=1; i--){
            maxi = max(maxi, i^n);
        }
        return maxi+1;
    }
};