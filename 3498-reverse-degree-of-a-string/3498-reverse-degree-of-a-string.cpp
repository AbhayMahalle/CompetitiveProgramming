class Solution {
public:
    int reverseDegree(string s) {
        int revDegree = 0, n = s.size();
        for(int i=0; i<n; i++){
            revDegree += (i+1) * (27-(s[i]-'a'+1));
        }
        return revDegree;
    }
};