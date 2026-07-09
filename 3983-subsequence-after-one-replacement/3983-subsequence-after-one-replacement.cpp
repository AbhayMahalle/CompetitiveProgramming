class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        int a = 0, b = 0;
        for(int i = 0; i<n ;i++){
            if(b<m && s[b]==t[i]){
                b++;
            }
            if(a<m){
                if(s[a]==t[i]){
                    a++;
                }
                else b = max(b, a+1);
            }
        }
        return (a==m) || (b==m);
    }
};