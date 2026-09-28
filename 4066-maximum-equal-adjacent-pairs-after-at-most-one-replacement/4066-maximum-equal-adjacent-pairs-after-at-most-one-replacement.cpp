class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        int base = 0;
        for(int i=0; i<n-1; i++){
            if(nums[i]==nums[i+1]){
                base++;
            }
        }
        int best = 0;
        map<pair<int, int>, int> freq;
        for(int i=0; i<n-1; i++){
            if(nums[i]==nums[i+1]) continue;
            long long a = nums[i];
            long long b = nums[i+1];
            if(a>b) swap(a, b);
            best = max(best, ++freq[{a, b}]);
        }
        return base + best;
    }
};