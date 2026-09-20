class Solution {
public:
    int reverseDegree(string s) {
        int revDegree = 0, n = s.size();
        for(int i=0; i<n; i++){
            revDegree += (i+1) * (26-(s[i]-'a'));
        }
        return revDegree;
    }
};