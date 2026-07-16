class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = nums[0];
        int n = nums.size();
        vector<int> prefixGcd(n, 0);
        for(int i=0; i<n ;i++){
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(mx, nums[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int l = 0, r = n-1;
        long long sum = 0;
        while(l<r){
            sum += gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }
        return sum;
    }
};