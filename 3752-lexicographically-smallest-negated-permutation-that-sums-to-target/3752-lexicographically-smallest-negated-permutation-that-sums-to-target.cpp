class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long maxSum = 1LL * n * (n+1) /2;
        long long minSum = -maxSum;
        long long rem = maxSum;
        if(target<minSum || target>maxSum) return {};
        if(n==1 && target==0) return {};
        vector<int> permutation;
        for(int i=1; i<=n; i++) permutation.push_back(i);
        long long cur = 0;
        for(int i=n-1; i>=0; i--){
            if(rem-2*permutation[i]>=target){
                rem -= 2*permutation[i];
                permutation[i] = -permutation[i];
                if(rem==target) {
                    break;
                }
            }
        }
        if(rem!=target) return {};
        sort(permutation.begin(), permutation.end());
        return permutation;
    }
};