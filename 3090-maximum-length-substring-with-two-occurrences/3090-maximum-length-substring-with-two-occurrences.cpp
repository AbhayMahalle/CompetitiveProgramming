class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int i = 0, j = 0;
        unordered_map<char, int> freq;
        int len = 0;
        while(j<n){
            freq[s[j]]++;
            while(i<=j && freq[s[j]]>2){
                freq[s[i]]--;
                i++;
            }
            len = max(len, j-i+1);
            j++;
        }
        return len;
    }
};