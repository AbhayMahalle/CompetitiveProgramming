class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(char c : word){
            freq[c-'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int cur = 1;
        int key = 8;
        int res = 0;
        for(int f : freq){
            res += (cur*f);
            key--;
            if(key==0){
                key = 8;
                cur++;
            }
        }
        return res;
    }
};