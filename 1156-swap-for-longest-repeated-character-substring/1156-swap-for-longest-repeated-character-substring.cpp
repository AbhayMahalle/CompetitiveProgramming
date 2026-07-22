class Solution {
public:
    int maxRepOpt1(string text) {
        unordered_map<char, int> freq;
        for(char c : text){
            freq[c]++;
        }
        int maxLen = 0;
        for(char c='a'; c<='z'; c++){
            int cur = 0;
            int prev = 0;
            int mid = -1;
            for(char t : text){
                if(t==c) cur++;
                else{
                    if(cur==0){
                        prev = 0;
                        mid = -1;
                        continue;
                    }
                    prev = cur;
                    mid = 1;
                    maxLen = max(maxLen, prev);
                    cur = 0;
                }
                if(cur) maxLen = max(maxLen, cur);
                if(mid){
                    int total = prev + cur;
                    if(freq[c]>total){
                        maxLen = max(maxLen, total+1);
                    }
                    maxLen = max(maxLen, total);
                }
            }
        }
        return maxLen;
    }
};