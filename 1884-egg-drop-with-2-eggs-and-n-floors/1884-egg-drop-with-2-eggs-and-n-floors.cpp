class Solution {
public:
    int twoEggDrop(int n) {
        int l = 0, r = n, ans = n;
        while(l<=r){
            int mid = (l+r)/2;
            long long sum = 1LL * (mid) * (mid+1)/2;
            if(sum>=n){
                ans = mid;
                r = mid-1;
            }
            else l= mid+1;
        }
        return ans;
    }
};