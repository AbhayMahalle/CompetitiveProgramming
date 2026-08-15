class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXor = 0;
        int n = nums.size();
        for(int num : nums){
            totalXor ^= num;
        }
        if(totalXor!=0) return n;
        for(int num : nums){
            if(totalXor^num!=0) return n-1;
        }
        return 0;
    }
};