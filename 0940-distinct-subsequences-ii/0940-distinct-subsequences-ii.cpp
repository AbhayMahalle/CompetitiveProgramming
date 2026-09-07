class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        int MOD = 1e9+7;
        vector<int> countEndWith(26, 0);
        int sum = 0;
        for(int i=0; i<n; i++){
           int idx = s[i] - 'a';
           int cur = (1 + sum - countEndWith[idx] + MOD) % MOD;
           sum = (sum + cur) % MOD;
           countEndWith[idx] = (countEndWith[idx] + cur) % MOD;
        }
        return sum;
    }
};