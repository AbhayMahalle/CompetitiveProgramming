class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        unordered_map<int, int> freq;
        int len = 0;
        while(j<n){
            freq[nums[j]]++;
            while(i<=j && freq[nums[j]]>k){
                freq[nums[i]]--;
                i++;
            }
            len = max(len, j-i+1);
            j++;
        }
        return len;
    }
};