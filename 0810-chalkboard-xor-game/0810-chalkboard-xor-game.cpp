class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int x = 0;
        for(int n : nums) x ^= n;
        return nums.size()%2==0 || x==0;
    }
};